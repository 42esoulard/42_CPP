/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:37:05 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/25 13:49:31 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>
#include "customException.hpp"

class Span {

	public:

		Span(unsigned int const N);
		Span(Span const &src);
		~Span(void);

		Span & operator=(Span const &rhs);

		void 		addNumber(int const &nb);
		
		template <typename iterator>
		void 	addNumber(iterator &ita, iterator &itb) {

			int i = 0;

			if (std::distance(ita, itb) > _size - _tab.size())
				throw customException("Range won't fit this Span instance :(");
			
			for (ita; ita != itb; ita++) {
				_tab.push_back(*ita);
			}
		};

		int const 	shortestSpan(void);
		int const 	longestSpan(void);

		std::list<int> const &getTab(void) const;

	private:

		Span(void);
		std::list<int> _tab;
		int _size;


};

std::ostream & operator<<(std::ostream &o, Span const &rhs);

#endif
