/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:34:47 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 16:58:17 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const type) : _type(type)
{
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType() const
{
    return (this->_type);
}

void Weapon::setType(std::string const &type)
{
    this->_type = type;
}

