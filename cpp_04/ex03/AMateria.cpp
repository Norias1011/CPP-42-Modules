/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:58:59 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 19:00:03 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria created" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destroyed" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
}

AMateria & AMateria::operator=(AMateria const & src)
{
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}


void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used on " << target.getName() << std::endl;
}


