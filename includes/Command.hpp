#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>
#include <regex>

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
		int						checkTypeValue(void);
		int						checkValue(void);
		void					assignString(std::string line);

	private:
		std::string				firstString;
		std::string				secondString;
};

#endif