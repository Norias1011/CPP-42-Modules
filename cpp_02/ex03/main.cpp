/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:14:32 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/08 18:33:40 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    Point a( -80, -80 );
    Point b( -80, -80 );
    Point c( -80, -80 );
    Point point( 80, 80 );

    std::cout << "Point a: x " << a.getX() << " y " << a.getY() << std::endl;
    std::cout << "Point b: x " << b.getX() << " y " << b.getY() << std::endl;
    std::cout << "Point c: x " << c.getX() << " y " << c.getY() << std::endl;
    std::cout << "Point: x " << point.getX() << " y " << point.getY() << std::endl;

    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle" << std::endl;
    else
        std::cout << "The point is outside the triangle" << std::endl;
    return 0;
}
