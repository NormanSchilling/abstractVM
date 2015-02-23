/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:44:19 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/23 17:31:12 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

class Command
{
	public:
		Command(void);
		Command(Command const & command);
		~Command(void);

		Command & 				operator=(Command const & command);

		void					parser(std::string line);
		int						numberString(std::string line, char separator);
		std::string				getFirstString(std::string line, char separator);
		std::string				getSecondString(std::string line, char separator);					

		void					parse_push(std::string line);
		void					parse_exit();

	private:
		std::string				firstString;
		std::string				secondString;
};

#endif