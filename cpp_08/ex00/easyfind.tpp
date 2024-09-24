/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:36:00 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/24 16:53:54 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int		easyfind(T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    return *it;
}