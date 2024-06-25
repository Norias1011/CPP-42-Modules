/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:11:32 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/25 16:30:44 by akinzeli         ###   ########.fr       */
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
		std::cin >> command;
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
	}
	return (0);
}
