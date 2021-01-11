/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:26:09 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 17:44:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <limits>

typedef struct Data { 

	std::string s1; 
	int n; 
	std::string s2; 
}				Data;

void *serialize(void) {
	
	Data *data = new Data;

	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

	std::string s1;
	for (int i = 0; i < 8; i++)
		s1 += alphanum[rand() % (sizeof(alphanum) - 1)];
	
	std::string s2;
	for (int i = 0; i < 8; i++)
		s2 += alphanum[rand() % (sizeof(alphanum) - 1)];

	int n = rand();


	data->s1 = s1;
	data->n = n;
	data->s2 = s2;

	std::cout << "DATA TO SERIALIZE" << std::endl;
	std::cout << "ADDR: [" << &data->s1 << "] " << data->s1 << std::endl;
	std::cout << "ADDR: [" << &data->n << "] " << data->n << std::endl;
	std::cout << "ADDR: [" << &data->s2 << "] " << data->s2 << std::endl;

	//we send back a void ptr to the data
	return reinterpret_cast<void *>(data);
}

/*
* reinterpret_cast is used to requalify
* a void pointer.
* /!\ careful, it is very permissive
*/

Data *deserialize(void *raw) {

	Data *data = reinterpret_cast<Data *>(raw);

	return data;
}

int main(void) {

	srand(time(NULL));

	void *ptr = serialize();

	std::cout << std::endl;
	std::cout << "SERIALIZED DATA PTR" << std::endl;
	std::cout << "ADDR: [" << ptr << "] " << std::endl;

	Data *data = deserialize(ptr);

	std::cout << std::endl;
	std::cout << "DESERIALIZED DATA" << std::endl;
	std::cout << "ADDR: [" << &data->s1 << "] " << data->s1 << std::endl;
	std::cout << "ADDR: [" << &data->n << "] " << data->n << std::endl;
	std::cout << "ADDR: [" << &data->s2 << "] " << data->s2 << std::endl;

	delete data;

	return 0;
}