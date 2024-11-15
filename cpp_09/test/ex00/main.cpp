#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	} else if (argc > 2)
	{
		std::cout << "Error: usage ./btc [file]" << std::endl;
		return 1;
	}
	BitcoinExchange ex;
	ex.parseInputFile((std::string )argv[1]);
}