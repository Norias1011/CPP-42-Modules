/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:26 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:03:32 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "Robotomy form Normal constructor has been called" << std::endl;
    this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
    std::cout << "Robotomy form Copy constructor has been called" << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy form Destructor has been called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
    std::cout << "Robotomy form Assignation operator has been called" << std::endl;
    if (this != &src)
    {
        _target = src._target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Robotomy form Parameter constructor has been called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (RobotomyRequestForm::isSigned() == false)
    {
        throw NotSignedException();
    }
    else if (executor.getGrade() > getGradeToExecute())
    {
        throw GradeTooLowException();
    }

    std::cout << "Drilling noises" << std::endl;
    if (rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << _target << " robotomization has failed" << std::endl;
    }
}

AForm *RobotomyRequestForm::clone(std::string target)
{
    return new RobotomyRequestForm(target);
}