#include "Abstractvm.hpp"

Abstractvm::Abstractvm(void)
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
