/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:01:15 by akinzeli          #+#    #+#             */
/*   Updated: 2024/06/13 14:51:53 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char *av[])
{
	int i;
	int j;

	i = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				av[i][j] = toupper(av[i][j]);
				std::cout << av[i][j];
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}