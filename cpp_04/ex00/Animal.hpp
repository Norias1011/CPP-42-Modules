/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:25:36 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 13:50:31 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        virtual ~Animal();
        Animal(Animal const & src);
        Animal & operator=(Animal const & src);
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string _type;

    private:

};


#endif