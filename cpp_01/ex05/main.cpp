/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:42:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 14:40:12 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    std::string line;
    Harl harl;

    std::cout << "Hello Sir, welcome to 42Burgers, how can i help you?" << std::endl;
    std::cout << "(only DEBUG, INFO, WARNING amd ERROR available)" << std::endl;
    while (1)
    {
        getline(std::cin, line);
        harl.complain(line);
        std::cin.clear();
    }
    std::cout << "Thank you for your time and have a nice day" << std::endl;
}