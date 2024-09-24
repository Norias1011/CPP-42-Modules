/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:11:33 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/24 14:43:45 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> array(5);
    for (size_t i = 0; i < array.size(); i++)
        array[i] = i;
    for (size_t i = 0; i < array.size(); i++)
        std::cout << array[i] << std::endl;
    try
    {
        array[7] = 42;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}