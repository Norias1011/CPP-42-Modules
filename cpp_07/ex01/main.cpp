/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:04:24 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/24 14:07:14 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(int const &i)
{
    std::cout << i << std::endl;
}

void times2(int const &i)
{
    std::cout << i * 2 << std::endl;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    std::cout << "Printing array:" << std::endl;
    iter(array, 5, print);
    std::cout << "Printing array * 2:" << std::endl;
    iter(array, 5, times2);
    return 0;
}