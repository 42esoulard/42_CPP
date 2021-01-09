/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:38:12 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/09 13:48:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iostream>
#include <sstream>
#include "customException.hpp"

Convert::Convert(std::string const &input) :
_type(parseInput(input)) {


	std::cout << "type is " << _type << std::endl;
	(this->*_makeConv[_type])(input);
	std::cout << "[Convert] Default constructor called" << std::endl;
};

Convert::Convert(void) {

	std::cout << "[Convert] Default constructor called" << std::endl;
};

Convert::Convert(Convert const &src) {

	std::cout << "[Convert] Copy constructor called" << std::endl;
	*this = src;
};

Convert::~Convert(void) {

	std::cout << "[Convert] Destructor called" << std::endl;
};

Convert & Convert::operator=(Convert const &rhs) {

	std::cout << "[Convert] Assignation operator called" << std::endl;
	return *this;
};

std::ostream & operator<<(std::ostream &o, Convert const &rhs) {

	return o << "char: " << rhs.getCharConv() << std::endl <<
			"int: " << rhs.getIntConv() << std::endl <<
			"float: " << rhs.getFloatConv() << "f" << std::endl <<
			"double: " << rhs.getDoubleConv() << std::endl;
};


char const & Convert::getCharConv(void) const {

	return this->_charConv;
};

int const & Convert::getIntConv(void) const {

	return this->_intConv;
};

float const & Convert::getFloatConv(void) const {

	return this->_floatConv;
};

double const & Convert::getDoubleConv(void) const {

	return this->_doubleConv;
};

int Convert::parseInput(std::string const &input) const {

	int size = input.size();

	if (size == 1 && isalpha(input[0]))
		return T_CHAR;
	int idx = 0;
	if (input[idx] == '-' || input[idx] == '+')
		idx++;
	int i = idx;
	while (idx < size && isdigit(input[idx]))
		idx++;
	if (idx == size && idx != i)
		return T_INT;
	if (input[idx++] != '.')
		throw customException("bad input");
	i = idx;
	while (input[idx] && isdigit(input[idx]))
		idx++;
	if (idx == size && idx != i)
		return T_DOUBLE;
	if (input[idx] == 'f' && idx + 1 == size && idx != i)
		return T_FLOAT;
	throw customException("bad input");

};

void	Convert::fromChar(std::string const &input) {

	try {
		std::stringstream ss(input);

		ss >> _charConv;
		std::cout << "conv ok " << _charConv << std::endl;
		
		void *ptr = &_charConv;
		_intConv = *reinterpret_cast<int *>(ptr);
		_floatConv = *reinterpret_cast<float *>(ptr);
		_doubleConv = *reinterpret_cast<double *>(ptr);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};

void	Convert::fromInt(std::string const &input) {

	try {
		std::stringstream ss(input);

		int i;
		ss >> _intConv;
		std::cout << "conv ok " << _intConv << std::endl;
		
		void *ptr = &_intConv;
		_charConv = *reinterpret_cast<char *>(ptr);
		_floatConv = *reinterpret_cast<float *>(ptr);
		_doubleConv = *reinterpret_cast<double *>(ptr);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};

void	Convert::fromFloat(std::string const &input) {

	try {
		std::stringstream ss(input);

		ss >>_floatConv;
		std::cout << "conv ok " << _floatConv << std::endl;
		
		void *ptr = &_floatConv;
		_intConv = *reinterpret_cast<int *>(ptr);
		_charConv = *reinterpret_cast<char *>(ptr);
		_doubleConv = *reinterpret_cast<double *>(ptr);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};

void	Convert::fromDouble(std::string const &input) {

	try {
		std::stringstream ss(input);

		ss >> _doubleConv;
		std::cout << "conv ok " << _doubleConv << std::endl;
		
		void *ptr = &_doubleConv;
		_intConv = *reinterpret_cast<int *>(ptr);
		_floatConv = *reinterpret_cast<float *>(ptr);
		_charConv = *reinterpret_cast<char *>(ptr);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};


