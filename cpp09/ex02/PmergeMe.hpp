/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:15 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/21 15:49:49 by gabriela         ###   ########.fr       */
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
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int> mergeSorted(std::vector<int> left, std::vector<int> right);
		std::deque<int> mergeSorted(std::deque<int> left, std::deque<int> right);
		void mergeInsertSort(std::vector<int>& vec);
		void mergeInsertSort(std::deque<int>& deq);
		void printOutput(const std::vector<int>& output);
};

bool isValid(const char* str);

#endif
