/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 10:54:28 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 19:27:41 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Cat.hpp"

#include <iostream>

int 	main() {
	

	Sorcerer robert("Robert", "the Magnificent");
	std::cout << "-------------------" << std::endl;
	Victim jim("Jimmy");

	//INSTANCE PEON [inherits from victim]
	std::cout << "-------------------" << std::endl;
	Peon joe("Joe");
	std::cout << "-------------------" << std::endl;
	std::cout << robert << jim << joe;

	std::cout << std::endl << "---------CALLING GETPOLYMORPHED----------" << std::endl << std::endl;
	robert.polymorph(jim);//will get victim function
	robert.polymorph(joe);//will get peon function



	std::cout << std::endl << "---------VICTIM INSTANCE - SUBTYPE CAT----------" << std::endl << std::endl;
	
	Victim *boots = new Cat("Puss-in-Boots");
	std::cout << "-------------------" << std::endl;
	Sorcerer *bobby = new Sorcerer("Bobby", "Robert's Evil Twin Who Hates Cats");
	
	bobby->polymorph(*boots);//VICTIM - SUBTYPE CAT GETS POLYMORPHED
	std::cout << "-------------------" << std::endl;
	delete boots;//VICTIM INSTANCE - SUBTYPE CAT DELETION

	std::cout << std::endl;
	std::cout << "-------------------" << std::endl;
	delete bobby;

	return 0;
}