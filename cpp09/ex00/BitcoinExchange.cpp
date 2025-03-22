#include "BitcoinExchange.hpp"

Date::Date(int year, int month, int day)
{
	if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
		throw std::out_of_range("invalid date");
	date = new std::tm;
	date->tm_year = year;
	date->tm_mon = month - 1;
	date->tm_mday = day;
	date->tm_hour = 0;
	date->tm_min = 0;
	date->tm_sec = 0;
	date->tm_isdst = -1;
}

Date::Date(const Date &rhs) : date(new std::tm)
{
	*date = *rhs.date;
}

Date &Date::operator=(const Date &rhs)
{
	if (this != &rhs)
	{
		*date = *rhs.date;
	}
	return *this;
}

Date::~Date()
{
	delete date;
}

int Date::getDay() const
{
	return date->tm_mday;
}

int Date::getMonth() const
{
	return date->tm_mon + 1;
}

int Date::getYear() const
{
	return date->tm_year;
}

time_t Date::getTime() const
{
	return std::mktime(date);
}

bool Date::operator<(const Date &rhs) const
{
	return getTime() < rhs.getTime();
}

bool Date::operator>(const Date &rhs) const
{
	return getTime() > rhs.getTime();
}

bool Date::operator<=(const Date &rhs) const
{
	return getTime() <= rhs.getTime();
}

bool Date::operator>=(const Date &rhs) const
{
	return getTime() >= rhs.getTime();
}

bool Date::operator==(const Date &rhs) const
{
	return getTime() == rhs.getTime();
}

bool Date::operator!=(const Date &rhs) const
{
	return getTime() != rhs.getTime();
}

std::ostream &operator<<(std::ostream &stream, const Date &date)
{
	stream << date.getYear() << '-' << std::setw(2) << std::setfill('0') << date.getMonth() << '-' << std::setw(2) << std::setfill('0') << date.getDay();
	return stream;
}

static Date parseDate(const char *str)
{
	int year, month, day;
	if (sscanf(str, "%d-%d-%d", &year, &month, &day) != 3)
		throw std::logic_error("invalid date format");
	return (Date(year, month, day));
}

std::map<Date, double> *generateData(std::ifstream &data_file)
{
	std::map<Date, double> *data = new std::map<Date, double>;
	std::string line;
	std::getline(data_file, line);
	while (std::getline(data_file, line))
	{
		try
		{
			size_t comma_pos = line.find(',');
			if (comma_pos == std::string::npos)
				throw std::logic_error("missing a comma in a line");
			std::string date_str = line.substr(0, comma_pos);
			std::string value_str = line.substr(comma_pos + 1);
			Date date = parseDate(date_str.c_str());
			double value;
			if (sscanf(value_str.c_str(), "%lf", &value) != 1)
				throw std::logic_error("invalid value");
			(*data)[date] = value;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: data.csv: " << e.what() << std::endl;
		}
	}
	return data;
}

void bitcoinExchange(std::ifstream &input, std::map<Date, double> *data)
{
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		try
		{
			size_t separator_pos = line.find('|');
			if (separator_pos == std::string::npos)
				throw std::logic_error("missing | operator");
			std::string date_str = line.substr(0, separator_pos);
			std::string value_str = line.substr(separator_pos + 1);
			Date date = parseDate(date_str.c_str());
			float value;
			if (sscanf(value_str.c_str(), "%f", &value) != 1)
				throw std::logic_error("invalid value");
			if (value < 0)
				throw std::logic_error("not a positive number");
			if (value > 1000)
				throw std::logic_error("too large a number");
			double scaled_value;
			try
			{
				scaled_value = data->at(date) * value;
			}
			catch (...)
			{
				std::map<Date, double>::iterator it = data->lower_bound(date);
				if (it == data->begin())
					throw std::logic_error("no element before the given date");
				--it;
				scaled_value = it->second * value;
			}
			std::cout << date << " => " << value << " = " << scaled_value << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}