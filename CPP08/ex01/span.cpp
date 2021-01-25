/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:37:20 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/25 11:27:44 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include "customException.hpp"
#include <iostream>
#include <list>
#include <algorithm>

Span::Span(unsigned int const N) : _size(N) {

	std::cout << "[Span] Default constructor called" << std::endl;
};

Span::Span(void) {

	std::cout << "[Span] Default constructor called" << std::endl;
};

Span::Span(Span const &src) : _size(src._size) {

	std::cout << "[Span] Copy constructor called" << std::endl;
	*this = src;
};

Span::~Span(void) {

	std::cout << "[Span] Destructor called" << std::endl;
};

Span & Span::operator=(Span const &rhs) {

	std::cout << "[Span] Assignation operator called" << std::endl;
	_tab.erase(_tab.begin(), _tab.end());

	std::list<int>::const_iterator itSrc;
	std::list<int>::const_iterator itSrce = rhs._tab.end();

	for (itSrc = rhs._tab.begin(); itSrc != itSrce; itSrc++) {
	 	_tab.push_back(*itSrc);
	}

	return *this;
};

void 		Span::addNumber(int const &nb) {

	if (_tab.size() == _size)
		throw customException("All slots are full, can't store any more ints!");
	this->_tab.push_back(nb);
};

template <typename iterator>
void 		Span::addNumber(iterator &ita, iterator &itb) {
	
	int i = 0;

	if (std::distance(ita, itb) > _size - _tab.size())
		throw customException("Range won't fit this Span instance :(");
			
	for (ita; ita != itb; ita++) {
		_tab.push_back(*ita);
	}
};

int const 	Span::shortestSpan(void) {

	if (_tab.size() <= 1)
		throw customException("Not enough entries to check for a span");
	
	_tab.sort();

	std::list<int>::const_iterator it = ++(_tab.begin());
	std::list<int>::const_iterator ite = _tab.end();
	std::list<int>::const_iterator prev = _tab.begin();

	int span = *it - *prev;

	for (it = ++(_tab.begin()); it != ite; it++) {
		if (span > *it - *prev)
			span = *it - *prev;
		prev++;
	}
	return span;
};


int const 	Span::longestSpan(void) {

	if (_tab.size() <= 1)
		throw customException("Not enough entries to check for a span");
	
	_tab.sort();
	std::list<int>::const_iterator it = _tab.begin();
	std::list<int>::const_iterator ite = _tab.end();
	ite--;

	return *ite - *it;
};

std::list<int> const &Span::getTab(void) const {

	return (_tab);
};

std::ostream & operator<<(std::ostream &o, Span const &rhs) {

	std::list<int> const tmp = rhs.getTab();

	std::list<int>::const_iterator it;
	std::list<int>::const_iterator ite = tmp.end();

	o << "------------" << std::endl;
	o << "[ ";
	for (it = tmp.begin(); it != ite; it++)
		o << *it << " ";
	o << "]" << std::endl;
	o << "------------" << std::endl;
	return o;
};

