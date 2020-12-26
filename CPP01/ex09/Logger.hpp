/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:33:51 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 15:38:46 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <iostream>

class Logger {
	
	public:

		Logger(std::string FileName);
		~Logger(void);

		void 				log(std::string const &dest, std::string const &message);

	private:

		void 				logToConsole(std::string const &str);
		void 				logToFile(std::string const &str);
	
		std::string			makeLogEntry(std::string const str);
	
		std::string 		_logFileName;
		static std::string 	_logFunctionNames[2];
	
		typedef void(Logger::*logPtrType)(std::string const &);
		static logPtrType 	_logPtr[2];
};


#endif