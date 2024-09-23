/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:21:42 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 16:23:08 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <iomanip>

class ScalarConverter
{
    public:
        static void convert(const std::string &input);
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        virtual ~ScalarConverter() = 0;
        ScalarConverter &operator=(const ScalarConverter &other);
};

#endif