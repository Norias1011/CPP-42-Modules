/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:25:36 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/05 14:49:09 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

class AAnimal
{
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(AAnimal const & src);
        AAnimal & operator=(AAnimal const & src);
        virtual void makeSound() const = 0;
        std::string getType() const;
    protected:
        std::string _type;

    private:

};


#endif