/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:00:30 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/17 16:51:34 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string price;
        std::getline(ss, date, ',');
        std::getline(ss, price, ',');
        _exchange[date] = atof(price.c_str());
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    _exchange = other._exchange;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &exchange)
{
    for (std::map<std::string, double>::size_type it = 0; it < exchange.size(); it++)
    {
        out << exchange[it]->first << " : " << exchange[it]->second << std::endl;
    }
    return out;
}

std::map<std::string, double>::size_type BitcoinExchange::size() const
{
    return _exchange.size();
}

std::map<std::string, double>::const_iterator BitcoinExchange::operator[](std::map<std::string, double>::size_type index) const
{
    std::map<std::string, double>::const_iterator it = _exchange.begin();
    for (std::map<std::string, double>::size_type i = 0; i < index; i++)
    {
        it++;
    }
    return it;
}

void BitcoinExchange::checkFile(std::string filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    file.close();
    std::ifstream file2("data.csv");
    if (!file2.is_open())
    {
        std::cerr << "Error: could not open file data.csv." << std::endl;
        exit(1);
    }
}

void BitcoinExchange::run(std::string filename, BitcoinExchange &exchange)
{
    std::ifstream input_file(filename.c_str());
    std::string line;

    std::getline(input_file, line);
    while (std::getline(input_file, line))
    {
        size_t pos = line.find("|");
        if (pos == std::string::npos || line.length() < pos + 2)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos - 1);
        if (!exchange.checkDate(date) || !exchange.validDate(date))
            continue;
        std::string rate = line.substr(pos + 2);
        rate.erase(std::remove_if(rate.begin(), rate.end(), isspace), rate.end());
        if (!exchange.checkRate(rate))
            continue;
        double final_rate = atof(rate.c_str());
        double price = exchange.getPrice(date);
        std::cout << date << " => " << final_rate << " = " << std::fixed << std::setprecision(1) << final_rate * price << std::endl;
    }
    input_file.close();
}

bool BitcoinExchange::checkRate(const std::string &rate) const
{
    if (rate.empty() || (rate.find_first_not_of("0123456789.-") != std::string::npos) || rate.at(0) == '.' || rate.at(rate.length() - 1) == '.')
    {
        std::cerr << "Error: invalid rate => " << rate << std::endl;
        return false;
    }
    else if (rate.at(0) == '-')
    {
        std::cerr << "Error: not a positive number" << std::endl;
        return false;
    }
    else if (rate.length() > 10 || (rate.length() == 10 && rate > "2147483647"))
    {
        std::cerr << "Error: too large a number" << std::endl;
        return false;
    }
    return true;
}


bool BitcoinExchange::checkDate(std::string &date) const
{
    if (date.empty() || date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-' || date.find_first_not_of("0123456789-") != std::string::npos)
    {
        std::cerr << "Error: bad input => " << date << std::endl;    
        return false;
    }
    return true;
}

bool BitcoinExchange::validDate(std::string &date) const
{
    tm time = {};

    char *end = strptime(date.c_str(), "%Y-%m-%d", &time);
    if (end == NULL || *end != '\0')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    tm duplicateTime = time;
    time_t result = mktime(&time);
    if (result == -1)
    {
        std::cerr << "mktime wrong" << std::endl;
        return false;
    }
    if (duplicateTime.tm_year != time.tm_year || duplicateTime.tm_mon != time.tm_mon || duplicateTime.tm_mday != time.tm_mday)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (result < 1230850800)
    {
        std::cerr << "Error: bad input => " << date << " (btc start the 2009-01-02)" << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::getPrice(std::string &date) const
{
    if (this->_exchange.count(date) > 0)
        return this->_exchange.at(date);
    return (--this->_exchange.lower_bound(date))->second;
}