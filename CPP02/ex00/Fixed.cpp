/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:07:58 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/20 17:29:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _fixedPointValue(0) {

	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed const &src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
};

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
};

Fixed & Fixed::operator=(Fixed const &rhs) {

	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();

	return *this;
};


int 	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
};

void 	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
};



int const	Fixed::_bits = 8;