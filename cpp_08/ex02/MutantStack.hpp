/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:27:46 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/25 12:35:37 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(MutantStack const &other);
    virtual ~MutantStack();

    MutantStack &operator=(MutantStack const &other);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif