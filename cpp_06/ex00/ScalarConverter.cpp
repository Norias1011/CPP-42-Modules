/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:21:46 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 16:28:37 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::convert(const std::string &input)
{
    std::string special_values[6] = {"nan", "-inf", "+inf", "inff", "-inff", "inf"};
    std::string toChar = "";
    int toInt = 0;
    float toFloat = 0;
    double toDouble = 0;

    if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
    {
        toChar = input[0];
        toInt = static_cast<int>(toChar[0]);
        toFloat = static_cast<float>(toChar[0]);
        toDouble = static_cast<double>(toChar[0]);
        std::cout << "char: " << toChar << std::endl;
        std::cout << "int: " << toInt << std::endl;
        std::cout << "float: " << toFloat << ".0f" << std::endl;
        std::cout << "double: " << toDouble << ".0" << std::endl;
        return;
    }

    toInt = std::atoi(input.c_str());

    if (input[input.length() - 1] == 'f')
    {
        toFloat = std::atof(input.c_str());
        toDouble = static_cast<double>(toFloat);
    }
    else
    {
        toDouble = std::atof(input.c_str());
        toFloat = static_cast<float>(toDouble);
    }

    for (int i = 0; i < 6; i++)
    {
        if (input == special_values[i])
        {
            toChar = "impossible";
            break;
        }
    }

    if (toChar.empty())
    {
        if (toInt == 0 && (input[0] != '0' || input.length() > 1))
            toChar = "impossible";
        else if (toInt < 32 || toInt > 126)
            toChar = "Non displayable";
        else
        {
            toChar = "'";
            toChar += static_cast<char>(toInt);
            toChar += "'";
        }
    }

    std::cout << "char: " << toChar << std::endl;
    if (toChar == "impossible")
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << toInt << std::endl;

    if (toChar == "impossible" && toFloat == 0)
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << toFloat << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << toDouble << std::endl;
    }
}