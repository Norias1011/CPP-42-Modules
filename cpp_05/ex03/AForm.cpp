/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:59:31 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 15:58:08 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "AForm constructor with parameters called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_signed;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat const & src)
{
    if (src.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    this->_signed = true;
}


AForm & AForm::operator=(AForm const & src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return *this;
}

std::ostream &operator<<(std::ostream & flux, AForm const & src)
{
    flux << "AForm " << src.getName() << " is ";
    if (src.isSigned())
        flux << "signed";
    else
        flux << "not signed";
    flux << " and requires grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute() << " to execute";
    return flux;
}
