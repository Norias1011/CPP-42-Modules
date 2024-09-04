/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:01:19 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 14:14:00 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "WrongAnimal";
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    *this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "GRRRRRRRRRR" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}