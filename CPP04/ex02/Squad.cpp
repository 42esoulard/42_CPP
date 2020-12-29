/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:18:25 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 13:38:21 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad(void) : _unitCount(0), _unitList(new Unit) {

	_unitList->cur = nullptr;
	_unitList->next = nullptr;
	std::cout << "[Squad] Default constructor called" << std::endl;
};

Squad::Squad(Squad const &src) {

	std::cout << "[Squad] Copy constructor called" << std::endl;
	*this = src;
};

Squad::~Squad(void) {

	std::cout << "[Squad] Destructor called" << std::endl;
};

Squad & Squad::operator=(Squad const &rhs) {

	Unit 		*tmp;

	std::cout << "[Squad] Assignation operator called" << std::endl;
	
	if (this->_unitCount > 0) {

		while (this->_unitList) {

			tmp = this->_unitList->next;
			delete this->_unitList->cur;
			delete this->_unitList;
			this->_unitList = tmp;
		}
	}

	this->_unitCount = rhs.getCount();
	this->_unitList = rhs.getUnitList();
	
	return *this;
};

std::ostream & operator<<(std::ostream &o, Squad const &rhs) {

	//return o << << std::endl;
};

Unit 			*Squad::getUnitList(void) const {

	return this->_unitList;
};

int 			Squad::getCount(void) const {

	return this->_unitCount;
};
//n starts at 0 but count = lastindex + 1
ISpaceMarine* 	Squad::getUnit(int n) const {

	Unit 		*tmp = this->_unitList;
	int 		i = -1;

	if (n >= this->_unitCount || n < 0)
		return nullptr;

	std::cout << "a" << i << n << std::endl;
	while (tmp->next && ++i != n) {
		std::cout << "getUnit loop " << i << std::endl;
		tmp = tmp->next;
	}
	std::cout << "b" << std::endl;
	return tmp->cur;
};

int 			Squad::push(ISpaceMarine* newUnit) {

	Unit 			*&tmp = this->_unitList;

	std::cout << "beg push?" << std::endl;
	if (!newUnit) // || tmp already in squad)
		return -1;
	std::cout << "beg push?" << std::endl;

	while (this->_unitList->next) {
		std::cout << "in while push loop" << std::endl;
		this->_unitList = this->_unitList->next;
	}
	std::cout << "0 " << this->_unitCount << std::endl;
	
	if (this->_unitCount > 0) {

		std::cout << "adding next to list" << std::endl;
		this->_unitList->next = new Unit;
		this->_unitList = this->_unitList->next;
	}
	std::cout << "1" << std::endl;
	this->_unitList->cur = newUnit;
	this->_unitList->next = nullptr;
	std::cout << "2" << std::endl;

	//this->_unitList = tmp;
	this->_unitCount++;
	std::cout << "2.5" << std::endl;
	return this->_unitCount;
};
