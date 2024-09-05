/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:59:03 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/06 01:06:51 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria 
{
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        AMateria & operator=(AMateria const & src);
        virtual AMateria* clone() const = 0;
        std::string const & getType() const;
        virtual void use(ICharacter& target);
    protected:
        std::string _type;
};

#endif