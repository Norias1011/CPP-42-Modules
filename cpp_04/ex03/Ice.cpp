/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:30:45 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/12 13:19:14 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria(src)
{
    *this = src;
}

Ice & Ice::operator=( Ice const & rhs )
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

Ice* Ice::clone() const
{
    Ice* ice = new Ice();
    return ice;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::string const & Ice::getType() const
{
    return this->_type;
}