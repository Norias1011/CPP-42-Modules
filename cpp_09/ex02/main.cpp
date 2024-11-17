/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:55 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/17 17:55:27 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: At least one integer argument is required." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe(argc, argv);

    double timeVec = pmergeMe.measureTime(&PmergeMe::sortVector, pmergeMe.getVec());
    double timeDeq = pmergeMe.measureTime(&PmergeMe::sortDeque, pmergeMe.getDeq());

    std::cout << "After (vector): ";
    pmergeMe.printResult(pmergeMe.getVec());
    std::cout << "After (deque): ";
    pmergeMe.printResult(pmergeMe.getDeq());

    std::cout << "Time to process with std::vector: " << timeVec << " s" << std::endl;
    std::cout << "Time to process with std::deque: " << timeDeq << " s" << std::endl;

    return 0;
}