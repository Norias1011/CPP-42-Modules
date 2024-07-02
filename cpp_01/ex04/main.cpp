/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:06:04 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 14:22:39 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./sed <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string line;
	std::string buff;
	std::string av1(av[1]);
	std::ifstream read_file(av[1]);
	std::ofstream write_file(av1 + ".replace");
	std::size_t position;
	std::size_t av2size;
	std::string av2(av[2]);
	std::string av3(av[3]);
	av2size = av2.length();
	if (read_file.is_open())
	{
		while (getline(read_file, line))
		{
			if (write_file.is_open())
			{
				while (line.find(av2) != std::string::npos)
				{
					position = line.find(av2);
					if (position != std::string::npos)
					{
						line.erase(position, av2size);
						line.insert(position, av3);
					}
				}
				buff.append(line);
				buff += "\n";
			}
		}
	}
	if (write_file.is_open())
	{
		write_file << buff;
	}
	read_file.close();
	write_file.close();
	return (0);
}