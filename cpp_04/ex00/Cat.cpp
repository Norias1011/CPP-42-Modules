/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:44 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 13:58:16 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(Cat const & src) :Animal(src)
{
    *this = src;
}

Cat & Cat::operator=(Cat const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "MIAOUUU MIAOUUU" << std::endl;
}