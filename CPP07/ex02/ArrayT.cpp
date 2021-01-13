/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayT.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:27:17 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/13 16:06:30 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayT.hpp"

// DEFAULT CONSTRUCTOR
template<typename T>
Array<T>::Array(void) : _array(nullptr), _size(0) {
};

// CONSTRUCTOR WITH UINT PARAM
template<typename T>
Array<T>::Array(unsigned int n) : _size(n) { 
	
	_array = new T[n]; 
};

template<typename T>
Array<T>::~Array( void ){ 
	if (_size) 			
		delete[] _array; 	
};

// COPY CONSTR CALLS =
template<typename T>
Array<T>::Array(Array<T> const &src) { 

	*this = src; 
};


// = NEW ALLOCATION + COPY ONE ELEM AT A TIME
template<typename T>
void Array<T>::operator=(Array<T> const &rhs) {
			
	if (size())
		delete[] _array;
	_size = rhs.size();
	
	if (_size) {
		_array = new T[_size];

		for (int i = 0; i < _size; i++)
			_array[i] = rhs.getArray(i);
	}
};

template<typename T>
T  & Array<T>::operator[](int const &index) const {
			
	std::cout << "[Operator[] called]" << std::endl;
	if (index > _size)
		throw customException("Element doesn't exist!");
	return _array[index];
};

//-----------------GETTERS--------------------

template<typename T>
T const 		&Array<T>::getArray() const { 

	return this->_array; 
};

template<typename T>		
size_t const	&Array<T>::size() const { 

	return _size;
};
	

template<typename T>
char const 		*Array<T>::customException::what() const throw() {
  	
  	return _err.c_str(); 
};
			
