/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/25 11:46:44 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		int _pair;
		std::vector<int> _vecc;
		std::deque<int> _deqc;
		std::vector<std::pair<int, int> > vec_pair;
		std::deque<std::pair<int, int> > deq_pair;

		void vecPairing();
		void vecCheckPairs();
		void vecCheckPair(int);
		void vecRecursiveSort(size_t base);
		void vecMergeAndSort();

		void deqPairing();
		void deqCheckPairs();
		void deqCheckPair(int);
		void deqRecursiveSort(size_t base);
		void deqMergeAndSort();

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

	void printOutput(const std::vector<int>& input);
};

	bool isValid(const char* str);

#endif