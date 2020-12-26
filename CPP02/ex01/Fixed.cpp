/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:07:58 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/20 18:47:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedPointValue(0) {

	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const &i) {

	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = i * pow(2, _bits);
};

Fixed::Fixed(float const &f) {

	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(f * pow(2, _bits));
};

Fixed::Fixed(Fixed const &src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

};

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
};

Fixed & 		Fixed::operator=(Fixed const &rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();

	return *this;
};

int 			Fixed::getRawBits(void) const {

	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
};

void 			Fixed::setRawBits(int const raw) {
	
	this->_fixedPointValue = raw;
};

float 			Fixed::toFloat(void) const {

	return float(this->_fixedPointValue) / pow(2, _bits);
};

int				Fixed::toInt(void) const {

	return this->_fixedPointValue / pow(2, _bits);
};

std::ostream & 	operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
};


int const	Fixed::_bits = 8;