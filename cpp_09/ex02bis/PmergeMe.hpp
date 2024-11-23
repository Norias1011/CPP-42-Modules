/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:25:48 by akinzeli          #+#    #+#             */
/*   Updated: 2024/11/23 16:30:42 by akinzeli         ###   ########.fr       */
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
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);

        template <typename Container>
        void printResult(Container & container) {
            for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        std::vector<int> & getVec() { return this->vec; };
        std::deque<int> & getDeq() { return this->deq; };
        std::vector<int> & getMainChainV() { return this->mainChainv; };
        std::deque<int> & getMainChainD() { return this->mainChaind; };

        void getFullNumbersV(char *av[]);
        void getFullNumbersD(char *av[]);
        void createVectorPair();
        void createDequePair();
        void sortVectorPairs();
        void sortDequePairs();

        template <typename Container>
        void merge(Container &array, int begin, int mid, int end);

        template <typename Container>
        void mergeSort(Container &array, int begin, int end);

        template <typename Container>
        int binarySearch(Container &array, int target, int begin, int end);

        void createMainChainPendVector();
        void createMainChainPendDeque();
        void JacobInsertVector();
        void JacobInsertDeque();
        int jacobsThalV(int n);
        int jacobsThalD(int n);
        void generatePositionsVector();
        void generatePositionsDeque();
        void InsertSortVector();
        void InsertSortDeque();
        
        void mergeInsertSortVector(char *av[]);
        void mergeInsertSortDeque(char *av[]);



        class exception : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Error";
                }
        };

    private:
        std::vector<int> vec;
        std::deque<int> deq;

        std::vector<int> positionsv;
        std::vector<std::pair<int, int> > vecPairs;
        std::vector<int> mainChainv;
        std::vector<int> pendv;
        std::vector<int> jacobsthalv;

        std::deque<int> positionsd;
        std::deque<std::pair<int, int> > deqPairs;
        std::deque<int> mainChaind;
        std::deque<int> pendd;
        std::deque<int> jacobsthald;

};

#endif