/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:07:02 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 17:04:05 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : _name(name) , _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
    std::cout << this->_name << " attacks with their "; 
    
    if (this->_weapon == NULL)
        std::cout << "big old brain" << std::endl;
    else
        std::cout << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &name)
{
    this->_weapon = &name;
}
