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
	std::map<std::string, executeCommand> execCommand = {
		{"push", &Abstractvm::push},
		{"assert", &Abstractvm::assert},
		{"pop", &Abstractvm::pop},
		{"dump", &Abstractvm::dump},
		{"add", &Abstractvm::add},
		{"sub", &Abstractvm::sub},
		{"mul", &Abstractvm::mul},
		{"div", &Abstractvm::div},
		{"mod", &Abstractvm::mod},
		{"print", &Abstractvm::print},
		{"exit", &Abstractvm::exit},
	};
	std::vector<std::string>::iterator					it;
	std::map<std::string, executeCommand>::iterator		itmap;

	for ( it = this->listCommand.begin() ; it != this->listCommand.end(); ++it )
	{
		std::cout << *it << std::endl;
	}

	// commande[mastring]()

 
// pour parcourir toutes les paires de la map
	for(itmap = execCommand.begin() ; itmap != execCommand.end() ; ++itmap)
	{
		itmap->first; // accede à la clé
		itmap->second; // accede à la valeur
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

void		Abstractvm::push(void)
{
	std::cout << "push" << std::endl;
}
void		Abstractvm::assert(void)
{
	std::cout << "assert" << std::endl;
}
void		Abstractvm::pop(void)
{
	std::cout << "pop" << std::endl;
}
void		Abstractvm::dump(void)
{
	std::cout << "dump" << std::endl;
}
void		Abstractvm::add(void)
{
	std::cout << "add" << std::endl;
}
void		Abstractvm::sub(void)
{
	std::cout << "sub" << std::endl;
}
void		Abstractvm::mul(void)
{
	std::cout << "mul" << std::endl;
}
void		Abstractvm::div(void)
{
	std::cout << "div" << std::endl;
}
void		Abstractvm::mod(void)
{
	std::cout << "mod" << std::endl;
}
void		Abstractvm::print(void)
{
	std::cout << "print" << std::endl;
}
void		Abstractvm::exit(void)
{
	std::cout << "exit" << std::endl;
}
