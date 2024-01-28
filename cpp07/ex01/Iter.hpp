/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:02:28 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/27 10:59:46 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t size, void(*f)(T const &))
{
	size_t i = 0;
	while (i < size)
	{
		f(array[i]);
		i++;
	}
}

template <typename T>
void printElement(const T &element)
{
	std::cout << element << std::endl;
}

#endif
