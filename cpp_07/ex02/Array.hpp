/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:11:36 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/24 14:37:52 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <iomanip>

template<typename T>
class Array
{
    private:
        T *_array;
        size_t _size;
    public:
        Array();
        Array(size_t n);
        Array(Array const &other);
        ~Array();
        Array &operator=(Array const &other);
        T &operator[](size_t index);
        size_t size() const;
};

# include "Array.class.tpp"

#endif