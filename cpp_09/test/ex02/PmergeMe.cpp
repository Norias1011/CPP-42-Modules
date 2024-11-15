
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char **argv, bool isVec)
{
	if (argc < 2)
	{
		returnStatus = true;
		return;
	}
	std::vector<Pair *> vectorPairs;
	std::deque<Pair *> dequePairs;

	for (int i = 1; i < argc; i++)
	{
		int j = std::atoi(argv[i]);
		//std::cout << "added : " << j << std::endl;
		if (j < 0)
		{
			returnStatus = true;
			return;
		}
		else if (std::find(input.begin(), input.end(), j) != input.end())
		{
			std::cout << "No duplicate numbers" << std::endl;
			returnStatus = true;
			return;
		}
		input.push_back(j);
	}

	if (input.size() == 1)
	{
		Pair *newPair = new Pair(input[0]);
		gc.push_back(newPair);
		if (isVec)
			mainVector.push_back(newPair);
		else
			mainDeque.push_back(newPair);
		return;
	}

	for (unsigned long int i = 0; i < input.size() / 2; i++)
	{
		if (isVec)
			vectorPairs.push_back(makePair(input[i * 2], input[i * 2 + 1]));
		else
			dequePairs.push_back(makePair(input[i * 2], input[i * 2 + 1]));
	}
	jacobsthal(true, 111);
	if (isVec)
	{
		sort(vectorPairs);
		if (input.size() % 2 == 1)
		{
			Pair *newPair = new Pair(input[input.size() - 1]);
			gc.push_back(newPair);
			binaryInsert(newPair);
		}
	}
	else
	{
		DSort(dequePairs);
		if (input.size() % 2 == 1)
		{
			Pair *newPair = new Pair(input[input.size() - 1]);
			gc.push_back(newPair);
			DBinaryInsert(newPair);
		}
	}
	returnStatus = false;
}

Pair *PmergeMe::makePair(int left, int right)
{
	Pair *leftPair = new Pair(left);
	Pair *rightPair = new Pair(right);

	leftPair->near = rightPair;
	rightPair->near = leftPair;
	gc.push_back(leftPair);
	gc.push_back(rightPair);
	return rightPair;
}

void PmergeMe::printPairs(std::vector<Pair *> &pairs)
{
	bool hasNext = true;
	int next = 0;

	while (hasNext)
	{
		std::cout << "Level " << next + 1 << std::endl;
		for (unsigned long int i = 0; i < pairs.size(); ++i)
		{
			Pair *current = pairs[i];
			for (int j = 0; j < next; ++j)
			{
				if (!current->next)
				{
					hasNext = false;
					break;
				}
				current = current->next;
			}
			if (hasNext)
				std::cout << "(" << current->near->value << ", " << current->value << ") ";
		}
		next++;
		std::cout << std::endl;
	}
//	std::cout << std::endl;

}

