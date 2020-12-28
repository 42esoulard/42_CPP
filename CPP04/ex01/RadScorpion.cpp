/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:41:48 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 19:04:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) :
Enemy(80, "RadScorpion") {

	std::cout << "[RadScorpion] * click click click *" << std::endl;
};

RadScorpion::RadScorpion(RadScorpion const &src) {

	std::cout << "[RadScorpion] Copy constructor called" << std::endl;
	*this = src;
};

RadScorpion::~RadScorpion(void) {

	std::cout << "[RadScorpion] * SPROTCH *" << std::endl;
};

RadScorpion & RadScorpion::operator=(RadScorpion const &rhs) {

	std::cout << "[RadScorpion] Assignation operator called" << std::endl;
	return *this;
};

