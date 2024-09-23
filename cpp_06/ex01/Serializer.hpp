/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:00:27 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 17:16:20 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    public:
        Serializer();
        virtual ~Serializer() = 0;
        Serializer(Serializer const& src);
        Serializer& operator=(Serializer const& rhs);
        static uintptr_t serialize(t_data* ptr);
        static t_data* deserialize(uintptr_t raw);
};

#endif