/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:30:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 13:12:25 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(std::string const &name) : Victim(name) {
	
	std::cout << "[Cat Constructor] Hey, I'm " << _name << " and I'm a cat! Cats are cooler than Zaz!!" << std::endl;
};

Cat::Cat(void) {

	std::cout << "Cat: Default constructor called" << std::endl;
};

Cat::Cat(Cat const &src) {

	std::cout << "Cat: Copy constructor called" << std::endl;
};

Cat::~Cat(void) {

	std::cout << "[Cat Destructor] MEEEEOOOOOOOW!!!" << std::endl;
};

void 			Cat::getPolymorphed(void) const {

 	std::cout << "[Cat morph]" << _name << " has been turned into an ashy galinette!" << std::endl;
};

Cat & 			Cat::operator=(Cat const &rhs) {

	std::cout << "Cat: Assignation operator called" << std::endl;
};

