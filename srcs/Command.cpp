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
		assignString(line);
		if (this->numberString(line, ' ') == 2)
		{
			if (this->checkCommandWithValue() == 1)
			{
				std::cout << this->firstString << " " <<  this->secondString << std::endl;
			}
		}
		else if (this->checkCommand() == 1)
		{
			std::cout << this->firstString << std::endl;
		}
	}
}

void				Command::assignString(std::string line)
{
	char	*dup;
	char	*token;
	int		i;

	i = 1;
	dup = strdup(line.c_str());
	token = strtok(dup, " ");
	while(token != NULL)
	{
		if (i == 1)
			this->firstString = token;
		if (i == 2)
			this->secondString = token;
		token = strtok(NULL, " ");
		i++;
	}
	free(dup);
}

int					Command::checkCommandWithValue( void )
{
	std::string		cmdWithValue[] = {"push", "assert"};

	for (int i = 0; i < 2; i++)
	{
		if (cmdWithValue[i] == this->firstString)
			return (1);
	}
	return (0);
}

int					Command::checkCommand( void )
{
	std::string		cmd[] =	{"pop", "dump", "add", "sub", "mul",
							"div","mod", "print", "exit"};

	for (int i = 0; i < 9; i++)
	{
		if (cmd[i] == this->firstString)
			return (1);
	}
	return (0);
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