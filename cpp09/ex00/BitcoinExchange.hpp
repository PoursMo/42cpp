#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
	Date(int year, int month, int day);
	Date(const Date &rhs);
	Date &operator=(const Date &rhs);
	~Date();
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	time_t getTime() const;
	bool operator<(const Date &rhs) const;
	bool operator>(const Date &rhs) const;
	bool operator<=(const Date &rhs) const;
	bool operator>=(const Date &rhs) const;
	bool operator==(const Date &rhs) const;
	bool operator!=(const Date &rhs) const;
};

std::ostream &operator<<(std::ostream &stream, const Date &date);

void bitcoinExchange(std::ifstream &input, std::map<Date, double> *data);
std::map<Date, double> *generateData(std::ifstream &data_file);

#endif