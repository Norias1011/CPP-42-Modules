/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:29:45 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 14:54:24 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        virtual ~Dog();
        Dog(Dog const & src);
        Dog & operator=(Dog const & src);
        virtual void makeSound() const;
        void setIdea(int i, std::string idea);
        void getIdeas() const;
    protected:

    private:
        Brain* _brain;
};

#endif