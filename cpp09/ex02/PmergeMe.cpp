/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:03:12 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/27 08:23:05 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _pair(1)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other) : 
		_pair(other._pair), _vecc(other._vecc), _deqc(other._deqc), 
		vec_pair(other.vec_pair), deq_pair(other.deq_pair) 
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_pair = other._pair;
		_vecc = other._vecc;
		_deqc = other._deqc;
		vec_pair = other.vec_pair;
		deq_pair = other.deq_pair;
	}
	return *this;
}

void
PmergeMe::vecPairing()
{
	size_t i = 0;
	vec_pair.clear();

	while ((i < _vecc.size() && _vecc.size() % 2 == 0) 
	|| (i < _vecc.size() - 1 && _vecc.size() % 2 == 1))
	{
		if (i + 1 < _vecc.size())
			vec_pair.push_back(std::make_pair(_vecc[i], _vecc[i + 1]));
		else 
			vec_pair.push_back(std::make_pair(_vecc[i], _vecc[i]));
		i += 2;
	}
	if (_vecc.size() % 2 == 0)
		_pair = 0;
	else
		_pair = 1;
}

void
PmergeMe::vecCheckPairs()
{
	for (size_t i = 0; i < vec_pair.size(); ++i)
	{
		if (vec_pair[i].first > vec_pair[i].second)
			std::swap(vec_pair[i].first, vec_pair[i].second);
	}
}

void
PmergeMe::vecCheckPair(int i)
{
	if (vec_pair[i].first > vec_pair[i].second)
		std::swap(vec_pair[i].first, vec_pair[i].second);
}

void
PmergeMe::vecRecursiveSort(size_t base)
{
	if (base >= vec_pair.size() - 1)
		return;

	for (size_t i = base + 1; i < vec_pair.size(); ++i)
	{
		if (vec_pair[i].first < vec_pair[base].first)
		{
			std::swap(vec_pair[i], vec_pair[base]);
			vecCheckPair(base);
			vecCheckPair(i);
		}
	}
	vecRecursiveSort(base + 1);
}


void
PmergeMe::vecMergeAndSort()
{
	int temp;

	if (_pair == 1)
		temp = _vecc[_vecc.size() - 1];
	_vecc.clear();
	for (size_t i = 0; i < vec_pair.size(); i++)
		_vecc.push_back(vec_pair[i].first); 
	for (size_t i = 0; i < vec_pair.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(_vecc.begin(), _vecc.end(), vec_pair[i].second);
		_vecc.insert(it, vec_pair[i].second);
	}
	vec_pair.clear();
	if (_pair == 1)
	{
		std::vector<int>::iterator it = std::lower_bound(_vecc.begin(), _vecc.end(), temp);
		_vecc.insert(it, temp);
	}
}

void 
PmergeMe::deqPairing()
{
	size_t i = 0;
	deq_pair.clear();

	while ((i < _deqc.size() && _deqc.size() % 2 == 0) || (i < _deqc.size() - 1 && _deqc.size() % 2 == 1))
	{
		if (i + 1 < _deqc.size())
			deq_pair.push_back(std::make_pair(_deqc[i], _deqc[i + 1]));
		else
			deq_pair.push_back(std::make_pair(_deqc[i], _deqc[i]));
		i += 2;
	}

	if (_deqc.size() % 2 == 0) 
		_pair = 0;
	else 
		_pair = 1;
}

void
PmergeMe::deqCheckPairs()
{
	for (size_t i = 0; i < deq_pair.size(); ++i)
	{
		if (deq_pair[i].first > deq_pair[i].second)
			std::swap(deq_pair[i].first, deq_pair[i].second);
	}
}

void
PmergeMe::deqCheckPair(int i)
{
	if (deq_pair[i].first > deq_pair[i].second)
		std::swap(deq_pair[i].first, deq_pair[i].second);
}

void
PmergeMe::deqRecursiveSort(size_t base)
{
	if (base >= deq_pair.size() - 1)
		return;

	for (size_t i = base + 1; i < deq_pair.size(); ++i)
	{
		if (deq_pair[i].first < deq_pair[base].first)
		{
			std::swap(deq_pair[i], deq_pair[base]);
			deqCheckPair(base);
			deqCheckPair(i);
		}
	}
	deqRecursiveSort(base + 1);
}

void
PmergeMe::deqMergeAndSort()
{
	int temp;

	if (_pair == 1)
		temp = _deqc[_deqc.size() - 1];
	_deqc.clear();
	for (size_t i = 0; i < deq_pair.size(); i++)
		_deqc.push_back(deq_pair[i].first);
	for (size_t i = 0; i < deq_pair.size(); i++)
	{
		std::deque<int>::iterator it = std::lower_bound(_deqc.begin(), _deqc.end(), deq_pair[i].second);
		_deqc.insert(it, deq_pair[i].second);
	}
	deq_pair.clear();
	if (_pair == 1)
	{
		std::deque<int>::iterator it = std::lower_bound(_deqc.begin(), _deqc.end(), temp);
		_deqc.insert(it, temp);
	}
}

void PmergeMe::printOutput(const std::vector<int>& input)
{
	_vecc = input;
	_deqc.clear();
	std::copy(input.begin(), input.end(), std::back_inserter(_deqc));

	if (input.size() <= 1)
		return;

	std::cout << "Before: ";
	for (size_t i = 0; i < _vecc.size(); ++i)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << _vecc[i];
	}
	std::cout << std::endl;

	std::clock_t startVec = std::clock();
	vecPairing();
	vecCheckPairs();
	vecRecursiveSort(0);
	vecMergeAndSort();
	double timeTakenVec = static_cast<double>(std::clock() - startVec) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (size_t i = 0; i < _vecc.size(); ++i)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << _vecc[i];
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(10)
			<< "Time to process a range of " << _vecc.size()
			<< " elements with std::vector<int> : " << timeTakenVec << " s" << std::endl;

	std::cout << "Before (deque): ";
	for (std::deque<int>::iterator it = _deqc.begin(); it != _deqc.end(); ++it)
	{
		if (it != _deqc.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;

	std::clock_t startDeq = std::clock();
	deqPairing();
	deqCheckPairs();
	deqRecursiveSort(0);
	deqMergeAndSort();
	double timeTakenDeq = static_cast<double>(std::clock() - startDeq) / CLOCKS_PER_SEC;

	std::cout << "After (deque): ";
	for (std::deque<int>::iterator it = _deqc.begin(); it != _deqc.end(); ++it)
	{
		if (it != _deqc.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(10)
			<< "Time to process a range of " << _deqc.size()
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
