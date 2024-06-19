/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:12:57 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/19 14:54:54 by akinzeli         ###   ########.fr       */
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
	std::cout << " Phonebook list " << std::endl;
	for (int i = 0; i < 8; i++)
	{
		this->mp_contacts[i].print_contact(i);
	}
	std::cout << std::endl;
}
