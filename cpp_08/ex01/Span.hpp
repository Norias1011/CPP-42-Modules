/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:02:14 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/25 12:09:01 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
    public:
        Span(unsigned int n);
        Span(Span const & src);
        ~Span();
        Span & operator=(Span const & src);
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();


        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Span is full");
                }
        };

        class SpanNotEnoughValuesException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Not enough values to calculate span");
                }
        };

    private:
        unsigned int    _n;
        std::vector<int>    _v;
};

#endif