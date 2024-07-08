/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:14:20 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/08 18:25:11 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point( float const x, float const y );
        Point( Point const & src );
        ~Point( void );

        const Fixed &getX( void ) const;
        const Fixed &getY( void ) const;

        Point & operator=( Point const & rhs );


    private:
        Fixed const _x;
        Fixed const _y;
};

std::ostream &operator<<(std::ostream &o, Fixed const &value);


#endif