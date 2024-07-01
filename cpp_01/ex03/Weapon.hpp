/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:34:52 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 16:58:19 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    public:
        Weapon(std::string const type);
        ~Weapon();

        std::string const &getType() const;
        void setType(std::string const &type);
    private:
        std::string _type;
};

#endif
