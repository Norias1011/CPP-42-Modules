/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:57:47 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 17:00:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string const &name);
        ~HumanB();

        void attack() const;
        void setWeapon(Weapon &name);
    private:
        std::string _name;
        Weapon *_weapon;
};

#endif
