/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:54:28 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/28 13:44:00 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Cat.hpp"

#include <iostream>

int 	main() {
	
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	
	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;
	Sorcerer *bobby = new Sorcerer("Bobby", "Robert's Evil Twin Who Hates Cats");
	Victim *boots = new Cat("Puss-in-Boots");

	bobby->polymorph(*boots);

	delete boots;
	delete bobby;

	std::cout << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;

	return 0;
}