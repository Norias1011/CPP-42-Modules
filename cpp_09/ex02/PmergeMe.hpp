/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:48 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/17 17:48:45 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>

class PmergeMe {
    public:
        PmergeMe(int argc, char* argv[]);
        ~PmergeMe();
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        void printReslut();
        void sortVector(std::vector<int> & vec);
        void sortDeque(std::deque<int> & deq);

        template <typename Func, typename Container>
        double measureTime(Func func, Container & container) {
            std::clock_t start = std::clock();
            (this->*func)(container);
            std::clock_t end = std::clock();
            return static_cast<double>(end - start) / CLOCKS_PER_SEC;
        }

        template <typename Container>
        void printResult(Container & container) {
            for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        std::vector<int> & getVec() { return this->vec; };
        std::deque<int> & getDeq() { return this->deq; };

    private:
        std::vector<int> vec;
        std::deque<int> deq;
};

#endif