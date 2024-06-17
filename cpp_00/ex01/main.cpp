/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:11:32 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/17 16:24:40 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std::cout << "Welcome to the phonebook" << std::endl;
    while (1)
    {
        std::string command;
        std::cout << "Enter a command (ADD, SEARCH or EXIT) :";
        std::cin >> command;
        if (command == "ADD")
            phonebook.add();
        else if (command == "SEARCH")
            phonebook.search();
        else if (command == "EXIT")
            break;
        else
        {
            std::cout << "Invalid command :"; 
            std::cout << "Valid commands are ADD, SEARCH and EXIT";
            std::cout << std::endl;
        }
    }
    return 0;
}