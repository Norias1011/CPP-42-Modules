/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:00:27 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/15 14:50:06 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void checkFile(std::string filename) const;
        void run(std::string filename, BitcoinExchange &exchange);
        bool checkDate(std::string &date) const;
        bool validDate(std::string &date) const;
        bool checkRate(const std::string &rate) const;
        double getPrice(std::string &date) const;
        std::map<std::string, double>::size_type size() const;
        std::map<std::string, double>::const_iterator operator[](std::map<std::string, double>::size_type index) const;

    private:
        std::map<std::string, double> _exchange;
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &exchange);

#endif