/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:40:47 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/24 16:14:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

/*
** From CPPreference, std::stack is defined as:
** template<
** class T,
** class Container = std::deque<T>
** > class stack;
**
** ...So we'll use a default std::deque iterator !
** 
** In class std::stack, the container is protected 
** and refered to as c.
** We can use its (std::deque) begin() and end() functions.
*/

template<typename T>
class MutantStack : public std::stack<T> {
	
	public:

		MutantStack<T>(void) : std::stack<T>() {};
		MutantStack<T>(MutantStack const &src) : std::stack<T>(src) {} ;
		virtual ~MutantStack<T>(void) {};

		MutantStack & operator=(MutantStack<T> const &rhs) {
			std::stack<T>::operator=(rhs);
		};

		typedef typename std::deque<T>::iterator iterator;
		iterator begin(){return this->c.begin();}
        iterator end() {return this->c.end();}

};

#endif