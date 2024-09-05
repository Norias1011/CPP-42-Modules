/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:43:06 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 14:49:11 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
    _type = "Animal";
    std::cout << "Animal Constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
    *this = src;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string AAnimal::getType() const
{
    return _type;
}
