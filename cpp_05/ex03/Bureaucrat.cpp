/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:04:17 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:00:30 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat() : _name("default")
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (src._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (src._grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = src._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream &operator<<(std::ostream & flux, Bureaucrat const & src)
{
    flux << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return flux;
}

void Bureaucrat::signForm(AForm & form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cout << this->_name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}