/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:50:34 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:00:59 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern Normal constructor has been called" << std::endl;
    this->_forms[0] = new ShrubberyCreationForm();
    this->_forms[1] = new RobotomyRequestForm();
    this->_forms[2] = new PresidentialPardonForm();
    this->_formNames[0] = "shrubbery creation";
    this->_formNames[1] = "robotomy request";
    this->_formNames[2] = "presidential pardon";
}

Intern::Intern(Intern const & src)
{
    std::cout << "Intern Copy constructor has been called" << std::endl;
    (void)src;
    this->_forms[0] = new ShrubberyCreationForm();
    this->_forms[1] = new RobotomyRequestForm();
    this->_forms[2] = new PresidentialPardonForm();
    this->_formNames[0] = "shrubbery creation";
    this->_formNames[1] = "robotomy request";
    this->_formNames[2] = "presidential pardon";
}

Intern::~Intern()
{
    std::cout << "Intern Destructor has been called" << std::endl;
    delete _forms[0];
    delete _forms[1];
    delete _forms[2];
}

Intern & Intern::operator=(Intern const & src)
{
    std::cout << "Intern Assignation operator has been called" << std::endl;
    (void)src;
    return *this;
}

AForm *Intern::makeForm(std::string const formName, std::string const target)
{
    for (int i(0); i < 3; i++)
    {
        if (formName == this->_formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return this->_forms[i]->clone(target);
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
    /*std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i(0); i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
        else
        {
            delete forms[i];
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;*/
}