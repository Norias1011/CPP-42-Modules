/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:38:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/04 14:06:12 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed{
    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(Fixed const & src);
        ~Fixed();
        Fixed & operator=( Fixed const & rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _value;
        static const int _bit_value;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);


#endif