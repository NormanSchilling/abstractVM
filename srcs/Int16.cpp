#include "Int16.hpp"

Int16::Int16(void)
{
	return ;
}

Int16::Int16( eOperandType type, std::string value )
{
	this->_type = type;
	this->_value = value;
	std::cout << "create Int16" << std::endl;
}

Int16::Int16(Int16 const & int16)
{
	*this = int16;
	return ;
}

Int16::~Int16( void )
{
	return ;
}

IOperand & 		Int16::operator=(Int16 const & int16)
{
	if ( this != &int16 )
	{

	}

	return *this;
}

IOperand const * Int16::operator+(IOperand const & rhs) const
{
	(void)rhs;
	return  this;
}

IOperand const * Int16::operator-(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int16::operator*(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int16::operator/(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int16::operator%(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

// std::string const & Int16::toString( void )
// {

// }

int			Int16::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Int16::getType(void) const
{
	return INT16;
}
