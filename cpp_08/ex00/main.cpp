/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:33:12 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/24 16:36:36 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int		main(void)
{
    std::vector<int>	v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    try
    {
        std::cout << easyfind(v, 5) << std::endl;
        std::cout << easyfind(v, 42) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found" << std::endl;
    }
    return 0;
}