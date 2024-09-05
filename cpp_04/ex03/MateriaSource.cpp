/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:25:56 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 19:25:18 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        this->_materias[i] = NULL;
    }
    std::cout << "Materia Source constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] != NULL)
        {
            delete this->_materias[i];
        }
    }
    std::cout << "Materia Source destructor called" << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const & src )
{
    for (int i = 0; i < 4; i++)
    {
        if (src._materias[i] != NULL)
        {
            this->_materias[i] = src._materias[i]->clone();
        }
    }
    std::cout << "Materia Source copy constructor called" << std::endl;
}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs )
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_materias[i] != NULL)
            {
                delete this->_materias[i];
            }
            if (rhs._materias[i] != NULL)
            {
                this->_materias[i] = rhs._materias[i]->clone();
            }
        }
    }
    std::cout << "Materia Source assignment operator called" << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] == NULL)
        {
            this->_materias[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (this->_materias[i] != NULL)
    {
        if (this->_materias[i]->getType() == type)
        {
            return this->_materias[i]->clone();
        }
        i++;
    }
    return NULL;
}





