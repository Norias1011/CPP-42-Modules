#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	RPN rpn;
	if (argc < 2)
	{
		std::cout << "Usage: ./RPN [expresison]" << std::endl;
		return 1;
	}
	rpn.calculate((std::string)argv[1]);
}