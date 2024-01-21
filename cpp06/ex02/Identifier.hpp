/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:53:18 by gabriela          #+#    #+#             */
/*   Updated: 2024/01/21 10:54:30 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFIER_HPP
# define IDENTIFIER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{};
class B : public Base
{};
class C : public Base
{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
