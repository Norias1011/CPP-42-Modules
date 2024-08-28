/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:14:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/08 18:27:53 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit_value = 8;

Fixed::Fixed(): _value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
    //std::cout << "Int constructor called" << std::endl;
    this->_value = value << Fixed::_bit_value;
}

Fixed::Fixed(float const value)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << Fixed::_bit_value));
}

Fixed::Fixed(Fixed const & src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs)
{
    //std::cout << "Copy Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (float)(1 << Fixed::_bit_value);
}

int Fixed::toInt(void) const
{
    return this->_value >> Fixed::_bit_value;
}

std::ostream &operator<<( std::ostream &o,Fixed const &value)
{
    o << value.toFloat();
    return o;
}

float Fixed::operator+(Fixed const &rhs) const
{
    return (this->toFloat() + rhs.toFloat());
}

float Fixed::operator-(Fixed const &rhs) const
{
    return (this->toFloat() - rhs.toFloat());
}

float Fixed::operator*(Fixed const &rhs) const
{
    return (this->toFloat() * rhs.toFloat());
}

float Fixed::operator/(Fixed const &rhs) const
{
    return (this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++()
{
    ++this->_value;
    return *this;
}

Fixed Fixed::operator--()
{
    --this->_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++this->_value;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --this->_value;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a.toFloat() <= b.toFloat() ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    return a.toFloat() <= b.toFloat() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a.toFloat() >= b.toFloat() ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    return a.toFloat() >= b.toFloat() ? a : b;
}

bool Fixed::operator>(Fixed const &rhs) const
{
    return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return this->toFloat() != rhs.toFloat();
}

bool Fixed::operator==(Fixed const &rhs) const
{
    return this->toFloat() == rhs.toFloat();
}