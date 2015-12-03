#include "Abstractvm.hpp"

Abstractvm::Abstractvm(void)
{
	return ;
}

Abstractvm::Abstractvm(std::vector<std::string> listCommand) : listCommand(listCommand)
{
	return ;
}

Abstractvm::Abstractvm(Abstractvm const & abstractvm)
{
	*this = abstractvm;
	return ;
}

Abstractvm::~Abstractvm(void)
{
	return ;
}

Abstractvm & 		Abstractvm::operator=(Abstractvm const & abstractvm)
{
	if ( this != &abstractvm )
	{

	}

	return *this;
}

void		Abstractvm::manager(void)
{
	// this->displayCommands();
	this->managerCommands();

}

void		Abstractvm::managerCommands(void)
{
	int			i;
	int			pos;
	std::string	cmd;
	std::string		arrayCommands[11] = {
		"push", "assert", "pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"
	};

	std::map<std::string, executeCommand> execCommands = {
		{arrayCommands[0], &Abstractvm::push},
		{arrayCommands[1], &Abstractvm::assert},
		{arrayCommands[2], &Abstractvm::pop},
		{arrayCommands[3], &Abstractvm::dump},
		{arrayCommands[4], &Abstractvm::add},
		{arrayCommands[5], &Abstractvm::sub},
		{arrayCommands[6], &Abstractvm::mul},
		{arrayCommands[7], &Abstractvm::div},
		{arrayCommands[8], &Abstractvm::mod},
		{arrayCommands[9], &Abstractvm::print},
		{arrayCommands[10], &Abstractvm::exit}
	};
	std::vector<std::string>::iterator					it;
	std::map<std::string, executeCommand>::iterator		itmap;

	for ( it = this->listCommand.begin() ; it != this->listCommand.end(); ++it )
	{
		cmd = *it;
		i = 0;
		pos = cmd.find(" ");
		cmd = cmd.substr(i, pos - i);
		executeCommand exec = execCommands.at(cmd);
		(this->*exec)(*it);
	}
}

void		Abstractvm::displayCommands(void)
{
	std::vector<std::string>::iterator		it;

	for ( it = this->listCommand.begin() ; it != this->listCommand.end(); ++it )
	{
		std::cout << *it << std::endl;
	}
}

void		Abstractvm::assignString(std::string command)
{
	int i = 0;
	int pos = command.find(" ");
	this->firstString = command.substr(i, pos - i);
	this->secondString = command.substr(pos + 1, command.length() );
}

void		Abstractvm::assignType()
{
	int i = 0;
	int pos = this->secondString.find("(");
	this->type = this->secondString.substr(i, pos - i);
}

void		Abstractvm::assignValue()
{
	int pos = this->secondString.find("(");
	int secondPos = this->secondString.find(")") - 1;
	this->value = this->secondString.substr(pos + 1, secondPos - pos);
}

void		Abstractvm::push(std::string command)
{
	createOperand		create;

	this->assignString(command);
	this->assignType();
	this->assignValue();
	create = &Abstractvm::createInt8;
	(this->*create)(this->value);
}
void		Abstractvm::assert(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::pop(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::dump(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::add(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::sub(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::mul(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::div(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::mod(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::print(std::string command)
{
	std::cout << command << std::endl;
}
void		Abstractvm::exit(std::string command)
{
	std::cout << command << std::endl;
}

IOperand const	*Abstractvm::createInt8( std::string const &value ) const
{
	std::cout << value << std::endl;
	return (new Int8(INT8, value));
}