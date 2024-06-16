/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 00:05:54 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/17 00:10:54 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    public:
        Contact();
        ~Contact();
    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_nickname;
        std::string m_phoneNumber;
        std::string m_darkestSecret;
};

#endif