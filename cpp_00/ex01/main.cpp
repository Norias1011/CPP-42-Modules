/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:11:32 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 13:51:20 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;

	std::string command;
	std::cout << "Welcome to the Phonebook" << std::endl;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT) :" << std::flush;
		std::getline(std::cin, command);
		if (std::cin.eof() == true)
		{
			std::cout << "Exiting the Phonebook" << std::endl;
			exit (0);
		}
		if (command.compare("ADD") == 0)
			phonebook.add();
		else if (command.compare("SEARCH") == 0)
			phonebook.search();
		else if (command.compare("EXIT") == 0)
			break ;
		else
		{
			std::cout << "Invalid command :";
			std::cout << "Valid commands are ADD, SEARCH and EXIT";
			std::cout << std::endl;
		}
		command.clear();
	}
	return (0);
}
