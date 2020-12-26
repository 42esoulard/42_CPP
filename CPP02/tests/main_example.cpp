
#include "Integer_example.hpp"
#include <iostream>

int main(){
	Integer x(30);
	Integer y(10);
	Integer z(0);

	//on fait appel a la surcharge d'opérateur << de Integer
	std::cout << "Value of x " << x << std::endl;
	std::cout << "Value of y " << y << std::endl;
	y = Integer(12);// on surcharge l'opérateur d'assignation
	std::cout << "Value of y " << y << std::endl;
	std::cout << "Value of z " << z << std::endl;
	z = x + y;// on surchage les opérateurs d'addition et d'assignation
	std::cout << "Value of z " << z << std::endl;

	return 0;
}