/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:00:24 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 17:06:55 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(Serializer const& src)
{
    *this = src;
}

Serializer& Serializer::operator=(Serializer const& rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

uintptr_t Serializer::serialize(t_data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

t_data* Serializer::deserialize(uintptr_t raw)
{
    t_data* ptr = reinterpret_cast<t_data*>(raw);
    return ptr;
}