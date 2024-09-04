/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:43:58 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 14:11:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(Dog const & src) :Animal(src)
{
    *this = src;
}

Dog & Dog::operator=(Dog const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "WOUFF WOUFF" << std::endl;
}

