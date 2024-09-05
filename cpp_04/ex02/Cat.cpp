/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:44 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 14:55:13 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(Cat const & src) :AAnimal(src)
{
    this->_brain = new Brain();
    *this = src;
}

Cat & Cat::operator=(Cat const & src)
{
    if (this != &src)
    {
        *(this->_brain) = *(src._brain);
        _type = src._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "MIAOUUU MIAOUUU" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}

void Cat::getIdeas() const
{
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << this->_brain->getIdea(i) << std::endl;
    }
}