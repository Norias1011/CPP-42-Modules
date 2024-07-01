/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:59 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 15:15:02 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* horde = zombieHorde(10, "Zombie");

    for (int i = 0; i < 10; i++)
        horde[i].announce();
    delete [] horde;
}