/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:55 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/18 23:35:00 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: At least one integer argument is required." << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i) 
    {
        for (size_t j = 0; j < strlen(argv[i]); ++j) 
        {
            if (!std::isdigit(argv[i][j])) 
            {
                std::cerr << "Error: Invalid argument." << std::endl;
                return 1;
            }
        }
    }

    PmergeMe pmergeMe(argc, argv);

    std::clock_t start_vec = std::clock();
    pmergeMe.mergeInsertSortVector(pmergeMe.getVec());
    std::clock_t end_vec = std::clock();
    double time_vec = 1000.0 * (end_vec - start_vec) / CLOCKS_PER_SEC;

    std::clock_t start_deq = std::clock();
    pmergeMe.mergeInsertSortDeque(pmergeMe.getDeq());
    std::clock_t end_deq = std::clock();
    double time_deq = 1000.0 * (end_deq - start_deq) / CLOCKS_PER_SEC;

    std::cout << std::endl << "After (vector): ";
    pmergeMe.printResult(pmergeMe.getVec());
    std::cout << "After (deque): ";
    pmergeMe.printResult(pmergeMe.getDeq());

    std::cout << "Time to process with std::vector: " << time_vec << " ms" << std::endl;
    std::cout << "Time to process with std::deque: " << time_deq << " ms" << std::endl;

    return 0;
}