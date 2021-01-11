/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:38:12 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 18:22:22 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iostream>
#include <sstream>
#include <string.h>
#include <limits>
#include <cmath>
#include "customException.hpp"

Convert::Convert(std::string const &input) :
_charConv(0), _intConv(0), _floatConv(0), _doubleConv(0), 
_type(_parseInput(input)) {

	(this->*_makeConv[_type])(input);
};

Convert::Convert(void) {
};

Convert::Convert(Convert const &src) {

	_output = new std::string("");
	*this = src;
};

Convert::~Convert(void) {

	delete _output;
};

Convert & Convert::operator=(Convert const &rhs) {

	_charConv = rhs.getCharConv();
	_intConv = rhs.getIntConv();
	_floatConv = rhs.getFloatConv();	
	_doubleConv = rhs.getDoubleConv();
	_type = rhs.getType();

	delete _output;
	_output = new std::string(*(rhs.getOutput()));
	return *this;
};

//--------------------------------------------
////------------PRINT RESULT------------------

std::ostream & operator<<(std::ostream &o, Convert const &rhs) {

	//--------------------------------------------
	o << "char: ";

	if (rhs.getType() == T_NAN || rhs.getType() == T_INVALID ||
		(rhs.getDoubleConv() > std::numeric_limits<char>::max() ||
		rhs.getDoubleConv() < std::numeric_limits<char>::min()))
		o << "impossible" << std::endl;
	else if (rhs.getDoubleConv() < 33 || rhs.getDoubleConv() > 126)
		o << "non displayable" << std::endl;
	else
		o  << "\'" << rhs.getCharConv() << "\'" << std::endl;

	//--------------------------------------------
	o << "int: ";

	if (rhs.getType() == T_NAN || rhs.getType() == T_INVALID ||
		(rhs.getDoubleConv() > std::numeric_limits<int>::max() ||
		rhs.getDoubleConv() < std::numeric_limits<int>::min()))
		o << "impossible" << std::endl;
	else
		o  << rhs.getIntConv() << std::endl;

	//--------------------------------------------
	o << "float: ";

	if (rhs.getType() == T_INVALID)
		o << "impossible" << std::endl;
	else {
		o << rhs.getFloatConv();
		if ((std::fmod(rhs.getFloatConv(), 1.0) == 0.0))
			o << ".0";
		o << "f"  << std::endl;
	}

	//--------------------------------------------
	o << "double: ";

	if (rhs.getType() == T_INVALID)
		o << "impossible" << std::endl;
	else {
		o << rhs.getDoubleConv();
		if ((std::fmod(rhs.getDoubleConv(), 1.0) == 0.0))
			o << ".0";
		o << std::endl;
	}

	return o;
};


//----------------------------------------------
//------------INITIAL CHECKS------------------
int Convert::_parseInput(std::string const &input) {

	
	_output = new std::string(input);



	int idx = 0;
	if (input[idx] == '-' || input[idx] == '+')
		idx++;

	// --------------------------
	//CHECK IF VALID DOUBLE
	int size = input.size();
	if ((_doubleConv = strtod(input.c_str(), nullptr)) ||
		(!_doubleConv && _isZero(idx))) {
		return T_DOUBLE;
	}
	

	// --------------------------
	//CHECK IF VALID AND DISPLAYABLE CHAR
	
	if (size == 1 && input[0] >= 33 && input[0] <= 126)
		return T_CHAR;

	delete _output;
	throw customException("Invalid argument"); 
};

//-------CHECK IF INPUT IS ZERO-----------
int Convert::_isZero(int idx) const {

	int tmp = idx;

	while (idx < (*_output).size() && (*_output)[idx] == '0')
		idx++;
	if ((*_output)[idx] == '.')
		idx++;
	while (idx < (*_output).size() &&(* _output)[idx] == '0')
		idx++;
	if ((idx == (*_output).size() && idx != 0) || (idx != tmp && !isdigit((*_output)[idx]))) 
		return 1;
	return 0;

};


//----------------------------------------------
//----------------CONVERSIONS-------------------

/*
* static_casts are used for simple conversions.
* allow for upcast and downcast.
*/

void	Convert::fromChar(std::string const &input) {

	std::stringstream ss(input);

	try {

		ss >> _charConv;

		_intConv = static_cast<int>(_charConv);
		_floatConv = static_cast<float>(_charConv);
		_doubleConv = static_cast<double>(_charConv);

		std::cout << *this;
	}
	catch(std::exception) {
		std::cout << "Conversion from char failed" << std::endl;
	}

};

void	Convert::fromDouble(std::string const &input) {

	try {
		_doubleConv = strtod(input.c_str(), nullptr);

		_intConv = static_cast<int>(_doubleConv);
		_floatConv = static_cast<float>(_doubleConv);
		_charConv = static_cast<char>(_doubleConv);

		if (std::isnan(_doubleConv))
			_type = T_NAN;

		std::cout << *this;
	}
	catch(std::exception) {
		std::cout << "Conversion from double failed" << std::endl;
	}
	
};

void	Convert::fromInvalid(std::string const &input) {

	try {
		std::cout << *this;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};

//----------------------------------------------
//----------------GETTERS-----------------------

std::string *Convert::getOutput(void) const {

	return this->_output;
};

int const & Convert::getType(void) const {

	return this->_type;
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

//----------------------------------------------
//----------------------------------------------