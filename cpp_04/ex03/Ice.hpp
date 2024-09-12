/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:28:59 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/12 13:19:01 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( Ice const & src );
        ~Ice();
        Ice & operator=( Ice const & rhs );
        Ice* clone() const;
        void use(ICharacter& target);
        std::string const & getType() const;
};

#endif