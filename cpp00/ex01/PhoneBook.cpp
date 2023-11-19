/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:44 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/19 10:06:18 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

Contact::Contact(void) : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void
Contact::setFirstName(const std::string& fName)
{
	firstName = fName;
}

void
Contact::setLastName(const std::string& lName)
{
	lastName = lName;
}

void
Contact::setNickname(const std::string& nick)
{
	nickname = nick;
}

void
Contact::setPhoneNumber(const std::string& phone)
{
	phoneNumber = phone;
}

void
Contact::setDarkestSecret(const std::string& secret)
{
	darkestSecret = secret;
}

std::string
Contact::getFirstName(void) const
{
	return (firstName);
}

std::string
Contact::getLastName(void) const
{
	return (lastName);
}

std::string
Contact::getNickname(void) const
{
	return (nickname);
}

std::string
Contact::getPhoneNumber(void) const
{
	return (phoneNumber);
}

std::string
Contact::getDarkestSecret(void) const
{
	return (darkestSecret);
}

std::string
Contact::getContent(const std::string& prompt)
{
	std::string content;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, content);
		if (!content.empty())
			return (content);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

void
Contact::setContact(void)
{
	setFirstName(getContent("Enter first name: "));
	setLastName(getContent("Enter last name: "));
	setNickname(getContent("Enter nickname: "));
	setPhoneNumber(getContent("Enter phone number: "));
	setDarkestSecret(getContent("Enter darkest secret: "));
}

void
Contact::showSummary(int index) const
{
	std::cout << std::setw(10) << index + 1 << "|";
	std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
	std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
	std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

void
Contact::showContent(void) const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

PhoneBook::PhoneBook(void) : count(0) {}

void
PhoneBook::add(void)
{
	if (count >= 8)
		contacts[count % 8].setContact();
	else
		contacts[count].setContact();
	count++;
}

void
PhoneBook::search(void) const
{
	int i = 0;
	int showCount = count < 8 ? count : 8;

	while (i < showCount)
	{
		contacts[i].showSummary(i);
		i++;
	}
	std::cout << "Enter the index of the contact to display (1 to 8): ";
	int index;
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail())
	{
		std::cout << "Invalid content." << std::endl;
		std::cin.clear();
		return;
	}
	index--;
	if (index < 0 || index >= showCount)
	{
		std::cout << "Invalid index. Enter a number between 1 and 8." << std::endl;
		return;
	}
	contacts[index].showContent();
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter one of the commands (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
	}
	return 0;
}
