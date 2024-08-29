/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:14:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/08/29 16:47:44 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name("New Name"), _hitpoints(100), _energy_points(50), _attack_damage(20)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(100), _energy_points(50), _attack_damage(20)
{
    std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    *this = src;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std:: cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs )
{
    if (this != &rhs)
    {
        this->_hitpoints = rhs.getHitpoints();
        this->_energy_points = rhs.getEnergyPoints();
        this->_attack_damage = rhs.getAttackDamage();
    }
    return *this;
}

int ClapTrap::getHitpoints() const
{
    return this->_hitpoints;
}

int ClapTrap::getEnergyPoints() const
{
    return this->_energy_points;
}

int ClapTrap::getAttackDamage() const
{
    return this->_attack_damage;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0 && this->_hitpoints > 0)
    {
        std::cout << "ClapTrap" << " " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points -= 1;
    }
    else
        std::cout << "ClapTrap" << " " << this->_name << " is out of energy or hit points!" << std::endl;
}




void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitpoints > (int)amount)
        this->_hitpoints -= amount;
    else if (this->_hitpoints > 0)
        this->_hitpoints = 0;
    else
    {
        std::cout << "ClapTrap" << " " << this->_name << " is already dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap" << " " << this->_name << " was attacked for " << amount << " points of damage!" << std::endl;
}




void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points > 0 && this->_hitpoints > 0)
    {
        std::cout << "ClapTrap" << " " << this->_name << " is being repaired for " << amount << " points of damage!" << std::endl;
        this->_hitpoints += amount;
        this->_energy_points -= 1;
    }
    else
        std::cout << "ClapTrap" << " " << this->_name << " is out of energy or hit points!" << std::endl;
}
