/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:45 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 14:38:42 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "Normal constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Parameter constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
    std::cout << "Copy constructor has been called" << std::endl;
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor has been called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
    std::cout << "Assignation operator has been called" << std::endl;
    if (this != &src)
    {
        _target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
    if (ShrubberyCreationForm::isSigned() == false)
    {
        throw AForm::NotSignedException();
    }
    else if (executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file((this->getName() + "_shrubbery").c_str());
    file << "                                            ." << std::endl;
    file << "                                          .         ;" << std::endl;  
    file << "             .              .              ;%     ;;" << std::endl;   
    file << "               ,           ,                :;%  %;   " << std::endl;
    file << "                :         ;                   :;%;'     .,   " << std::endl;
    file << "       ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "          %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                  `@%:.  :;%.         ;@@%;'  " << std::endl; 
    file << "                    `@%.  `;@%.      ;@@%; " << std::endl;        
    file << "                      `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                        ;@%. :@%%  %@@%;       " << std::endl;
    file << "                          %@bd%%%bd%%:;     " << std::endl;
    file << "                            #@%%%%%:;;" << std::endl;
    file << "                            %@@%%%::;" << std::endl;
    file << "                            %@@@%(o);  . '         " << std::endl;
    file << "                            %@@@o%;:(.,'         " << std::endl;
    file << "                        `.. %@@@o%::;         " << std::endl;
    file << "                           `)@@@o%::;         " << std::endl;
    file << "                            %@@(o)::;        " << std::endl;
    file << "                           .%@@@@%::;         " << std::endl;
    file << "                           ;%@@@@%::;.          " << std::endl;
    file << "                          ;%@@@@%%:;;;. " << std::endl;
    file << "                      ...;%@@@@@%%:;;;;,.." << std::endl;
    file.close();
}