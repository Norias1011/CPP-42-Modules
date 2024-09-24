/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:22:10 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/24 11:56:34 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;

    std::cout << "***** Before swap *****" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "***** After swap *****" << std::endl;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "***** Before swap *****" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "***** After swap *****" << std::endl;

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}