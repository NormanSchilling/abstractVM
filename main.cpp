/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:56:57 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/23 16:12:57 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>

#include "Command.hpp"

int		main(int argc, char const **argv)
{
	Command command;
	std::string line;

	std::ifstream myfile(argv[1]);
	if (myfile && argc == 2)  // same as: if (myfile.good())
	{
		while (getline( myfile, line ))  // same as: while (getline( myfile, line ).good())
		{
			command.parser(line);
		}
		myfile.close();
	}
	else
	{
		while (getline( std::cin, line ))  // same as: while (getline( myfile, line ).good())
		{
			std::cout << line << std::endl;				
		}
	}
	return 0;
}
