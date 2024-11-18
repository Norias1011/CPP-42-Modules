/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:48 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/18 23:35:12 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <cstring>

class PmergeMe {
    public:
        PmergeMe(int argc, char* argv[]);
        ~PmergeMe();
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        void mergeInsertSortVector(std::vector<int>& arr);
        void mergeInsertSortDeque(std::deque<int>& arr);

        void mergeInsertSortVectorHelper(std::vector<int>& arr, int l, int r);
        void mergeVector(std::vector<int>& arr, int l, int m, int r);

        void mergeInsertSortDequeHelper(std::deque<int>& arr, int l, int r);
        void mergeDeque(std::deque<int>& arr, int l, int m, int r);

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