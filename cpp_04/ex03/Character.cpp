/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:21:17 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/12 14:02:00 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
    std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] != 0)
            delete _materias[i];
    }
    std::cout << "Character destructor called" << std::endl;
}

Character::Character( Character const & src )
{
    for (int i = 0; i < 4; i++)
    {
        if (src._materias[i] != 0)
            _materias[i] = src._materias[i]->clone();
        else
            _materias[i] = 0;
    }
    std::cout << "Character copy constructor called" << std::endl;
}

Character & Character::operator=( Character const & rhs )
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i] != 0)
                delete _materias[i];
            if (rhs._materias[i] != 0)
                _materias[i] = rhs._materias[i]->clone();
        }
    }
    std::cout << "Character assignation operator called" << std::endl;
    return *this;
}

std::string const & Character::getName() const
{
    return _name;
}


void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << "Can't equip nothing" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] == 0)
        {
            this->_materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _materias[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    std::cout << "I'm in use" << std::endl;
    if (idx >= 0 && idx < 4 && _materias[idx] != 0)
        _materias[idx]->use(target);
}



