/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/23 16:27:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe&
PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe()
{}

void
PmergeMe::mergeInsertSort(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	size_t mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	for (size_t i = 1; i < left.size(); ++i)
	{
		int current = left[i];
		size_t j = i;
		while (j > 0 && left[j - 1] > current)
		{
			left[j] = left[j - 1];
			--j;
		}
		left[j] = current;
	}
	for (size_t i = 1; i < right.size(); ++i)
	{
		int current = right[i];
		size_t j = i;
		while (j > 0 && right[j - 1] > current)
		{
			right[j] = right[j - 1];
			--j;
		}
		right[j] = current;
	}
	vec = mergeSorted(left, right);
}

std::vector<int>
PmergeMe::mergeSorted(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> output;
	std::vector<int>::iterator leftIt = left.begin();
	std::vector<int>::iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt <= *rightIt)
		{
			output.push_back(*leftIt);
			++leftIt;
		}
		else
		{
			output.push_back(*rightIt);
			++rightIt;
		}
	}
	while (leftIt != left.end())
	{
		output.push_back(*leftIt);
		++leftIt;
	}
	while (rightIt != right.end())
	{
		output.push_back(*rightIt);
		++rightIt;
	}
	return output;
}

void
PmergeMe::mergeInsertSort(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return;

	size_t mid = deq.size() / 2;
	std::deque<int> left(deq.begin(), deq.begin() + mid);
	std::deque<int> right(deq.begin() + mid, deq.end());

	for (size_t i = 1; i < left.size(); ++i)
	{
		int current = left[i];
		size_t j = i;
		while (j > 0 && left[j - 1] > current)
		{
			left[j] = left[j - 1];
			--j;
		}
		left[j] = current;
	}
	for (size_t i = 1; i < right.size(); ++i)
	{
		int current = right[i];
		size_t j = i;
		while (j > 0 && right[j - 1] > current)
		{
			right[j] = right[j - 1];
			--j;
		}
		right[j] = current;
	}
	deq = mergeSorted(left, right);
}

std::deque<int>
PmergeMe::mergeSorted(std::deque<int> left, std::deque<int> right)
{
	std::deque<int> output;
	std::deque<int>::iterator leftIt = left.begin();
	std::deque<int>::iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt <= *rightIt)
		{
			output.push_back(*leftIt);
			++leftIt;
		}
		else
		{
			output.push_back(*rightIt);
			++rightIt;
		}
	}
	while (leftIt != left.end())
	{
		output.push_back(*leftIt);
		++leftIt;
	}
	while (rightIt != right.end())
	{
		output.push_back(*rightIt);
		++rightIt;
	}
	return output;
}

void
PmergeMe::printOutput(const std::vector<int>& input)
{
	if (input.size() <= 1)
		return;

	std::vector<int> vecContainer(input);
	std::deque<int> deqContainer(input.begin(), input.end());

	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		if (it != input.begin()) 
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;

	std::clock_t startVec = std::clock();
	mergeInsertSort(vecContainer);
	double timeTakenVec = static_cast<double>(std::clock() - startVec) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = vecContainer.begin(); it != vecContainer.end(); ++it)
	{
		if (it != vecContainer.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5)
		<< "Time to process a range of " << vecContainer.size()
		 << " elements with std::vector<int> : " << timeTakenVec << " s" << std::endl;

	std::cout << "Before: ";
	for (std::deque<int>::const_iterator it = deqContainer.begin(); it != deqContainer.end(); ++it)
	{
		if (it != deqContainer.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;

	std::clock_t startDeq = std::clock();
	mergeInsertSort(deqContainer);
	double timeTakenDeq = static_cast<double>(std::clock() - startDeq) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (std::deque<int>::const_iterator it = deqContainer.begin(); it != deqContainer.end(); ++it)
	{
		if (it != deqContainer.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5)
		<< "Time to process a range of " << deqContainer.size()
		<< " elements with std::deque<int> : " << timeTakenDeq << " s" << std::endl;
}

bool
isValid(const char* str)
{
	if (*str == '\0')
		return false;
	for (; *str != '\0'; ++str)
	{
		if (*str < '0' || *str > '9')
			return false;
	}
	return true;
}
