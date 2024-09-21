/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:07 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:03:40 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "President form Normal constructor has been called" << std::endl;
    this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "President form Parameter constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src)
{
    std::cout << "President form Copy constructor has been called" << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "President form Destructor has been called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
    std::cout << "President form Assignation operator has been called" << std::endl;
    if (this != &src)
    {
        _target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (PresidentialPardonForm::isSigned() == false)
    {
        throw NotSignedException();
    }
    else if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

AForm *PresidentialPardonForm::clone(std::string target)
{
    return new PresidentialPardonForm(target);
}