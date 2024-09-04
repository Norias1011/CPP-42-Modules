/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:04:16 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 14:13:58 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat";
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) :WrongAnimal(src)
{
    *this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "MIAOUUU MIAOUUU" << std::endl;
}