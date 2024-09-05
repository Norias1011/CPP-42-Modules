/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:21:11 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 15:23:10 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
    *this = src;
}

Brain & Brain::operator=(Brain const &src)
{
    if (this == &src)
        return *this;
    for (size_t i = 0; i < 100; i++)
    {
        if (src._ideas[i].length() > 0)
            _ideas[i] = src._ideas[i];
    }
    return *this;
}

void Brain::setIdea(int i, std::string idea)
{
    if (i < 100)
        _ideas[i] = idea;
    else
        std::cout << "only a 100 ideas can be stored" << std::endl;
}

const std::string Brain::getIdea(size_t i) const
{
    if (i < 100)
        return _ideas[i];
    else
        return "only a 100 ideas can be stored";
}

const std::string *Brain::getIdeasAddress(size_t i) const
{
    if (i < 100)
        return &_ideas[i];
    else
        return NULL;
}