/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:36 by akinzeli          #+#    #+#             */
/*   Updated: 2024/08/31 18:27:55 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

//std::string ScavTrap::class_name = "ScavTrap";

ScavTrap::ScavTrap()
{
    std::cout << "Scavtrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor with name called" << std::endl;
    this->_name = name;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "I'am in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
    *this = src;
    std::cout << "Scavtrap copy constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs)
{
    if (this != &rhs)
    {
        this->_attack_damage = rhs.getAttackDamage();
        this->_energy_points = rhs.getEnergyPoints();
        this->_hitpoints = rhs.getHitpoints();
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0 && this->_hitpoints > 0)
    {
        std::cout << "ScavTrap" << " " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points -= 1;
    }
    else
        std::cout << "ScavTrap" << " " << this->_name << " is out of energy or hit points!" << std::endl;
}



