/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:57:49 by gabriela          #+#    #+#             */
/*   Updated: 2023/11/19 10:06:30 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		std::string getContent(const std::string& prompt);

	public:
		Contact();

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);

		void setContact();
		void showSummary(int index) const;
		void showContent() const;
};

class PhoneBook
{
	private:
		Contact contacts[8];
		int count;

	public:
		PhoneBook();
		void add();
		void search() const;
};

#endif
