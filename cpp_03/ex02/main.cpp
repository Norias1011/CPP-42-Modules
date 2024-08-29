/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:15:33 by akinzeli          #+#    #+#             */
/*   Updated: 2024/08/29 17:38:19 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"


int main()
{
    FragTrap a("The Big");
    FragTrap b;

    a.attack("The Lord");
    a.beRepaired(20);
    a.highFivesGuys();
    a.takeDamage(30);
    b.attack("The King");
    b.beRepaired(20);
    b.highFivesGuys();
    b.takeDamage(30);
    return 0;
}