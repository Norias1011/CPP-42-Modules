/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:13:23 by akinzeli          #+#    #+#             */
/*   Updated: 2024/08/31 18:27:21 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Fragtrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor with name called" << std::endl;
    this->_name = name;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    *this = src;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs )
{
    if (this != &rhs)
    {
        this->_hitpoints = rhs.getHitpoints();
        this->_energy_points = rhs.getEnergyPoints();
        this->_attack_damage = rhs.getAttackDamage();
    }
    return *this;
}


void FragTrap::highFivesGuys()
{
    std::cout << this->_name << " wants to HIGH FIVE you!" << std::endl;
}