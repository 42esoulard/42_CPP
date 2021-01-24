/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 19:38:12 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/24 16:50:02 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main(void) {
	
	MutantStack<int> mstack;
	std::cout << "------------" << std::endl;
	std::cout << "PUSH 5/17 TOP" << std::endl;
	std::cout << "------------" << std::endl;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	std::cout << "Size before pop: " << mstack.size() << std::endl;
	mstack.pop();
	
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	
	std::cout << "------------" << std::endl;
	std::cout << "PUSH 3/5/737/0" << std::endl;
	std::cout << "------------" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	
	std::cout << "------------" << std::endl;
	std::cout << "ITERATING ON MSTACK, +TOP" << std::endl;
	std::cout << "------------" << std::endl;
	
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << mstack.top() << std::endl;


	std::cout << "------------" << std::endl;
	std::cout << "INIT STD::STACK FROM MSTACK, +TOP" << std::endl;
	std::cout << "------------" << std::endl;
	
	std::stack<int> s(mstack);

	std::cout << s.top() << std::endl;

	std::cout << "------------" << std::endl;
	std::cout << "POP ALL OF MSTACK" << std::endl;
	std::cout << "------------" << std::endl;

	int tmp = mstack.size();
	for (int i = 0; i < tmp; i++)
		mstack.pop();

	it = mstack.begin();
	ite = mstack.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "------------" << std::endl;
	std::cout << "INIT MSTACK COPY FROM EMPTY MSTACK" << std::endl;
	std::cout << "------------" << std::endl;
	
	MutantStack<int> blou(mstack);

	std::cout << "------------" << std::endl;
	std::cout << "FILL MSTACK COPY 0-10 +ITERATE" << std::endl;
	std::cout << "------------" << std::endl;

	for (int i = 0; i <= 10; i++)
		blou.push(i);

	it = blou.begin();
	ite = blou.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "------------" << std::endl;
	std::cout << "SWAP 0-10 MSTACK WITH EMPTY" << std::endl;
	std::cout << "------------" << std::endl;

	MutantStack<int> sup;
	sup.swap(blou);

	it = blou.begin();
	ite = blou.end();

	std::cout << "OLD ONE:" << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	it = sup.begin();
	ite = sup.end();

	std::cout << "NEW ONE:" << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}


	return 0;
}