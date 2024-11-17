/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:09:18 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/25 12:12:49 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) 
{
    _v.reserve(n);
}

Span::Span(Span const & src)
{
    *this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & src)
{
    if (this != &src)
    {
        _n = src._n;
        _v = src._v;
    }
    return (*this);
}

void Span::addNumber(int n)
{
    if (_v.size() >= _n)
        throw SpanFullException();
    _v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_v.size() + std::distance(begin, end) > _n)
        throw SpanFullException();
    _v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw SpanNotEnoughValuesException();
    std::sort(_v.begin(), _v.end());
    int min = _v[1] - _v[0];
    for (size_t i = 2; i < _v.size(); i++)
    {
        if (_v[i] - _v[i - 1] < min)
            min = _v[i] - _v[i - 1];
    }
    return (min);
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw SpanNotEnoughValuesException();
    std::sort(_v.begin(), _v.end());
    return (_v[_v.size() - 1] - _v[0]);
}

