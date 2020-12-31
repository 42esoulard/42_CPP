/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:24:33 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/31 11:58:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) {

	std::cout << "[MateriaSource] Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {

		_memory[i] = nullptr;
	}
};

MateriaSource::MateriaSource(MateriaSource const &src) {

	std::cout << "[MateriaSource] Copy constructor called" << std::endl;
	*this = src;
};

MateriaSource::~MateriaSource(void) {

	for (int i = 0; i < 4; i++) {

		if (this->_memory[i])
			delete this->_memory[i];

		this->_memory[i] = nullptr;
	}
	std::cout << "[MateriaSource] Destructor called" << std::endl;
};

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs) {

	std::cout << "[MateriaSource] Assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++) {

		this->_memory[i] = rhs.getMateria(i)->clone();
	}
	return *this;
};

AMateria*	MateriaSource::getMateria(int idx) const {

	return this->_memory[idx];
};

void 		MateriaSource::learnMateria(AMateria* newMateria) {

	AMateria *tmp;

	tmp = newMateria;
	for (int i = 0; i < 4; i++) {

		if (!_memory[i]) {

			_memory[i] = tmp;
			return ;
		}
	}
	std::cout << "MateriaSource: memory full" << std::endl;
	delete newMateria;
};

AMateria* 	MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++) {

		if (_memory[i] && type.compare(_memory[i]->getType()) == 0) {
			return _memory[i]->clone();
		}
	}
	std::cout << "MateriaSource: AMateria type unknown" << std::endl;
	return 0;
};