void PmergeMe::printReslut()
{
	std::cout << "Before:\t";
	for (unsigned long int i = 0; i < input.size(); ++i)
	{
		std::cout << input[i];
		if (i < input.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "After:\t";
	for (unsigned long int i = 0; i < mainVector.size(); ++i)
	{
		Pair *current = mainVector[i];
		std::cout << current->value;
		if (i < mainVector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printSinglePairs(std::vector<Pair *> &pairs)
{
	for (unsigned long int i = 0; i < pairs.size(); ++i)
	{
		Pair *current = pairs[i];
		std::cout << *current;
		if (i < pairs.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int PmergeMe::jacobsthal(bool reset, int max)
{
	static int jIndex = 2;
	static int jValue = 2;
	static int jOldValue = 0;

	if (reset)
	{
		jIndex = 2;
		jValue = 2;
		jOldValue = 0;
		return jValue;
	}
	if (max < jOldValue)
		return -1;

	do
	{
		jValue--;
		if (jValue <= jOldValue)
		{
			jIndex++;
			jOldValue = jacobsthalRecursive(jIndex - 1);
			jValue = jacobsthalRecursive(jIndex);
		}
	} while (jValue > max);

	return jValue;
}

int PmergeMe::jacobsthalRecursive(int index)
{
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;

	return jacobsthalRecursive(index - 1) + 2 * jacobsthalRecursive(index - 2);
}

void PmergeMe::binaryInsert(Pair *value)
{
	int left = 0;
	int right = mainVector.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (mainVector[mid]->value < value->value)
			left = mid + 1;
		else
			right = mid;
	}
	mainVector.insert(mainVector.begin() + left, value);
}

std::vector<Pair *> PmergeMe::sort(std::vector<Pair *> &pairs)
{
	std::vector<Pair *> newPairs;
	std::vector<Pair *> returnedPairs;
	std::vector<Pair *> sortedPairs;
	bool isOdd = false;
	Pair *rest = NULL;

	if (pairs[pairs.size() - 1]->near == NULL)
	{
		isOdd = true;
		rest = pairs[pairs.size() - 1];
	}
	for (unsigned long int i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i]->near && pairs[i]->value < pairs[i]->near->value)
		{
			pairs[i] = pairs[i]->near;
			//std::cout << "[i] = " << *pairs[i] << " | near = " << *pairs[i]->near << std::endl;
		}
	}

	for(unsigned long int j = 0; j < pairs.size() / 2; j++)
	{
		if (isOdd && j == pairs.size() / 2 - 1)
		{
			if (pairs.size() % 2 == 0)
			{
				Pair *newRight = new Pair(pairs[j * 2]->value, pairs[j * 2]);
				gc.push_back(newRight);
				newPairs.push_back(newRight);
				continue;
			}

		}
		Pair *newLeft = new Pair(pairs[j * 2]->value, pairs[j * 2]);
		Pair *newRight = new Pair(pairs[j * 2 + 1]->value, pairs[j * 2 + 1]);
		newLeft->near = newRight;
		newRight->near = newLeft;
		gc.push_back(newLeft);
		gc.push_back(newRight);
//		std::cout << "added to newPairs : " << *newRight << std::endl;
//		std::cout << "[newPair] = " << *newRight << " | near = " << *newRight->near << " | near next = " << *newRight->near->next << " | next = " << *newRight->next << std::endl;
		newPairs.push_back(newRight);
	}
	if (pairs.size() % 2 == 1 && pairs[pairs.size() - 1]->near)
	{
		Pair *newRight = new Pair(pairs[pairs.size() - 1]->value, pairs[pairs.size() - 1]);
		gc.push_back(newRight);
		newPairs.push_back(newRight);
//		std::cout << "added to newPairs : " << *newRight << std::endl;
	}
//	printSinglePairs(pairs);
	if (pairs.size() != 1 && !(pairs.size() == 2 && !pairs[1]->near))
	{
		sortedPairs = sort(newPairs);
	}
	else
	{
		mainVector.push_back(pairs[0]->near);
		mainVector.push_back(pairs[0]);
		returnedPairs.push_back(pairs[0]->near->next);
		returnedPairs.push_back(pairs[0]->next);
		if ((pairs.size() == 2 && !pairs[1]->near))
		{
			returnedPairs.push_back(pairs[1]->next);
			binaryInsert(pairs[1]);
		}
//		std::cout << "returned Pairs :" << std::endl;
//		printSinglePairs(returnedPairs);
//		std::cout << "[0] = " << *pairs[0] << " | near = " << *pairs[0]->near << " | near next = " << *pairs[0]->near->next << " | next = " << *pairs[0]->next << std::endl;
		return returnedPairs;
	}

	for(unsigned long int i = 0; i < sortedPairs.size(); i++)
	{
//		std::cout << "pair address = " << sortedPairs[i] << std::endl;
//		std::cout << "pair = " << *sortedPairs[i] << std::endl;
		returnedPairs.push_back(sortedPairs[i]->near->next);
		returnedPairs.push_back(sortedPairs[i]->next);

		if (i > 0)
		{
			int jacob = jacobsthal(false, sortedPairs.size() - 1);
			binaryInsert(sortedPairs[jacob]->near);
		}
		else
			mainVector.insert(mainVector.begin(), sortedPairs[i]->near);
	}
	jacobsthal(true, 0);
	if (isOdd)
	{
		returnedPairs.push_back(rest->next);
		binaryInsert(rest);
	}
	//std::cout << "returned Pairs :" << std::endl;
	//printSinglePairs(returnedPairs);
	return returnedPairs;
}

//deque
void PmergeMe::DBinaryInsert(Pair *value)
{
	int left = 0;
	int right = mainDeque.size();

	while (left < right)
	{
		int mid = left + (right - left) / 2;

		if (mainDeque[mid]->value < value->value)
			left = mid + 1;
		else
			right = mid;
	}
	mainDeque.insert(mainDeque.begin() + left, value);
}

std::deque<Pair *> PmergeMe::DSort(std::deque<Pair *> &pairs)
{
	std::deque<Pair *> newPairs;
	std::deque<Pair *> returnedPairs;
	std::deque<Pair *> sortedPairs;
	bool isOdd = false;
	Pair *rest = NULL;

	if (pairs[pairs.size() - 1]->near == NULL)
	{
		isOdd = true;
		rest = pairs[pairs.size() - 1];
	}
	for (unsigned long int i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i]->near && pairs[i]->value < pairs[i]->near->value)
		{
			pairs[i] = pairs[i]->near;
		}
	}

	for(unsigned long int j = 0; j < pairs.size() / 2; j++)
	{
		if (isOdd && j == pairs.size() / 2 - 1)
		{
			if (pairs.size() % 2 == 0)
			{
				Pair *newRight = new Pair(pairs[j * 2]->value, pairs[j * 2]);
				gc.push_back(newRight);
				newPairs.push_back(newRight);
				continue;
			}
		}
		Pair *newLeft = new Pair(pairs[j * 2]->value, pairs[j * 2]);
		Pair *newRight = new Pair(pairs[j * 2 + 1]->value, pairs[j * 2 + 1]);
		newLeft->near = newRight;
		newRight->near = newLeft;
		gc.push_back(newLeft);
		gc.push_back(newRight);
		newPairs.push_back(newRight);
	}

	if (pairs.size() % 2 == 1 && pairs[pairs.size() - 1]->near)
	{
		Pair *newRight = new Pair(pairs[pairs.size() - 1]->value, pairs[pairs.size() - 1]);
		gc.push_back(newRight);
		newPairs.push_back(newRight);
	}

	if (pairs.size() != 1 && !(pairs.size() == 2 && !pairs[1]->near))

	{
		sortedPairs = DSort(newPairs);
	}
	else
	{
		mainDeque.push_back(pairs[0]->near);
		mainDeque.push_back(pairs[0]);
		returnedPairs.push_back(pairs[0]->near->next);
		returnedPairs.push_back(pairs[0]->next);
		if ((pairs.size() == 2 && !pairs[1]->near))
		{
			returnedPairs.push_back(pairs[1]->next);
			DBinaryInsert(pairs[1]);
		}
//		std::cout << "returned Pairs :" << std::endl;
//		printSinglePairs(returnedPairs);
//		std::cout << "[0] = " << *pairs[0] << " | near = " << *pairs[0]->near << " | near next = " << *pairs[0]->near->next << " | next = " << *pairs[0]->next << std::endl;
		return returnedPairs;
	}

	for(unsigned long int i = 0; i < sortedPairs.size(); i++)
	{
		returnedPairs.push_back(sortedPairs[i]->near->next);
		returnedPairs.push_back(sortedPairs[i]->next);

		if (i > 0)
		{
			int jacob = jacobsthal(false, sortedPairs.size() - 1);
			DBinaryInsert(sortedPairs[jacob]->near);
		}
		else
			mainDeque.insert(mainDeque.begin(), sortedPairs[i]->near);
	}

	jacobsthal(true, 0);

	if (isOdd)
	{
		returnedPairs.push_back(rest->next);
		DBinaryInsert(rest);
	}

	return returnedPairs;
}

unsigned long int PmergeMe::getInputSize()
{
	return input.size();
}

bool &PmergeMe::getReturnStatus()
{
	return returnStatus;
}

std::ostream &operator<<(std::ostream &out, const Pair& pair)
{
	if (!pair.near)
		out << "(NULL, " << pair.value << ")";
	else
		out << "(" << pair.near->value << ", " << pair.value << ")";
	return out;
}

PmergeMe::~PmergeMe()
{
	for (unsigned long int i = 0; i < gc.size(); ++i)
	{
		delete gc[i];
	}
	gc.clear();
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this == &copy)
		return *this;
	//do some stuff
	return *this;
}
