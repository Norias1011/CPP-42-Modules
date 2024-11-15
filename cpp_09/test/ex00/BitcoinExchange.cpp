
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
//	std::cout << "[BitcoinExchange] Default constructor called" << std::endl;
	initCSV();
}

BitcoinExchange::~BitcoinExchange()
{
//	std::cout << "[BitcoinExchange] Default destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
//	std::cout << "[BitcoinExchange] Copy constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
//	std::cout << "[BitcoinExchange] Default Assignment called" << std::endl;
	if (this == &copy)
		return *this;
	//do some stuff
	return *this;
}

void BitcoinExchange::initCSV()
{
	std::fstream csv;
	std::string temp, line, word, date, priceStr;
	csv.open("data.csv", std::ios::in);
	while(csv >> temp)
	{
		getline(csv, line);
		std::stringstream s(temp);
		date = "";
		priceStr = "";
		while (getline(s, word, ','))
		{
			if (word == "date" || word == "exchange_rate")
				continue;
			if (date.empty())
				date = word;
			else if (priceStr.empty())
				priceStr = word;
		}
		if (date.empty() && priceStr.empty())
			continue;
		double price = atof(priceStr.c_str());
		this->datas.insert(std::pair<time_t , double>(getTime(date), price));
	}
}

double BitcoinExchange::getPrice(std::string date)
{

	time_t time = getTime(date);
	while(time >= 1230850800)
	{
		try
		{
			return this->datas.at(time);
		}
		catch (std::exception e)
		{}
		time -= 86400;
	}
	return -1;
}


time_t BitcoinExchange::getTime(std::string str)
{
    tm time = {};

    char *end = strptime(str.c_str(), "%Y-%m-%d", &time);
    if (end == NULL || *end != '\0') {
        std::cerr << "strptime failed to parse the date" << std::endl;
        return -1;
    }
	tm duplicateTime = time;
    // Print parsed date

    time_t result = mktime(&time);
    if (result == -1) {
        std::cerr << "mktime failed" << std::endl;
		return -1;
    }

    // Validation
    if (duplicateTime.tm_year != time.tm_year ||
        duplicateTime.tm_mon != time.tm_mon ||
        duplicateTime.tm_mday != time.tm_mday) {
//        std::cerr << "Invalid date!" << std::endl;
        return -1;
    }

    return result;
}

void BitcoinExchange::parseInputFile(std::string str)
{
	std::ifstream file;
	std::string temp, line, word, date, amount;
	std::stringstream lastLine;
	file.open(str.c_str(), std::ios::in);
	int nbLine = 0;
	while (file)
	{
		if (lastLine.tellp() != 0)
			std::cout << lastLine.str();
		std::getline(file, line);
		std::stringstream s(line);
		int nbWord = 0;
		date = amount = "";
		while (getline(s, word, ' '))
		{
			if (nbLine == 0 && nbWord == 0 && word == "date")
			{
				nbWord++;
				continue;
			}
			if (nbWord == 1 && word == "|")
			{
				nbWord++;
				continue;
			}
			if (nbLine == 0 && nbWord == 2 && word == "value")
			{
				nbWord++;
				continue;
			}
			if (nbWord == 0)
				date = word;
			if (nbWord == 2)
				amount = word;
			nbWord++;
		}
		if (date.empty() && amount.empty() && nbLine == 0)
			continue;
		lastLine.str("");
		time_t newTime = getTime(date);
		double newAmount = atof(amount.c_str());
		if (newTime == -1)
		{
			lastLine << "Error: bad input => " << date << std::endl;
		}
		else if (newTime < 1230850800)
		{
			lastLine << "Error: bad input => " << date << " (btc start the 2009-01-02)" << std::endl;
		}
		else if (newAmount <= 0)
		{
			lastLine << "Error: not a positive number." << std::endl;
		}
		else if (newAmount > 1000)
		{
			lastLine << "Error: too large a number." << std::endl;
		}
		else
		{
			lastLine << date << " => " << newAmount << " = " << newAmount * getPrice(date) << std::endl;
		}
		nbLine++;
	}
}
