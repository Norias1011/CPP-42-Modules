/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:21:39 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 17:34:55 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Base
{
    public:
        virtual ~Base() = 0;
};

Base * generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference(Base & p);

#endif