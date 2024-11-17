/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:51 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/17 17:55:26 by akinzeli         ###   ########.fr       */
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

void PmergeMe::sortVector(std::vector<int>& data)
{
    if (data.size() <= 1) return;

    for (size_t i = 1; i < data.size(); ++i) 
    {
        int key = data[i];
        size_t j = i;
        while (j > 0 && data[j - 1] > key) 
        {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = key;
    }
}

void PmergeMe::sortDeque(std::deque<int>& data)
{
    if (data.size() <= 1) return;

    for (size_t i = 1; i < data.size(); ++i) 
    {
        int key = data[i];
        size_t j = i;
        while (j > 0 && data[j - 1] > key) 
        {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = key;
    }
}