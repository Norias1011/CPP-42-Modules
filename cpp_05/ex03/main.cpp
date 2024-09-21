/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:59:13 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:08:00 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    std::cout << "--------------- Intern ---------------" << std::endl;
    try 
	{
        AForm *SCF = intern.makeForm("shrubbery creation", "home");
        Bureaucrat b1("Bob", 136);
        Bureaucrat b2("Jhon", 145);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    
	catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try 
	{
        AForm *SCF = intern.makeForm("robotomy request", "home");
        Bureaucrat b1("Bob2", 44);
        Bureaucrat b2("Jhon2", 72);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }

    catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--------------- Bureaucrat ---------------" << std::endl;

    try {
        Bureaucrat bureaucrat("ash", 2);
        Bureaucrat employee("John", 100); 
        ShrubberyCreationForm form1("Shrubbery");
        ShrubberyCreationForm form4("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        RobotomyRequestForm form5("Robotomy");
        PresidentialPardonForm form3("President");
        PresidentialPardonForm form6("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        //employee.executeForm(form4);
        employee.signForm(form4);
        employee.executeForm(form4);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat.executeForm(form2);
        //employee.executeForm(form5);
        //employee.signForm(form5);
        //employee.executeForm(form5);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
        //employee.executeForm(form6);
        //employee.signForm(form6);
        //employee.executeForm(form6);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}