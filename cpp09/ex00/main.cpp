#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	std::ifstream input(argv[1]);
	if (!input)
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return 1;
	}
	std::ifstream data_file("data.csv");
	if (!data_file)
	{
		std::cerr << "Error: Could not open data.csv" << std::endl;
		return 0;
	}
	std::map<Date, double> *data = generateData(data_file);
	bitcoinExchange(input, data);
	delete data;
}