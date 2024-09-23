/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:23:05 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/23 17:27:03 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;
    return (0);
}