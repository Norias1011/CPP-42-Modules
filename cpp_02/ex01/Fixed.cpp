/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:39:25 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/04 14:08:00 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit_value = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << Fixed::_bit_value;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << Fixed::_bit_value));
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    
}

int Fixed::toInt(void) const
{
    return this->_value >> Fixed::_bit_value;
}
