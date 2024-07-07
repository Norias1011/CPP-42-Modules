/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:14:42 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/07 13:59:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float x = point.getX().getRawBits();
    float y = point.getY().getRawBits();
    float x1 = a.getX().getRawBits();
    float y1 = a.getY().getRawBits();
    float x2 = b.getX().getRawBits();
    float y2 = b.getY().getRawBits();
    float x3 = c.getX().getRawBits();
    float y3 = c.getY().getRawBits();

    float d1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
    float d2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
    float d3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}