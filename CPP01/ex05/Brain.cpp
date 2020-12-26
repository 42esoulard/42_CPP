/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:26:10 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/10 19:24:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	
	std::cout << "Brain born" << std::endl;
};

Brain::~Brain(void) {
	
	std::cout << "Brain dead" << std::endl;
};

std::string Brain::identify(void) const {

	std::ostringstream address;
	address << this;
	return address.str();
};