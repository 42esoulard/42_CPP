/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:34:17 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/14 12:57:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayT.hpp"

int main(void) {
	
	std::cout << std::endl << "-------------------------------------" << std::endl;
	std::cout << "--------PRINT STRING ARRAY[3]--------" << std::endl << std::endl;

	Array< std::string > strArray(3);

	std::cout << "[INIT BY DEFAULT]" << std::endl;
	for (int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;

	strArray[0] = "omg im a string";
	strArray[1] = "omg me too";
	strArray[2] = "im not a string, im a panda";

	std::cout << "[AFTER ASSIGNING]" << std::endl;
	for (int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;

	std::cout << std::endl << "-----------------------------------" << std::endl;
	std::cout << "--------DEFAULT CONSTRUCTOR--------" << std::endl << std::endl;

	Array< std::string > emptyStrArray;

	std::cout << "[INIT BY DEFAULT]" << std::endl;
	for (int i = 0; i < emptyStrArray.size(); i++)
		std::cout << emptyStrArray[i] << std::endl;

	std::cout << std::endl << "----------------------------------------" << std::endl;
	std::cout << "--------OPERATOR= ON EMPTY ARRAY--------" << std::endl << std::endl;
	emptyStrArray = strArray;

	for (int i = 0; i < emptyStrArray.size(); i++)
		std::cout << emptyStrArray[i] << std::endl;

	std::cout << std::endl << "---------------------------------------" << std::endl;
	std::cout << "--------OPERATOR= ON FULL ARRAY--------" << std::endl << std::endl;
	Array< std::string > anotherStrArray(1);

	anotherStrArray[0] = "A BOOMBOX IS NOT A TOY!!!";

	strArray = anotherStrArray;
	for (int i = 0; i < anotherStrArray.size(); i++)
		std::cout << anotherStrArray[i] << std::endl;

	for (int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;

	std::cout << std::endl;
	std::cout << "[MODIFYING ONE DOESNT AFFECT THE OTHER]" << std::endl << std::endl;

	strArray[0] = "AFRIDIBIDIHUUUU!";

	for (int i = 0; i < anotherStrArray.size(); i++)
		std::cout << anotherStrArray[i] << std::endl;
	for (int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << std::endl;

	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << "--------COPY CONSTRUCTOR--------" << std::endl << std::endl;
	Array< std::string > copiedStrArray(anotherStrArray);

	for (int i = 0; i < copiedStrArray.size(); i++)
		std::cout << copiedStrArray[i] << std::endl;

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << "--------PRINT INT ARRAY[5]--------" << std::endl << std::endl;
	std::cout << std::endl;
	Array< int > 	a(5);

	std::cout << "[INIT BY DEFAULT]" << std::endl;
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
	Array< float > 	sneakyFloat(2);

	std::cout << "[INIT BY DEFAULT]" << std::endl;
	for (int i = 0; i < sneakyFloat.size(); i++)
		std::cout << sneakyFloat[i] << std::endl;
	
	std::cout << std::endl << "-----------------------------------------------" << std::endl;
	std::cout << "--------ITERATE & MODIFY FLOAT ARRAY[2]--------" << std::endl << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < sneakyFloat.size(); i++) {
		sneakyFloat[i] += i;
		std::cout << sneakyFloat[i] << std::endl;
	}

	std::cout << std::endl << "-----------------------------------" << std::endl;
	std::cout << "--------BAD INDEX EXCEPTION--------" << std::endl << std::endl;
	try {
		std::cout << "Array a size <" << a.size() << ">, getting index <2>..." << std::endl;
		std::cout << a[2] << std::endl;
		std::cout << "Index 2 successfully retrieved!" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Array a size <" << a.size() << ">, getting index <42>..." << std::endl;
		std::cout << a[42] << std::endl;
		std::cout << "Index 42 successfully retrieved!" << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}