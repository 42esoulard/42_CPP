/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayT.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:25:49 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/13 17:10:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYT_HPP
#define ARRAYT_HPP

#include <iostream>

template<typename T>
class Array {
	
	public:

		Array<T>(void) : _array(nullptr), _size(0) {};

		Array<T>(unsigned int n) : _size(n) { 
			_array = new T[n](); 

		};

		Array<T>(Array<T> const &src) : _size(0) { 
			*this = src; 
		};

		~Array<T>( void ){ 
			if (_size) 
				delete[] _array; 
		};


		//----------------------------------
		//			   OPERATORS
		//----------------------------------

		void operator=(Array<T> const &rhs) {

			if (size())
				delete[] _array;
			_size = rhs.size();
			if (_size) {
				_array = new T[_size]();

				for (int i = 0; i < _size; i++)
					_array[i] = rhs[i];
			}
		};

		T  & operator[](int const &index) const {
			
			// std::cout << "Calling operator[]" << std::endl;
			if (index > _size)
				throw customException("Element doesn't exist!");
			return _array[index];
		};

		
		//----------------------------------
		//			   GETTERS
		//----------------------------------
		
		size_t const	 &size() const { 
			return _size;
		};

	
		//----------------------------------
		//			   EXCEPTIONS
		//----------------------------------

		class customException : public std::exception {
			
			public:
				customException(std::string const &str) : _err(str) {};
				virtual char const *what() const throw() { return _err.c_str(); };
			
			protected:
				std::string const _err;	
		};


	private:

		T 		*_array;
		size_t 	_size;
};

#endif
