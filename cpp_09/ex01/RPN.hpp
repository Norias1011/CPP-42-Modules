/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:03:26 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/27 16:31:48 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>

class RPN
{
    public:
        RPN(std::string expression);
        ~RPN();
        void calculate();
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        void push_to_stack(char value);
        int add(int a, int b);
        int sub(int a, int b);
        int mul(int a, int b);
        int div(int a, int b);
        
    private:
        int (RPN::*_operations[4])(int, int);
        std::string _expression;
        std::stack<int> _stack;
        RPN();
};



#endif