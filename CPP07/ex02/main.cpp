/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:34:17 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/13 17:18:35 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayT.hpp"

int main(void) {
	
	std::cout << std::endl << "-------------------------------------" << std::endl;
	std::cout << "--------PRINT STRING ARRAY[3]--------" << std::endl << std::endl;

	Array< std::string > blou(3);

	std::cout << "[EMPTY]" << std::endl;
	for (int i = 0; i < blou.size(); i++)
		std::cout << blou[i] << std::endl;

	blou[0] = "omg im a string";
	blou[1] = "omg me too";
	blou[2] = "im not a string, im a panda";

	std::cout << "[FULL]" << std::endl;
	for (int i = 0; i < blou.size(); i++)
		std::cout << blou[i] << std::endl;

	std::cout << std::endl << "-----------------------------------" << std::endl;
	std::cout << "--------DEFAULT CONSTRUCTOR--------" << std::endl << std::endl;

	Array< std::string > bla;

	std::cout << "[EMPTY]" << std::endl;
	for (int i = 0; i < bla.size(); i++)
		std::cout << bla[i] << std::endl;

	std::cout << std::endl << "----------------------------------------" << std::endl;
	std::cout << "--------OPERATOR= ON EMPTY ARRAY--------" << std::endl << std::endl;
	bla = blou;

	for (int i = 0; i < bla.size(); i++)
		std::cout << bla[i] << std::endl;

	std::cout << std::endl << "---------------------------------------" << std::endl;
	std::cout << "--------OPERATOR= ON FULL ARRAY--------" << std::endl << std::endl;
	Array< std::string > blep(1);

	blep[0] = "A BOOMBOX IS NOT A TOY!!!";

	blou = blep;
	for (int i = 0; i < blou.size(); i++)
		std::cout << blou[i] << std::endl;

	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << "--------COPY CONSTRUCTOR--------" << std::endl << std::endl;
	Array< std::string > flap(blep);

	for (int i = 0; i < flap.size(); i++)
		std::cout << flap[i] << std::endl;

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "--------PRINT INT ARRAY[5]--------" << std::endl << std::endl;
	std::cout << std::endl;
	Array< int > 	a(5);

	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	
	std::cout << std::endl << "---------------------------------------------" << std::endl;
	std::cout << "--------ITERATE & MODIFY INT ARRAY[5]--------" << std::endl << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < a.size(); i++) {
		a[i] += i;
		std::cout << a[i] << std::endl;
	}
	
	std::cout << std::endl << "------------------------------------" << std::endl;
	std::cout << "--------PRINT FLOAT ARRAY[2]--------" << std::endl << std::endl;
	std::cout << std::endl;
	Array< float > 	sneak(2);

	for (int i = 0; i < sneak.size(); i++)
		std::cout << sneak[i] << std::endl;
	
	std::cout << std::endl << "-----------------------------------------------" << std::endl;
	std::cout << "--------ITERATE & MODIFY FLOAT ARRAY[2]--------" << std::endl << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < sneak.size(); i++) {
		sneak[i] += i;
		std::cout << sneak[i] << std::endl;
	}

	std::cout << std::endl << "-----------------------------------" << std::endl;
	std::cout << "--------BAD INDEX EXCEPTION--------" << std::endl << std::endl;
	try {
		std::cout << "Array a size " << a.size() << ", getting index 42" << std::endl;
		std::cout << a[42] << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}