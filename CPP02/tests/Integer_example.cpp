#include "Integer_example.hpp"

Integer::Integer(int const n): _n(n) {
	std::cout << "Constructor called with value " << _n << std::endl;
};
	
Integer::~Integer(void){
	std::cout << "Destructor called with value " << this->_n << std::endl;
};

int Integer::getValue(void) const {
	return this->_n;
};

//surcharge de l'opérateur =
Integer & Integer::operator=(Integer const & rhs) {

	std::cout << "Assignation operator called from value " << this->_n
	<< " to value " << rhs.getValue() << std::endl;
	this->_n = rhs.getValue();

	return *this;//on return l'instance courante pour pouvoir enchainer plusieurs calculs
};


Integer Integer::operator+(Integer const & rhs) const {
	std::cout << "Addition operator called with " << this->_n
	<< " and " << rhs.getValue() << std::endl;
	return Integer(this->_n + rhs.getValue());//on retourne une nouvelle instance Integer avec le résultat
};


//overload de l'operateur de redirection de flux
std::ostream & Integer::operator<<(std::ostream & o, Integer const & rhs) {
	o << rhs.getValue();
	return o;
};