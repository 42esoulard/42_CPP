/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:18:25 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/29 14:56:45 by esoulard         ###   ########.fr       */
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

	this->deleteUnitList();
	std::cout << "[Squad] Destructor called" << std::endl;
};

Squad & Squad::operator=(Squad const &rhs) {

	std::cout << "[Squad] Assignation operator called" << std::endl;
	
	this->deleteUnitList();

	this->_unitCount = rhs.getCount();
	this->_unitList = rhs.getUnitList();
	
	return *this;
};

Unit 			*Squad::getUnitList(void) const {

	return this->_unitList;
};

int 			Squad::getCount(void) const {

	return this->_unitCount;
};

void 			Squad::deleteUnitList(void) {

	Unit 		*tmp;

	if (this->_unitCount > 0) {

		while (this->_unitList) {

			tmp = this->_unitList->next;
			delete this->_unitList->cur;
			delete this->_unitList;
			this->_unitList = tmp;
		}
	}
	else
		delete this->_unitList;

	this->_unitCount = 0;
};

//n starts at 0 but count = lastindex + 1
ISpaceMarine* 	Squad::getUnit(int n) const {

	Unit 		*tmp = this->_unitList;
	int 		i = -1;

	if (n >= this->_unitCount || n < 0)
		return nullptr;

	while (tmp->next && ++i != n)
		tmp = tmp->next;

	return tmp->cur;
};

int 			Squad::push(ISpaceMarine* newUnit) {

	Unit 	*tmp = this->_unitList;

	if (!newUnit) {
		std::cerr << "Can't add a null unit!" << std::endl;
		return -1;
	}

	while (this->_unitList->next) {
		
		if (newUnit == this->_unitList->cur || 
			newUnit == this->_unitList->next -> cur) {
			std::cerr << "Unit already in Squad!" << std::endl;
			this->_unitList = tmp;
			return -1;
		}
		this->_unitList = this->_unitList->next;
	}
	
	if (this->_unitCount > 0) {

		this->_unitList->next = new Unit;
		this->_unitList = this->_unitList->next;
	}

	this->_unitList->cur = newUnit;
	this->_unitList->next = nullptr;

	this->_unitList = tmp;
	this->_unitCount++;

	return this->_unitCount;
};
