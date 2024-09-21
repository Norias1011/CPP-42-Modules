/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:50:38 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 15:42:20 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const & src);
        Intern & operator=(Intern const & src);
        AForm *makeForm(std::string const formName, std::string const target);
    private:
        AForm *_forms[3];
        std::string _formNames[3];
};

#endif