/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:44:14 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 19:26:09 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) {

	std::cout << "Human born" << std::endl;
};

Human::~Human(void) {

	std::cout << "Human dead. They lived a happy long life." << std::endl;
};


const Brain &Human::getBrain(void) const {

	return this->_brain;
};

std::string Human::identify(void) const {

	return this->_brain.identify();
};