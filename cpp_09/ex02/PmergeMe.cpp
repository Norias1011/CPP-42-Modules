/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:51 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/18 23:34:53 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        this->vec.push_back(num);
        this->deq.push_back(num);
    }
    std::cout << "Before: ";
    this->printResult(this->vec);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & src) {
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
    if (this != &rhs) {
        this->vec = rhs.vec;
        this->deq = rhs.deq;
    }
    return *this;
}


void PmergeMe::mergeVector(std::vector<int>& arr, int l, int m, int r) 
{
    std::vector<int> leftArr(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> rightArr(arr.begin() + m + 1, arr.begin() + r + 1);

    size_t i = 0, j = 0;
    int k = l;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}


void PmergeMe::mergeInsertSortVectorHelper(std::vector<int>& arr, int l, int r) 
{
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeInsertSortVectorHelper(arr, l, mid);
        mergeInsertSortVectorHelper(arr, mid + 1, r);
        mergeVector(arr, l, mid, r);
    }
}


void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) 
{
    mergeInsertSortVectorHelper(arr, 0, arr.size() - 1);
}


void PmergeMe::mergeDeque(std::deque<int>& arr, int l, int m, int r) 
{
    std::deque<int> leftArr(arr.begin() + l, arr.begin() + m + 1);
    std::deque<int> rightArr(arr.begin() + m + 1, arr.begin() + r + 1);

    size_t i = 0, j = 0;
    int k = l;

    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }
}


void PmergeMe::mergeInsertSortDequeHelper(std::deque<int>& arr, int l, int r) 
{
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeInsertSortDequeHelper(arr, l, mid);
        mergeInsertSortDequeHelper(arr, mid + 1, r);
        mergeDeque(arr, l, mid, r);
    }
}


void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) 
{
    mergeInsertSortDequeHelper(arr, 0, arr.size() - 1);
}
