/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:32 by akinzeli          #+#    #+#             */
/*   Updated: 2024/08/29 17:04:41 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("The Big ScavTrap");
    ScavTrap b;

    a.attack("The Lord");
    a.beRepaired(20);
    a.guardGate();
    a.takeDamage(30);
    b.attack("The King");
    b.beRepaired(20);
    b.guardGate();
    b.takeDamage(30);
    return 0;
}