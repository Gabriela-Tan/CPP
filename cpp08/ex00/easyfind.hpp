/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:23:40 by gabriela          #+#    #+#             */
/*   Updated: 2024/02/02 11:12:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Number is not there.";
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
