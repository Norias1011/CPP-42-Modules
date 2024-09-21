/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:59:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:02:28 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const name, int gradeToSign, int gradeToExecute);
        AForm();
        AForm(AForm const & src);
        virtual ~AForm(); 
        AForm & operator=(AForm const & src);
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const & src);
        virtual AForm *clone(std::string Target) = 0;

        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too high";
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Grade is too low" ;
                }
        };

        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Form is not signed";
                }
        };
        
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream & flux, AForm const & src);

#endif