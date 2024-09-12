/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:02:38 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/12 13:14:22 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    this->_type = "cure";
    std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure( Cure const & src ) : AMateria(src)
{
    *this = src;
}

Cure & Cure::operator=( Cure const & rhs )
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

Cure* Cure::clone() const
{
    Cure* cure = new Cure();
    return cure;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string const & Cure::getType() const
{
    return this->_type;
}