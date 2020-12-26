/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:32:38 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:36:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int error_msg(const std::string err) {
	std::cout << err << std::endl;
	std::cout << "Try : ./replace [VALID_FILENAME][''STRING TO REPLACE''][''NEW STRING'']" << std::endl
	<< std::endl;
	return 1;
}

int main (int ac, char **av) {

	if (ac != 4)
		return error_msg("Wrong number of parameters!");
	
	std::ifstream ifs(av[1]);
	if (ifs.fail())
		return error_msg("Couldn't open input file!");
	
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (!s1.length() || !s2.length())
		return error_msg("Can't use an empty string!");
	
	std::ofstream ofs(std::string(av[1]) + ".replace");
	if (ofs.fail())
		return error_msg("Couldn't open input file!");
	
	std::string line;
	int 		res;
	int 		count = 0;
	while (getline(ifs, line)) {
		res = -1;
		while ((res = line.find(s1)) >= 0) {
			line.replace(res, s1.length(), s2);
			count++;
		}
		ofs << line << std::endl;
	}

	ifs.close();
	ofs.close();

	std::cout << "Successfully copied content of " <<
		av[1] << " to " << av[1] << ".replace" << std::endl;
		std::cout << count << " occurences of [" << s1 <<
		"] were found and replaced by [" << s2 << "] ! " << std::endl;
		
	return 0;
}

//stdstdstd