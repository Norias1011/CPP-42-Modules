
#include "PmergeMe.hpp"


// Test the Ford-Johnson sort
//./PmergeMe $(shuf -i 0-3001 -n 3000)
int main(int argc, char **argv) {

	clock_t startVec = clock();
	PmergeMe vec(argc, argv, true);
	clock_t endVec = clock();
	if (vec.getReturnStatus())
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	clock_t startDeque = clock();
	PmergeMe deque(argc, argv, false);
	clock_t endDeque = clock();
	if (deque.getReturnStatus())
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	vec.printReslut();
	std::cout << "Time to process a range of " << vec.getInputSize() << " elements with std::vector : " << std::fixed << double(endVec - startVec) / CLOCKS_PER_SEC << " s" << std::endl;
	std::cout << "Time to process a range of " << deque.getInputSize() << " elements with std::deque  : " << std::fixed << double(endDeque - startDeque) / CLOCKS_PER_SEC << " s" << std::endl;


	return 0;
}