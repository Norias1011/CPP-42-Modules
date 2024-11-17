/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:03:31 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/17 16:15:45 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string expression) : _expression(expression)
{
    this->_operations[0] = &RPN::add;
    this->_operations[1] = &RPN::sub;
    this->_operations[2] = &RPN::mul;
    this->_operations[3] = &RPN::div;
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &other)
{
    *this = other;
}

RPN &RPN::operator=(RPN const &other)
{
    if (this != &other)
    {
        this->_expression = other._expression;
        this->_stack = other._stack;
    }
    return *this;
}

void RPN::push_to_stack(char value)
{
    if (value > '9' || value < '0')
    {
        std::cout << "Invalid expression" << std::endl;
        exit(1);
    }
    this->_stack.push(value - '0');
}

void RPN::calculate()
{
    if (this->_expression.empty())
    {
        std::cout << "Empty expression : fill it with some calculation" << std::endl;
        return ;
    }
    std::string operators = "+-*/";
    try {
        for(size_t i = 0; i < this->_expression.length(); i++)
        {
            if (this->_expression[i] >= '0' && this->_expression[i] <= '9')
                this->push_to_stack(this->_expression[i]);
            else if (this->_expression[i] == '+' || this->_expression[i] == '-' || this->_expression[i] == '*' || this->_expression[i] == '/')
            {
                if (this->_stack.size() < 2)
                    throw std::invalid_argument("Invalid expression");
                int b = this->_stack.top();
                this->_stack.pop();
                int a = this->_stack.top();
                this->_stack.pop();
                for (size_t j = 0; j < operators.length(); j++)
                {
                    if (this->_expression[i] == operators[j])
                    {
                        this->_stack.push((this->*_operations[j])(a, b));
                        break;
                    }
                }
            }
            else if (this->_expression[i] != ' ')
                throw std::invalid_argument("Invalid expression");
        }
        if (this->_stack.size() != 1)
            throw std::invalid_argument("Invalid expression");
        else
            std::cout << this->_stack.top() << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

int RPN::add(int a, int b)
{
    return a + b;
}

int RPN::sub(int a, int b)
{
    return a - b;
}

int RPN::mul(int a, int b)
{
    return a * b;
}

int RPN::div(int a, int b)
{
    if (b == 0)
        throw std::invalid_argument("Division by zero");
    return a / b;
}