#include "BitcoinExchange.hpp"

#include <map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>

class Date
{
private:
	std::tm *date;
	Date();

public:
	Date(int year, int month, int day) : date(new std::tm)
	{
		if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
			throw std::out_of_range("invalid date");
		date->tm_year = year;
		date->tm_mon = month - 1;
		date->tm_mday = day;
		date->tm_hour = 0;
		date->tm_min = 0;
		date->tm_sec = 0;
		date->tm_isdst = -1;
	}
	Date(const Date &rhs) : date(new std::tm)
	{
		*date = *rhs.date;
	}
	Date &operator=(const Date &rhs)
	{
		if (this != &rhs)
		{
			*date = *rhs.date;
		}
		return *this;
	}
	~Date()
	{
		delete date;
	}
	int getDay() const
	{
		return date->tm_mday;
	}
	int getMonth() const
	{
		return date->tm_mon + 1;
	}
	int getYear() const
	{
		return date->tm_year;
	}
	time_t getTime() const
	{
		return std::mktime(date);
	}
	bool operator<(const Date &rhs) const
	{
		return getTime() < rhs.getTime();
	}
	bool operator>(const Date &rhs) const
	{
		return getTime() > rhs.getTime();
	}
	bool operator<=(const Date &rhs) const
	{
		return getTime() <= rhs.getTime();
	}
	bool operator>=(const Date &rhs) const
	{
		return getTime() >= rhs.getTime();
	}
	bool operator==(const Date &rhs) const
	{
		return getTime() == rhs.getTime();
	}
	bool operator!=(const Date &rhs) const
	{
		return getTime() != rhs.getTime();
	}
};

std::ostream &operator<<(std::ostream &stream, const Date &date)
{
	stream << date.getYear() << '-' << std::setw(2) << std::setfill('0') << date.getMonth() << '-' << std::setw(2) << std::setfill('0') << date.getDay();
	return stream;
}

Date parseDate(const char *str)
{
	int year, month, day;
	if (sscanf(str, "%d-%d-%d", &year, &month, &day) != 3)
	{
		throw std::logic_error("Invalid date format");
	}
	return (Date(year, month, day));
}

std::map<Date, double> *generateData()
{
	std::ifstream data_file("data.csv");
	if (!data_file)
	{
		std::cerr << "Error: Could not open data.csv" << std::endl;
		return 0;
	}
	std::map<Date, double> *data = new std::map<Date, double>;
	std::string line;
	std::getline(data_file, line); // skip first line
	while (std::getline(data_file, line))
	{
		size_t comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
		{
			std::cerr << "Error: data.csv: missing a comma in a line" << std::endl;
			continue;
		}
		std::string date_str = line.substr(0, comma_pos);
		std::string value_str = line.substr(comma_pos + 1);
		try
		{
			Date date = parseDate(date_str.c_str());
			double value;
			if (sscanf(value_str.c_str(), "%lf", &value) != 1)
			{
				std::cerr << "Error: data.csv: invalid value" << std::endl;
				continue;
			}
			(*data)[date] = value;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: data.csv: " << e.what() << std::endl;
		}
	}
	return data;
}

int main(int argc, char **argv)
{
	(void)argc;
	std::ifstream input(argv[1]);
	if (!input)
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return 1;
	}
	std::map<Date, double> *data = generateData();

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		size_t separator_pos = line.find('|');
		if (separator_pos == std::string::npos)
		{
			std::cerr << "Error: missing | operator" << std::endl;
			continue;
		}
		std::string date_str = line.substr(0, separator_pos);
		std::string value_str = line.substr(separator_pos + 1);
		try
		{
			Date date = parseDate(date_str.c_str());
			float value;
			if (sscanf(value_str.c_str(), "%f", &value) != 1 || value < 0 || value > 1000)
			{
				std::cerr << "Error: invalid value" << std::endl;
				continue;
			}
			try
			{
				double scaled_value = data->at(date) * value;
				std::cout << date << " => " << value << " = " << scaled_value << std::endl;
			}
			catch (...)
			{
				std::map<Date, double>::iterator it = data->lower_bound(date);
				if (it == data->begin())
				{
					std::cerr << "Error: No element before the given date" << std::endl;
				}
				else
				{
					--it;
					double scaled_value = it->second * value;
					std::cout << date << " => " << value << " = " << scaled_value << std::endl;
				}
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: data.csv: " << e.what() << std::endl;
		}
	}

	delete data;
}