/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:03:44 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 12:38:20 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class Phonebook
{
  public:
	Phonebook();
	~Phonebook();
	void add(void);
	void search(void);
	int get_index(void) const;

  private:
	Contact mp_contacts[8];
};

#endif