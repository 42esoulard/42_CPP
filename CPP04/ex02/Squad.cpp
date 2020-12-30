/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:18:25 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/30 13:43:43 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad(void) : _unitCount(0), _unitList(new Unit) {

	_unitList->cur = nullptr;
	_unitList->next = nullptr;
	_unitList->copy = 0;
	std::cout << "[Squad] Default constructor called" << std::endl;
};

Squad::Squad(Squad const &rhs) : _unitCount(0) {

	std::cout << "[Squad] Copy constructor called" << std::endl;

	this->_unitCount = rhs.getCount();
	this->_unitList = &rhs.copyUnitList();
};

Squad::~Squad(void) {

	this->deleteUnitList();
	std::cout << "[Squad] Destructor called" << std::endl;
};

Squad & Squad::operator=(Squad const &rhs) {

	std::cout << "[Squad] Assignation operator called" << std::endl;
	
	this->deleteUnitList();

	this->_unitCount = rhs.getCount();
	this->_unitList = &rhs.copyUnitList();
	
	return *this;
};

Unit 		&Squad::copyUnitList(void) const {

	Unit *copy = new Unit;
	Unit *copyRet = copy;
	Unit *src  = this->_unitList;

	std::cout << "[Copying squad UnitList!]" << std::endl;
	
	copy->cur = src->cur;
	copy->copy = 1;
	copy->next = nullptr;

	for (int i = 1; i < _unitCount; ++i) {

		src = src->next;
		copy->next = new Unit;
		copy = copy->next;
		copy->cur = src->cur;
		copy->copy = 1;
		copy->next = nullptr;
	}
	return *copyRet;
};

int 			Squad::getCount(void) const {

	return this->_unitCount;
};

void 			Squad::deleteUnitList(void) {

	Unit 		*tmpNxt;
	int i = 0;

	if (this->_unitCount > 0) {

		while (this->_unitList) {

			tmpNxt = this->_unitList->next;
			if (!this->_unitList->copy && this->_unitList->cur) {
				
				delete this->_unitList->cur;
				this->_unitList->cur = nullptr;
			}
			delete this->_unitList;
			this->_unitList = tmpNxt;
			i++;
		}
	}
	else if (this->_unitList) {
			delete this->_unitList;
	}

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
	this->_unitList->copy = 0;
	this->_unitList->next = nullptr;

	this->_unitList = tmp;
	this->_unitCount++;

	return this->_unitCount;
};
