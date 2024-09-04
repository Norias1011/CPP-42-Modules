/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:00:10 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 14:08:49 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(WrongAnimal const & src);
        WrongAnimal & operator=(WrongAnimal const & src);
        void makeSound() const;
        std::string getType() const;
    protected:
        std::string _type;
};


#endif