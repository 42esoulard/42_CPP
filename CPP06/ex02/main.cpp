/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:48:28 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 18:01:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "identify.h"

Base *genA(void) {

	std::cout << "Generating class A!" << std::endl;
	
	Base *a = new A();
	return a;
}

Base *genB(void) {

	std::cout << "Generating class B!" << std::endl;
	
	Base *b = new B();
	return b;
}

Base *genC(void) {

	std::cout << "Generating class C!" << std::endl;
	
	Base *c = new C();
	return c;
}

// Generating random polymorphic Base instance
// of subtype A, B or C class

Base *generate(void) {
	
	_tGenClass 	 genClass[3] 	= 	{	
										&genA, 
										&genB,
										&genC,
									};

	Base *randBase = (*genClass[rand() % 3])();

	return randBase;
}

/*
* dynamic_casts are used in situations of 
* polymorphism. 
* It checks for the true type at execution.
* If we try to cast a child
* to another branch, it fails.
*/

void identify_from_pointer(Base * p) {

	try {
		A a = dynamic_cast<A &>(*p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast) {}
	try {
		B b = dynamic_cast<B &>(*p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast) {}
	try {
		C c = dynamic_cast<C &>(*p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast) {}
}

void identify_from_reference( Base & p) {

	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast) {}
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast) {}
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast) {}
}


int main(void) {

	srand(time(NULL));

	std::cout << "------------" << std::endl;
	Base *ment = generate();

	std::cout << "------------" << std::endl;
	std::cout << "Identification from pointer..." << std::endl;
	identify_from_pointer(ment);

	std::cout << "Identification from reference..." << std::endl;
	identify_from_reference(*ment);
	std::cout << "------------" << std::endl;

	delete ment;

	return 0;
}