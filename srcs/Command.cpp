#include "Command.hpp"

Command::Command(void)
{
	exitInit = 0;
	return ;
}

Command::Command(Command const & command)
{
	exitInit = 0;
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
			if (this->checkCommandWithValue() == 1 && this->checkTypeValue() == 1
				&& this->checkValue() == 1)
			{
				command = this->firstString + " " + this->secondString;
				listCommand.push_back(command);
			}
			else
				throw Errors("An instruction is unknown");
		}
		else if (this->checkCommand() == 1)
		{
			command = this->firstString;
			listCommand.push_back(command);
		}
		else
			throw Errors("An instruction is unknown");
	}

}

void				Command::assignString(std::string line)
{
	int i = 0;
	int pos = line.find(" ");
	this->firstString = line.substr(i, pos - i);
	this->secondString = line.substr(pos + 1, line.length() );
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

int					Command::checkTypeValue( void )
{
	std::string		typeValue[] = {"int8", "int16", "int32", "float", "double"};
	std::string		type;

	int i = 0;
	int pos = this->secondString.find("(");
	type = this->secondString.substr(i, pos - i);
	for (int i = 0; i < 5; i++)
	{
		if (typeValue[i] == type)
			return (1);
	}
	return (0);
}

int					Command::checkValue( void )
{
	std::string		value;

	int pos = this->secondString.find("(");
	value = this->secondString.substr(pos, this->secondString.length());
	std::string s = value;
	std::regex e ("[(]{1,1}[-]{0,1}[0-9]{1,}[.]{0,1}[0-9]{0,}[)]{1,1}");
	if (std::regex_match (s,e))
		return (1);
	return (0);
}

int					Command::checkCommand( void )
{
	std::string		cmd[] =	{"pop", "dump", "add", "sub", "mul",
							"div","mod", "print", "exit"};

	for (int i = 0; i < 9; i++)
	{
		if (this->firstString == "exit")
			exitInit = 1;
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

std::vector<std::string>		Command::getListCommand()
{
	return this->listCommand;
}

