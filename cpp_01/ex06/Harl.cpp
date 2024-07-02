/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:59:48 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 16:01:26 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(int level)
{
    switch (level)
    {
        case 1:
            debug();
            break;
        case 2:
            info();
            break;
        case 3:
            warning();
            break;
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    return ;
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl; 
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
    info();
    return;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
    warning();
    return ;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
    error();
    return ;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}