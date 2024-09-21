/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:16 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/21 16:01:58 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
        void execute(Bureaucrat const & executor) const;
        AForm *clone(std::string target);
    private:
        std::string _target;
};

#endif