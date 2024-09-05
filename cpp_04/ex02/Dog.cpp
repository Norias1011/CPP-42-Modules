/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:43:58 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 14:50:45 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(Dog const & src) :AAnimal(src)
{
    this->_brain = new Brain();
    *this = src;
}

Dog & Dog::operator=(Dog const & src)
{
    if (this != &src)
    {
        _type = src._type;
        *(this->_brain) = *(src._brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "WOUFF WOUFF" << std::endl;
}


void Dog::setIdea(int i, std::string idea)
{
    this->_brain->setIdea(i, idea);
}

void Dog::getIdeas() const
{
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << this->_brain->getIdea(i) << std::endl;
    }
}

