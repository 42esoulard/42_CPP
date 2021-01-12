/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex_classT.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:47:10 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/12 12:05:54 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

//on peut avoir un type par défaut
template< typename T = float >
class Vertex {

	public:
		Vertex(T const & x, T const & y, T const & z) : _x(x), _y(y), _z(z){};
		~Vertex(){};

		T const & getx(void) const {return this->_x;}
		T const & gety(void) const {return this->_y;}
		T const & getz(void) const {return this->_z;}

		//[...etc]

	private:
		T const _x;
		T const _y;
		T const _z;

		Vertex(void);
};

template <typename T>
std::ostream & operator<<(std::ostream &o, Vertex<T> const &v) {

	std::cout.precision(1);
	o << setiosflags(std::ios::fixed);
	o << "Vertex( ";
	o << v.getx() << ", ";
	o << v.gety() << ", ";
	o << v.getz() << ")";

	return o;
	

}