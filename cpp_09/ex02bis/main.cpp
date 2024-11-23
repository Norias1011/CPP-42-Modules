/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:55 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/23 16:31:15 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./pmergeMe [numbers]" << std::endl;
        return 1;
    }

    PmergeMe pmvec;
    PmergeMe pmdeq;

    try
    {
        std::clock_t start_vec = std::clock();
        pmvec.mergeInsertSortVector(argv);
        std::clock_t end_vec = std::clock();
        double time_vec = 1000.0 * (end_vec - start_vec) / CLOCKS_PER_SEC;

        std::clock_t start_deq = std::clock();
        pmdeq.mergeInsertSortDeque(argv);
        std::clock_t end_deq = std::clock();
        double time_deq = 1000.0 * (end_deq - start_deq) / CLOCKS_PER_SEC;

        std::cout << "Before: ";
        pmvec.printResult(pmvec.getVec());

        std::cout << "After (vector): ";
        pmvec.printResult(pmvec.getMainChainV());

        std::cout << "After (deque): ";
        pmdeq.printResult(pmdeq.getMainChainD());

        std::cout << "Time to process with std::vector: " << time_vec << " ms" << std::endl;
        std::cout << "Time to process with std::deque: " << time_deq << " ms" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    /*PmergeMe pmergeMe(argc, argv);

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
    std::cout << "Time to process with std::deque: " << time_deq << " ms" << std::endl;*/

    return 0;
}