#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cout << argv[1] << ": Error" << std::endl;
		return 1;
	}
	std::string replace_file_name = std::string(argv[1]) + ".replace";
	std::ofstream replace_file(replace_file_name.c_str());
	std::string target_str = argv[2];
	std::string replace_str = argv[3];
	std::string line;
	while (getline(file, line))
	{
		std::size_t pos = 0;
		while ((pos = line.find(target_str)) != std::string::npos)
		{
			line.erase(pos, target_str.size());
			line.insert(pos, replace_str);
		}
		replace_file << line << std::endl;
	}
	file.close();
	replace_file.close();
}