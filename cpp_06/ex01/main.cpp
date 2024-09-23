/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:00:30 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 17:08:04 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    t_data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

    std::cout << "********** Before Serialization **********" << std::endl;

    std::cout << "s1: " << data.s1 << std::endl;
    std::cout << "n: " << data.n << std::endl;
    std::cout << "s2: " << data.s2 << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    t_data* ptr = Serializer::deserialize(raw);

    std::cout << "********** After Serialization **********" << std::endl;

    std::cout << "s1: " << ptr->s1 << std::endl;
    std::cout << "n: " << ptr->n << std::endl;
    std::cout << "s2: " << ptr->s2 << std::endl;

    return 0;
}