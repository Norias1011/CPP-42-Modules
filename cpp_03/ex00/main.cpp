/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:34:30 by akinzeli          #+#    #+#             */
/*   Updated: 2024/08/28 14:56:33 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2;

    claptrap.attack("Skag");
    claptrap.takeDamage(10);
    claptrap.beRepaired(5);
    claptrap2.attack("Old Skag");
    claptrap2.takeDamage(10);
    claptrap2.beRepaired(5);
    return 0;
}