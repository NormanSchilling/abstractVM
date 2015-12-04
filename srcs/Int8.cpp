#include "Int8.hpp"

Int8::Int8(void)
{
	return ;
}

Int8::Int8( eOperandType type, std::string value )
{
	this->_type = type;
	this->_value = value;
}

Int8::Int8(Int8 const & int8)
{
	*this = int8;
	return ;
}

Int8::~Int8( void )
{
	return ;
}

IOperand & 		Int8::operator=(Int8 const & int8)
{
	if ( this != &int8 )
	{

	}

	return *this;
}

IOperand const * Int8::operator+(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int8::operator-(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int8::operator*(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int8::operator/(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int8::operator%(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

std::string const & Int8::toString( void ) const
{
	return (this->_value);
}

int				Int8::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Int8::getType(void) const
{
	return INT8;
}

std::string		Int8::getValue(void) const
{
	return this->_value;
}