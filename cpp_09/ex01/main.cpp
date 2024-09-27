/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:03:35 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/27 13:25:23 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    rpn.calculate();
    return 0;
}