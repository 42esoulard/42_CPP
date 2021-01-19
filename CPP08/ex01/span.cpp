/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:37:20 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/19 19:35:46 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "customException.hpp"
#include <iostream>

Span::Span(unsigned int const N) : _size(N), _cur(0) {

	_tab = new int[N]();
};

Span::Span(void) {

	std::cout << "[Span] Default constructor called" << std::endl;
};

Span::Span(Span const &src) : _size(-1) {

	std::cout << "[Span] Copy constructor called" << std::endl;
	*this = src;
};

Span::~Span(void) {

	delete[] _tab;
	std::cout << "[Span] Destructor called" << std::endl;
};

Span & Span::operator=(Span const &rhs) {

	std::cout << "[Span] Assignation operator called" << std::endl;

	if (_size > -1)
		delete[] _tab;
	_size = rhs.getSize();
	_tab = new int[_size]();

	for (int i = 0; i < _size; i++)
		_tab[i] = rhs.getEntry(i);
	_cur = rhs.getCur();

	return *this;
};

void 		addNumber(int const &nb) {

	if (_cur == _size)
		throw customException("All numbers are already filled!")
	_cur++;
};

int const 	&shortestSpan(void);
int const 	&longestSpan(void);

int const 	&getSize(void) const {

	return this->_size;
};

int const 	&getCur(void) const {

	return this->_cur;
};

int const 	&getEntry(int const index) const {

	if (index >= _size)
		throw customException("Index doesn't exist!")
	return (_tab[index]);
};

// std::ostream & operator<<(std::ostream &o, Span const &rhs) {

// 	//return o << << std::endl;
// };

