/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:04:55 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/04 18:00:49 by akinzeli         ###   ########.fr       */
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
        float operator+(Fixed rhs) const;
        float operator-(Fixed rhs) const;
        float operator*(Fixed rhs) const;
        float operator/(Fixed rhs) const;
        bool operator>(Fixed rhs) const;
        bool operator<(Fixed rhs) const;
        bool operator>=(Fixed rhs) const;
        bool operator<=(Fixed rhs) const;
        bool operator==(Fixed rhs) const;
        bool operator!=(Fixed rhs) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed operator++();
        Fixed operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        static Fixed &max(Fixed &a, Fixed &b);
        static Fixed const &max(Fixed const &a, Fixed const &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);

    private:
        int _value;
        static const int _bit_value;
};

std::ostream &operator<<(std::ostream &o, Fixed const &value);

#endif