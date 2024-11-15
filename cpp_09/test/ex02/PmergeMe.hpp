
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>

struct Pair{
	int value;
	Pair *near;
	Pair *next;
	Pair(int v) : value(v), near(NULL), next(NULL)
	{}
	Pair(int v, Pair *near, Pair *next) : value(v), near(near), next(next)
	{}
	Pair(int v, Pair *next) : value(v), near(NULL), next(next)
	{}
};

class PmergeMe
{
private:
	std::vector<int> input;
	PmergeMe();
	std::vector<Pair *> mainVector;
	std::deque<Pair *> mainDeque;
	std::vector<Pair *>gc;
	bool returnStatus;
public:
	PmergeMe(int argc, char **argv, bool isVec);
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	void printVector(std::vector<std::pair<int, int> > &pairs);
	void printPairs(std::vector<Pair *> &pairs);
	void printSinglePairs(std::vector<Pair *> &pairs);
	void printReslut();
	void sort(std::vector<std::pair<int, int> > &pairs);
	void binaryInsert(Pair *value);
	std::vector<Pair *> sort(std::vector<Pair *> &pairs);
	Pair *makePair(int left, int right);
	int jacobsthal(bool reset, int max);
	int jacobsthalRecursive(int index);
	void DBinaryInsert(Pair *value);
	unsigned long int getInputSize();
	bool &getReturnStatus();
	std::deque<Pair *> DSort(std::deque<Pair *> &pairs);
};

std::ostream &operator<<(std::ostream &out, const Pair& pair);


#endif
