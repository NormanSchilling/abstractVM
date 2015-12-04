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
		{arrayCommands[9], &Abstractvm::printOp},
		{arrayCommands[10], &Abstractvm::exitOp}
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
		if ((this->*exec)(*it) == -1)
			exit(-1);
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

void		Abstractvm::displayStack(void)
{
	std::vector<IOperand const *>::iterator		itOperand;

	for ( itOperand = this->stack.begin() ; itOperand != this->stack.end(); ++itOperand )
	{
		std::cout << (*itOperand)->toString() << std::endl;
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

int		Abstractvm::push(std::string command)
{
	std::string		arrayTypeValue[5] = {
		"int8", "int16", "int32", "float", "double"
	};

	std::map<std::string, eOperandType> geteOperandType = {
		{arrayTypeValue[0], INT8},
		{arrayTypeValue[1], INT16},
		{arrayTypeValue[2], INT32},
		{arrayTypeValue[3], FLOAT},
		{arrayTypeValue[4], DOUBLE}
	};
	eOperandType		currentType;

	this->assignString(command);
	this->assignType();
	this->assignValue();
	currentType = geteOperandType.at(this->type);
	this->currentOperand = this->createOperand(currentType, this->value);
	this->stack.push_back(this->currentOperand);
	// this->stack.insert(this->stack.begin(), this->currentOperand);
	return (0);
}
int		Abstractvm::assert(std::string command)
{
	std::string		arrayTypeValue[5] = {
		"int8", "int16", "int32", "float", "double"
	};

	std::map<std::string, eOperandType> geteOperandType = {
		{arrayTypeValue[0], INT8},
		{arrayTypeValue[1], INT16},
		{arrayTypeValue[2], INT32},
		{arrayTypeValue[3], FLOAT},
		{arrayTypeValue[4], DOUBLE}
	};
	eOperandType		currentType;
	std::vector<IOperand const *>::iterator	topStack = this->stack.end();

	this->assignString(command);
	this->assignType();
	this->assignValue();

	currentType = geteOperandType.at(this->type);
	if (currentType != (*topStack)->getType() || this->value != (*topStack)->toString())
	{
		std::cout << "Error : assert" << std::endl;
		return (-1);
	}
	return (0);
}
int		Abstractvm::pop(std::string command)
{
	if (this->stack.size() == 0)
	{
		std::cout << "Error : " << command << std::endl;
		return (-1);
	}
	else
		this->stack.pop_back();
	return (0);
}
int		Abstractvm::dump(std::string command)
{
	std::vector<IOperand const *>::iterator		itOperand;

	std::cout << command << std::endl;
	for ( itOperand = this->stack.end() ; itOperand-- != this->stack.begin(); )
	{
		std::cout << (*itOperand)->toString() << std::endl;
	}
	return (0);
}
int		Abstractvm::add(std::string command)
{
	std::cout << command << std::endl;
	return (0);
}
int		Abstractvm::sub(std::string command)
{
	std::cout << command << std::endl;
	return (0);
}
int		Abstractvm::mul(std::string command)
{
	std::cout << command << std::endl;
	return (0);
}
int		Abstractvm::div(std::string command)
{
	std::cout << command << std::endl;
	return (0);
}
int		Abstractvm::mod(std::string command)
{
	std::cout << command << std::endl;
	return (0);
}
int		Abstractvm::printOp(std::string command)
{
	(void)command;
	std::vector<IOperand const *>::iterator	topStack = this->stack.end();

	if ((*topStack)->getType() != INT8)
	{
		std::cout << "Error : print" << std::endl;
		return (-1);
	}
	std::cout << this->value << std::endl;
	return (0);
}
int		Abstractvm::exitOp(std::string command)
{
	(void)command;
	return (-1);
}

IOperand const	*Abstractvm::createOperand( eOperandType type, std::string const & value ) const
{
	std::map<eOperandType, createOpe> createTypeValue = {
		{INT8, &Abstractvm::createInt8},
		{INT16, &Abstractvm::createInt16},
		{INT32, &Abstractvm::createInt32},
		{FLOAT, &Abstractvm::createFloat},
		{DOUBLE, &Abstractvm::createDouble}
	};
	createOpe		create;

	create = createTypeValue.at(type);
	return ((this->*create)(value));
}

IOperand const	*Abstractvm::createInt8( std::string const &value ) const
{
	return (new Int8(INT8, value));
}

IOperand const	*Abstractvm::createInt16( std::string const &value ) const
{
	return (new Int16(INT16, value));
}

IOperand const	*Abstractvm::createInt32( std::string const &value ) const
{
	return (new Int32(INT32, value));
}

IOperand const	*Abstractvm::createFloat( std::string const &value ) const
{
	return (new Float(FLOAT, value));
}

IOperand const	*Abstractvm::createDouble( std::string const &value ) const
{
	return (new Double(DOUBLE, value));
}
