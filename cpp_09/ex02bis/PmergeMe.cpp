/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:51 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/23 16:25:41 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
}

PmergeMe::~PmergeMe() 
{
}

PmergeMe::PmergeMe(PmergeMe const & src) 
{
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) 
{
    (void)rhs;
    return *this;
}

/***************************** TEMPLATE FUNCTIONS ************************ */

template <typename Container>
void PmergeMe::merge(Container &array, int begin, int mid, int end)
{
    size_t leftArrayIndex;
    size_t rightArrayIndex;
    size_t mergedArrayIndex;

    Container leftArray(array.begin() + begin, array.begin() + mid + 1);
    Container rightArray(array.begin() + mid + 1, array.begin() + end + 1);

    leftArrayIndex = 0;
    rightArrayIndex = 0;
    mergedArrayIndex = begin;

    while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
    {
        if (leftArray[leftArrayIndex].first < rightArray[rightArrayIndex].first)
        {
            array[mergedArrayIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        }
        else
        {
            array[mergedArrayIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }
        mergedArrayIndex++;
    }
    while (leftArrayIndex < leftArray.size())
    {
        array[mergedArrayIndex] = leftArray[leftArrayIndex];
        leftArrayIndex++;
        mergedArrayIndex++;
    }
    while (rightArrayIndex < rightArray.size())
    {
        array[mergedArrayIndex] = rightArray[rightArrayIndex];
        rightArrayIndex++;
        mergedArrayIndex++;
    }
}

template <typename Container>
void PmergeMe::mergeSort(Container &array, int begin, int end)
{
    int mid;

    if (begin >= end)
        return;
    mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

template <typename Container>
int PmergeMe::binarySearch(Container &array, int target, int begin, int end)
{
    int mid;

    while (begin <= end)
    {
        mid = begin + (end - begin) / 2;
        if (target == array.at(mid))
            return mid;
        else if (target < array.at(mid))
            end = mid - 1;
        else
            begin = mid + 1;
    }
    if (target > array.at(mid))
        return mid + 1;
    else
        return mid;
}


/***************************** VECTORS FUNCTIONS ************************* */

void PmergeMe::mergeInsertSortVector(char *av[])
{
    this->getFullNumbersV(av);

    if (this->vec.size() == 1)
        this->mainChainv.push_back(this->vec.at(0));
    else
    {
        this->createVectorPair();
        this->sortVectorPairs();
        this->mergeSort(this->vecPairs, 0, this->vecPairs.size() - 1);
        this->createMainChainPendVector();
        this->InsertSortVector();
    }
}


void PmergeMe::getFullNumbersV(char *av[])
{
    int i;
    char *ptr;

    i = 1;
    int num;
    while (av[i])
    {
        if (av[i][0] == '\0')
            throw(PmergeMe::exception());
        num = strtol(av[i], &ptr, 10);
        if (*ptr != '\0' || num < 0)
            throw(PmergeMe::exception());
        this->vec.push_back(num);
        i++;
    }
}


void PmergeMe::createVectorPair()
{
    int size;
    unsigned int i;

    size = this->vec.size() / 2;
    i = 0;
    while (size != 0)
    {
        this->vecPairs.push_back(std::make_pair(this->vec[i], this->vec[i + 1]));
        i += 2;
        size--;
    }
}

void PmergeMe::sortVectorPairs()
{
    unsigned int i;
    int tmp;

    i = 0;
    while (i < this->vecPairs.size())
    {
        if (this->vecPairs[i].first < this->vecPairs[i].second)
        {
            tmp = this->vecPairs[i].first;
            this->vecPairs[i].first = this->vecPairs[i].second;
            this->vecPairs[i].second = tmp;
        }
        i++;
    }
}

void PmergeMe::createMainChainPendVector()
{
    size_t i;

    mainChainv.push_back(this->vecPairs.at(0).second);

    i = 0;
    while (i < this->vecPairs.size())
    {
        mainChainv.push_back(this->vecPairs.at(i).first);
        pendv.push_back(this->vecPairs.at(i).second);
        i++;
    }
}

void PmergeMe::JacobInsertVector()
{
    size_t size;
    size_t jacobIndex;
    int index;

    size = this->pendv.size();
    index = 3;

    while ((jacobIndex = jacobsThalV(index)) < size - 1)
    {
        this->jacobsthalv.push_back(jacobIndex);
        index++;
    }
}

int PmergeMe::jacobsThalV(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsThalV(n - 1) + 2 * jacobsThalV(n - 2);
}

void PmergeMe::generatePositionsVector()
{
    size_t val;
    size_t pos;
    size_t lastPos;
    size_t i;

    if (this->pendv.size() == 0)
        return;
    this->JacobInsertVector();
    lastPos = 1;
    val = 1;
    i = 0;
    while (i < this->jacobsthalv.size())
    {
        val = this->jacobsthalv.at(i);
        this->positionsv.push_back(val);
        pos = val - 1;
        while (pos > lastPos)
        {
            this->positionsv.push_back(pos);
            pos--;
        }
        lastPos = val;
        i++;
    }
    while (val++ < this->pendv.size())
        this->positionsv.push_back(val);
}

void PmergeMe::InsertSortVector()
{
    std::vector<int>::iterator it;
    int target;
    size_t endPos;
    size_t addedCount;
    size_t pos;

    this->generatePositionsVector();
    addedCount = 0;

    for (it = this->positionsv.begin(); it < this->positionsv.end(); it++)
    {
        target = this->pendv.at(*it - 1);
        endPos = *it + addedCount;
        pos = this->binarySearch(this->mainChainv, target, 0, endPos);
        this->mainChainv.insert(this->mainChainv.begin() + pos, target);
        addedCount++;
    }
    if (this->vec.size() % 2 != 0)
    {
        target = this->vec.at(this->vec.size() - 1);
        pos = this->binarySearch(this->mainChainv, target, 0, this->mainChainv.size() - 1);
        this->mainChainv.insert(this->mainChainv.begin() + pos, target);
    }
}

/*******************************  DEQUE FUNCTIONS  ***********************/

void PmergeMe::mergeInsertSortDeque(char *av[])
{
    this->getFullNumbersD(av);

    if (this->deq.size() == 1)
        this->mainChaind.push_back(this->deq.at(0));
    else
    {
        this->createDequePair();
        this->sortDequePairs();
        this->mergeSort(this->deqPairs, 0, this->deqPairs.size() - 1);
        this->createMainChainPendDeque();
        this->InsertSortDeque();
    }
}

void PmergeMe::getFullNumbersD(char *av[])
{
    int i;
    char *ptr;

    i = 1;
    int num;
    while (av[i])
    {
        if (av[i][0] == '\0')
            throw(PmergeMe::exception());
        num = strtol(av[i], &ptr, 10);
        if (*ptr != '\0' || num < 0)
            throw(PmergeMe::exception());
        this->deq.push_back(num);
        i++;
    }
}

void PmergeMe::createDequePair()
{
    int size;
    unsigned int i;

    size = this->deq.size() / 2;
    i = 0;
    while (size != 0)
    {
        this->deqPairs.push_back(std::make_pair(this->deq[i], this->deq[i + 1]));
        i += 2;
        size--;
    }
}

void PmergeMe::sortDequePairs()
{
    unsigned int i;
    int tmp;

    i = 0;
    while (i < this->deqPairs.size())
    {
        if (this->deqPairs[i].first < this->deqPairs[i].second)
        {
            tmp = this->deqPairs[i].first;
            this->deqPairs[i].first = this->deqPairs[i].second;
            this->deqPairs[i].second = tmp;
        }
        i++;
    }
}

void PmergeMe::createMainChainPendDeque()
{
    size_t i;

    mainChaind.push_back(this->deqPairs.at(0).second);

    i = 0;
    while (i < this->deqPairs.size())
    {
        mainChaind.push_back(this->deqPairs.at(i).first);
        pendd.push_back(this->deqPairs.at(i).second);
        i++;
    }
}

void PmergeMe::JacobInsertDeque()
{
    size_t size;
    size_t jacobIndex;
    int index;

    size = this->pendd.size();
    index = 3;

    while ((jacobIndex = jacobsThalD(index)) < size - 1)
    {
        this->jacobsthald.push_back(jacobIndex);
        index++;
    }
}

int PmergeMe::jacobsThalD(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsThalD(n - 1) + 2 * jacobsThalD(n - 2);
}

void PmergeMe::generatePositionsDeque()
{
    size_t val;
    size_t pos;
    size_t lastPos;
    size_t i;

    if (this->pendd.size() == 0)
        return;
    this->JacobInsertDeque();
    lastPos = 1;
    val = 1;
    i = 0;
    while (i < this->jacobsthald.size())
    {
        val = this->jacobsthald.at(i);
        this->positionsd.push_back(val);
        pos = val - 1;
        while (pos > lastPos)
        {
            this->positionsd.push_back(pos);
            pos--;
        }
        lastPos = val;
        i++;
    }
    while (val++ < this->pendd.size())
        this->positionsd.push_back(val);
}

void PmergeMe::InsertSortDeque()
{
    std::deque<int>::iterator it;
    int target;
    size_t endPos;
    size_t addedCount;
    size_t pos;

    this->generatePositionsDeque();
    addedCount = 0;

    for (it = this->positionsd.begin(); it < this->positionsd.end(); it++)
    {
        target = this->pendd.at(*it - 1);
        endPos = *it + addedCount;
        pos = this->binarySearch(this->mainChaind, target, 0, endPos);
        this->mainChaind.insert(this->mainChaind.begin() + pos, target);
        addedCount++;
    }
    if (this->deq.size() % 2 != 0)
    {
        target = this->deq.at(this->deq.size() - 1);
        pos = this->binarySearch(this->mainChaind, target, 0, this->mainChaind.size() - 1);
        this->mainChaind.insert(this->mainChaind.begin() + pos, target);
    }
}


