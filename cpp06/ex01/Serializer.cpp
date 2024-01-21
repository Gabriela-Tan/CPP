/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:50:56 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/21 09:28:47 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer&
Serializer::operator=(const Serializer& other)
{
	(void) other;
	return *this;
}

Serializer::~Serializer()
{}

uintptr_t
Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*
Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
