/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:06:16 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 13:58:03 by akinzeli         ###   ########.fr       */
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
	std::cin.clear(); //ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->m_firstName = this->add_contact("First name :");
	this->m_lastName = this->add_contact("Last Name : ");
	this->m_nickname = this->add_contact("Nickname : ");
	this->m_phoneNumber = this->add_contact("Phonenumber : ");
	this->m_darkestSecret = this->add_contact("Enter your darkest secret : ");
	this->m_index = i;
	std::cout << std::endl;
}

std::string Contact::add_contact(std::string input) const
{
	int	flag;

	std::string info;
	flag = 1;
	do
	{
		std::cout << input << std::flush;
		std::getline(std::cin, info);
		if (std::cin.eof() == true)
		{
			std::cout << "Exiting Phonebook" << std::endl;
			std::exit(0);
		}
		if (std::cin.good() && info.empty() == false)
			flag = 0;
		else
		{
			std::cin.clear();
			std::cout << "Invalid Input" << std::endl;
		}
	} while (flag == 1);
	return (info);
}

void Contact::print_contact(int index)
{
	if (this->m_firstName.empty() || this->m_lastName.empty()
		|| this->m_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << this->resize_contact(this->m_firstName) << std::flush;
	std::cout << "|" << this->resize_contact(this->m_lastName) << std::flush;
	std::cout << "|" << this->resize_contact(this->m_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

std::string Contact::resize_contact(std::string &info) const 
{
	if (info.length() > 10)
	{
		info.resize(9);
		info.resize(10, '.');
	}
	return (info);
}

void Contact::display_contact(int index) const
{
	if (this->m_firstName.empty() || this->m_lastName.empty()
		|| this->m_nickname.empty())
		return ;
	std::cout << "Firstname : " << m_firstName << std::endl;
	std::cout << "Lastname : " << m_lastName << std::endl;
	std::cout << "Nickname : " << m_nickname << std::endl;
	std::cout << "Phonenumber : " << m_phoneNumber << std::endl;
	std::cout << "The darkest secret : " << m_darkestSecret << std::endl;
}