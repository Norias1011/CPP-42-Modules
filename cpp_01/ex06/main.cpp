/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:59:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 15:58:55 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Please say something Sir" << std::endl;
        return (1);
    }
    std::string line(av[1]);
    int flag(0);
    Harl harl;
    if (line.compare("DEBUG") == 0)
        flag = 1;
    else if (line.compare("INFO") == 0)
        flag = 2;
    else if (line.compare("WARNING") == 0)
        flag = 3;
    else if (line.compare("ERROR") == 0)
        flag = 4;
    harl.complain(flag);
}