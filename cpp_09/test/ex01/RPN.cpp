
#include "RPN.hpp"


RPN::RPN()
{
	;
}

RPN::~RPN()
{
	;
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this == &copy)
		return *this;
	//do some stuff
	return *this;
}

void RPN::operate(char c)
{
	double i = this->stack.top();
	this->stack.pop();
	double j = this->stack.top();
	this->stack.pop();
	switch (c)
	{
		case '+':
			this->stack.push(j + i);
			break;
		case '-':
			this->stack.push(j - i);
			break;
		case '*':
			this->stack.push(j * i);
			break;
		case '/':
			this->stack.push(j / i);
			break;
		default:
			break;
	}
}

void RPN::printStack()
{
	std::stack<double> copy = this->stack;
	std::cout << "--- Stack ---" << std::endl;
	while (copy.size() > 0)
	{
		std::cout << copy.top() << std::endl;
		copy.pop();
	}
	std::cout << "--- End ---" << std::endl;
}

void RPN::calculate(std::string str)
{
	if (str.empty())
	{
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}
	for (int i = 0; i < (int)str.size(); i++)
	{
		if(isspace(str[i]))
			continue;
		else if (isdigit(str[i]))
		{
			this->stack.push(str[i] - '0');
		}
		else if (this->stack.size() < 2)
		{
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			operate(str[i]);
		}
		else
		{
			std::cout << "Error: Invalid input" << std::endl;
			return;
		}
	}
	if (this->stack.size() == 1)
		std::cout << this->stack.top() << std::endl;
	else
		std::cout << "Error: Invalid input." << std::endl;
}
