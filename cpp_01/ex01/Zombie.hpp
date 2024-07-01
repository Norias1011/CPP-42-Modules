/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:53:02 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 15:05:28 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        void announce();
        void setName(std::string name);
    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif

