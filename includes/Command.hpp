#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Command
{
	public:
		Command(void);
		Command(Command const & command);
		~Command(void);

		Command & 				operator=(Command const & command);

		void					parser(std::string line);
		int						numberString(std::string line, char separator);
		int						checkCommandWithValue( void );
		int						checkCommand( void );
		void					assignString(std::string line);

	private:
		std::string				firstString;
		std::string				secondString;
};

#endif