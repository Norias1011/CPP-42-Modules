
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

class BitcoinExchange
{
private:
	std::map<time_t , double> datas;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	void initCSV();
	void parseInputFile(std::string str);
	double getPrice(std::string date);
	time_t getTime(std::string str);
};


#endif
