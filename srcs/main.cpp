#include <fstream>
#include <string>

#include "Command.hpp"

int		main(int argc, char const **argv)
{
	Command command;
	std::string line;

	std::ifstream myfile(argv[1]);
	if (myfile && argc == 2)
	{
		while (getline( myfile, line ))
		{
			command.parser(line);
		}
		myfile.close();
	}
	else
	{
		while (getline( std::cin, line ))
		{
			std::cout << line << std::endl;
		}
	}
	return 0;
}
