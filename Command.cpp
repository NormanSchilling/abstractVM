/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:44:34 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/23 17:31:36 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(void)
{
	return ;
}

Command::Command(Command const & command)
{
	*this = command;
	return ;
}

Command::~Command(void)
{
	return ;
}

Command & 		Command::operator=(Command const & command)
{
	if ( this != &command )
	{

	}

	return *this;
}

void			Command::parser(std::string line)
{
	if ( line[0] != ';')
	{
		if (this->numberString(line, ' ') == 2)
		{
			if (this->getFirstString(line, ' ') == "push")
				std::cout << "2 :" << line << std::endl;
		}
		if (this->numberString(line, ' ') == 1)
		{
			std::cout << "1: " << line << std::endl;
		}
	}
}


int				Command::numberString(std::string line, char separator)
{
	int		numberString;

	numberString = 1;
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == separator)
			numberString++;
	}

	return numberString;
}

std::string		Command::getFirstString(std::string line, char separator)
{
	int				j;

	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == separator)
			j = i;
	}

	this->firstString = line.substr (0, j);
	return this->firstString;
}

std::string		Command::getSecondString(std::string line, char separator)
{
	int				j;

	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == separator)
			j = i + 1;
	}

	this->secondString = line.substr (j, line.length());
	return this->secondString;
}

void			Command::parse_push(std::string line)
{
	(void)line;
}

void			Command::parse_exit()
{
	exit(0);
}