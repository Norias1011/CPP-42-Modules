/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:31:10 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/12 13:18:55 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure( Cure const & src );
        ~Cure();
        Cure & operator=( Cure const & rhs );
        Cure* clone() const;
        void use(ICharacter& target);
        std::string const & getType() const;
};

#endif