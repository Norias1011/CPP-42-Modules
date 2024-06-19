/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:12:05 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/19 16:14:15 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}

void Contact::new_contact(int i)
{
	std::cin.ignore();
	this->m_firstName = this->add_contact("First name :");
	this->m_lastName = this->add_contact("Last Name : ");
	this->m_nickname = this->add_contact("Nickname : ");
	this->m_phoneNumber = this->add_contact("Phonenumber : ");
	this->m_darkestSecret = this->add_contact("Enter your darkest secret : ");
	this->m_index = i;
	std::cout << std::endl;
}

std::string Contact::add_contact(std::string input)
{
	int	flag;

	std::string info;
	flag = 0;
	std::cout << input << std::flush;
	std::getline(std::cin, info);
	if (std::cin.good() && info.empty() == false)
		flag = 1;
	else
	{
		std::cin.clear();
		std::cout << "Invalid Input" << std::endl;
	}
	if (flag == 1)
		add_contact(input);
	return (info);
}

void Contact::print_contact(int index)
{
	if (this->m_firstName.empty() || this->m_lastName.empty()
		|| this->m_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << this->resize_contact(this->m_firstName);
	std::cout << "|" << this->resize_contact(this->m_lastName);
	std::cout << "|" << this->resize_contact(this->m_nickname);
	std::cout << "|" << std::endl;
}

std::string Contact::resize_contact(std::string info)
{
	if (info.length() > 10)
		info.resize(10, '.');
	return (info);
}

void Contact::display_contact(int index)
{
	if (this->m_firstName.empty() || this->m_lastName.empty()
		|| this->m_nickname.empty() || this->m_phoneNumber.empty()
		|| this->m_darkestSecret.empty())
		return ;
	std::cout << m_firstName << std::endl;
	std::cout << m_lastName << std::endl;
	std::cout << m_nickname << std::endl;
	std::cout << m_phoneNumber << std::endl;
	std::cout << m_darkestSecret << std::endl;
}
