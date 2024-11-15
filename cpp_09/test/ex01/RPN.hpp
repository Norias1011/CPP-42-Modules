
#ifndef CPP09_RPN_HPP
#define CPP09_RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class RPN
{
private:
	std::stack<double> stack;
public:
	RPN();
	~RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	void calculate(std::string str);
	void operate(char c);
	void printStack();
};


#endif
