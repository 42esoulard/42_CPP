/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:36:17 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/14 10:23:20 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void) {

	std::cout << "------------------INT---------------------" << std::endl;

	int a = 2;
	int b = 3;
	
	std::cout << std::endl;
	std::cout << "[ADDR] a = " << &a << std::endl;
	std::cout << "[ADDR] b = " << &b << std::endl;
	
	std::cout << std::endl;
	std::cout << "[BEFORE SWAP] a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "[AFTER SWAP] a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << " [ADDR = " << &::min( a, b ) << "]" << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << " [ADDR = " << &::max( a, b ) << "]" << std::endl;
	
	std::cout << std::endl;
	a = b;
	std::cout << "[CHANGED VALUES] a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << " [ADDR = " << &::min( a, b ) << "]" << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << " [ADDR = " << &::max( a, b ) << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "--------------------STR-------------------" << std::endl;

	std::cout << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "[ADDR] c = " << &c << std::endl;
	std::cout << "[ADDR] d = " << &d << std::endl;
	
	std::cout << std::endl;
	std::cout << "[BEFORE SWAP] c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "[AFTER SWAP] c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << " [ADDR = " << &::min( c, d ) << "]" << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << " [ADDR = " << &::max( c, d ) << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "------------------FLOAT-------------------" << std::endl;

	std::cout << std::endl;
	float e = 42.1f;
	float f = 24.3f;
	
	std::cout << "[ADDR] e = " << &e << std::endl;
	std::cout << "[ADDR] f = " << &f << std::endl;
	
	std::cout << std::endl;
	std::cout << "[BEFORE SWAP] e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "[AFTER SWAP] e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << " [ADDR = " << &::min( e, f ) << "]" << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << " [ADDR = " << &::max( e, f ) << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "-------------------CHAR-------------------" << std::endl;

	std::cout << std::endl;
	char g = '1';
	char h = '2';
	
	std::cout << "[ADDR] g = " << static_cast<void const *>(&g) << std::endl;
	std::cout << "[ADDR] h = " << static_cast<void const *>(&h) << std::endl;
	
	std::cout << std::endl;
	std::cout << "[BEFORE SWAP] g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "[AFTER SWAP] g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << " [ADDR = " << static_cast<void const *>(&::min( g, h )) << "]" << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << " [ADDR = " << static_cast<void const *>(&::max( g, h )) << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "-------------------DOUBLE------------------" << std::endl;

	std::cout << std::endl;
	double i = 123.123;
	double j = 123.123;
	
	std::cout << "[ADDR] i = " << &i << std::endl;
	std::cout << "[ADDR] j = " << &j << std::endl;
	
	std::cout << std::endl;
	std::cout << "[BEFORE SWAP] i = " << i << ", j = " << j << std::endl;
	::swap(i, j);
	std::cout << "[AFTER SWAP] i = " << i << ", j = " << j << std::endl;
	std::cout << "min( i, j ) = " << ::min( i, j ) << " [ADDR = " << &::min( i, j ) << "]" << std::endl;
	std::cout << "max( i, j ) = " << ::max( i, j ) << " [ADDR = " << &::max( i, j ) << "]" << std::endl;

	std::cout << std::endl;
	//std::cout << "------------------INT vs FLOAT--------------------" << std::endl;

	/*
	*	Not the same type: 
	*	the compiler refuses!
	*/
	
	// std::cout << "[BEFORE SWAP] a = " << a << ", f = " << f << std::endl;
	// ::swap(a, f);
	// std::cout << "[AFTER SWAP] a = " << a << ", f = " << f << std::endl;
	// std::cout << "min( a, f ) = " << ::min( a, f ) << std::endl;
	// std::cout << "max( a, f ) = " << ::max( a, f ) << std::endl;


	return 0;
}