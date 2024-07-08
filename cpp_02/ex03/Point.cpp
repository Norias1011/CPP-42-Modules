/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:14:25 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/08 18:25:10 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
    return ;
}

Point::Point( float const x, float const y ) : _x(x), _y(y)
{
    return;
}

Point::~Point( void )
{
    return ;
}

Point::Point( Point const & src ) : _x(src.getX()), _y(src.getY())
{
    return ;
}

const Fixed &Point::getX( void ) const
{
    return this->_x;
}

const Fixed &Point::getY( void ) const
{
    return this->_y;
}

Point & Point::operator=( Point const & rhs)
{
    if (this == &rhs)
        return *this;
    return *this;
}

std::ostream &operator<<(std::ostream &o, Point const &point)
{
    o << "Point(" << point.getX() << ", " << point.getY() << ")";
    return o;
}