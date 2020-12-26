#ifndef INTEGER_EXAMPLE_HPP
# define INTEGER_EXAMPLE_HPP

#include <iostream>

class Integer {
	
	public:
		Integer(int const n);
		~Integer(void);

		int getValue(void) const;

		Integer & operator=(Integer const & rhs);
		//overload de l'opérateur d'assignation '=', rhs = rightHandSide
		// on renverra l'instance courante pour pouvoir faire des assignations chainées, du type a = b = c.
		//on fera instance.=(valeur);

		Integer operator+(Integer const & rhs) const;
		//overload de l'opérateur d'addition '+'
		// on renvoie une copie du résultat



	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);
//overload de l'operateur de redirection de flux

#endif