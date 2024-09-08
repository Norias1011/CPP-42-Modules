/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:03:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/06 18:13:04 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

class Bureaucrat
{
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat();
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();
        Bureaucrat & operator=(Bureaucrat const & src);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        std::ostream &operator<<(std::ostream & flux, Bureaucrat const & src);
        void print_object(std::ostream & flux) const;
    protected:

    private:
        std::string const _name;
        int _grade;
};

#endif