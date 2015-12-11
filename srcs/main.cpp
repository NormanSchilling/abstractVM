#include <fstream>
#include <string>

#include "Command.hpp"
#include "Abstractvm.hpp"

int		main(int argc, char const **argv)
{
	Command			command;
	Abstractvm		*abstractvm;
	std::string		line;

	std::ifstream myfile(argv[1]);
	if (myfile && argc == 2)
	{
		while (getline( myfile, line ))
		{
			try
			{
				command.parser(line);
			}
			catch (Errors & e)
			{
				e.display();
				exit(-1);
			}
		}
		myfile.close();
		abstractvm = new Abstractvm(command.getListCommand());
		abstractvm->manager();
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
