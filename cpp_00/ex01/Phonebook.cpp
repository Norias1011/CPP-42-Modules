/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:12:57 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/19 16:00:48 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
}
Phonebook::~Phonebook()
{
}

void Phonebook::add(void)
{
	int	i;

	this->mp_contacts[i % 8].new_contact(i);
	i++;
}

void Phonebook::search(void)
{
	int	index;

	std::cout << " Phonebook list " << std::endl;
	for (int i = 0; i < 8; i++)
	{
		this->mp_contacts[i].print_contact(i);
	}
	std::cout << std::endl;
	index = this->get_index();
	this->mp_contacts[index].display_contact(index);
}

int Phonebook::get_index(void)
{
	int	index;
	int	flag;

	index = 9;
	flag = 0;
	std::cout << "Enter the contact index";
	std::cin >> index;
	std::cin.ignore();
	if (std::cin.good() && (index >= 0 && index < 8))
		flag = 1;
	else
	{
		std::cin.clear();
		std::cout << "Wrong index, between 0 to 7" << std::endl;
	}
	if (flag = 0)
		get_index();
	return (index);
}
