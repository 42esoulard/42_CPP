/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:37:36 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/25 11:39:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <numeric>

int main(void) {

	std::cout << "--------BASIC MAIN---------" << std::endl;

	try {
		Span sp = Span(5);
		
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------NOT ENOUGH INTS---------" << std::endl;

	try {
		Span spa = Span(5);

		std::cout << spa << std::endl;

		std::cout << "Shortest: " << spa.shortestSpan() << std::endl;
		std::cout << "Longest: " << spa.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------10000+ numbers, init with iterator array---------" << std::endl;

	try {
		Span spb = Span(10500);

		std::list<int> range(10500);
		std::iota(range.begin(), range.end(), 0);

		std::list<int>::iterator it = range.begin();
		std::list<int>::iterator ite = range.end();

		spb.addNumber(it, ite);

		// std::cout << spb << std::endl;

		std::cout << "Shortest: " << spb.shortestSpan() << std::endl;
		std::cout << "Longest: " << spb.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------TOO LARGE INIT ARRAY---------" << std::endl;

	try {
		Span spb = Span(12);

		std::list<int> range(10500);
		std::iota(range.begin(), range.end(), 0);

		std::list<int>::iterator it = range.begin();
		std::list<int>::iterator ite = range.end();

		spb.addNumber(it, ite);

		std::cout << spb << std::endl;

		std::cout << "Shortest: " << spb.shortestSpan() << std::endl;
		std::cout << "Longest: " << spb.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------ADDED TOO MANY NUMBERS---------" << std::endl;

	try {
		Span sp = Span(2);

		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}


	return 0;
}