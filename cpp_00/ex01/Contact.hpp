/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:05:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 12:37:01 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <limits>
# include <string>

class Contact
{
  public:
	Contact();
	~Contact();
	void new_contact(int i);
	std::string add_contact(std::string input) const;
	void print_contact(int index);
	std::string resize_contact(std::string &info) const;
	void display_contact(int index) const;

  private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_nickname;
	std::string m_phoneNumber;
	std::string m_darkestSecret;
	int m_index;
};

#endif
