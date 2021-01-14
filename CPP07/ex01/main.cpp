/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:18:42 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/14 13:20:19 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void 	imJustARegularReadStrFunction(std::string &bla) {

	std::cout << bla << std::endl;
}

void 	imJustARegularReadIntFunction(int &bla) {

	std::cout << bla << std::endl;
}

int 	main(void) {

	std::string str_arr[] = {"abc", "def", "ghi"};

	std::cout << "[STD::STRING_ARRAY] " << std::endl;
	std::cout << "[-> with template function] " << std::endl;
	iter<std::string>(str_arr, 3, &read);
	std::cout << "[-> with regular function] " << std::endl;
	iter<std::string>(str_arr, 3, imJustARegularReadStrFunction);

	std::cout << "---------------------------" << std::endl;

	char char_arr[] = "abc";

	std::cout << "[CHAR_ARRAY] " << std::endl;
	iter<char>(char_arr, 3, &read);

	iter<char>(char_arr, 3, &increment);
	std::cout << "[AFTER ITER (increment)] " << std::endl;
	iter<char>(char_arr, 3, &read);


	std::cout << "---------------------------" << std::endl;

	int int_arr[] = {1,2,3};

	std::cout << "[INT_ARRAY] " << std::endl;
	std::cout << "[-> with template function] " << std::endl;
	iter<int>(int_arr, 3, &read);
	std::cout << "[-> with regular function] " << std::endl;
	iter<int>(int_arr, 3, imJustARegularReadIntFunction);


	iter<int>(int_arr, 3, &increment);
	std::cout << "[AFTER ITER (increment)] " << std::endl;
	iter<int>(int_arr, 3, &read);

	iter<int>(int_arr, 3, &multiply);
	std::cout << "[AFTER ITER (multiply *2)] " << std::endl;
	iter<int>(int_arr, 3, &read);


	std::cout << "---------------------------" << std::endl;

	float float_arr[] = {12.056f,225.1f,301.8f};

	std::cout << "[FLOAT_ARRAY] " << std::endl;
	iter<float>(float_arr, 3, &read);

	iter<float>(float_arr, 3, &increment);
	std::cout << "[AFTER ITER (increment)] " << std::endl;
	iter<float>(float_arr, 3, &read);
	
	iter<float>(float_arr, 3, &multiply);
	std::cout << "[AFTER ITER (multiply *2)] " << std::endl;
	iter<float>(float_arr, 3, &read);

	std::cout << "---------------------------" << std::endl;
	iter<std::string>(NULL, 3, &read);

	return 0;
}