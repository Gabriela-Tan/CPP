/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:50:47 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/21 09:02:49 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Data inputData;
		inputData.value = std::atoi(argv[1]);
		std::cout << "Input value: " << inputData.value << std::endl;

		uintptr_t serializedAddress = Serializer::serialize(&inputData);
		Data* deserializedData = Serializer::deserialize(serializedAddress);

		if (deserializedData == &inputData)
		{
			std::cout << "Yay! Deserialized data is the same as the original data." << std::endl;
			std::cout << "Deserialized value: " << deserializedData->value << std::endl;
		}
		else
		{
			std::cout << "Oh, no! Deserialized data is not the same as the original data." << std::endl;
			std::cout << "Deserialized value: null (failed to deserialize correctly)" << std::endl;
		}
	}
	else
		std::cout << "Wrong input! Run ./serialize [int]" << std::endl;
	return 0;
}
