/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:06:04 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/01 17:44:18 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    std::ifstream read_file;
    std::ofstream write_file;
    if (ac != 4)
    {
        std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
        return (1);
    }
    
}