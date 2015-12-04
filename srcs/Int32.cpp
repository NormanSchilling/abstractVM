#include "Int32.hpp"

Int32::Int32(void)
{
	return ;
}

Int32::Int32( eOperandType type, std::string value )
{
	this->_type = type;
	this->_value = value;
}

Int32::Int32(Int32 const & int32)
{
	*this = int32;
	return ;
}

Int32::~Int32( void )
{
	return ;
}

IOperand & 		Int32::operator=(Int32 const & int32)
{
	if ( this != &int32 )
	{

	}

	return *this;
}

IOperand const * Int32::operator+(IOperand const & rhs) const
{
	(void)rhs;
	return  this;
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int32::operator*(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

std::string const & Int32::toString( void ) const
{
	return (this->_value);
}

int				Int32::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Int32::getType(void) const
{
	return INT32;
}

std::string		Int32::getValue(void) const
{
	return this->_value;
}
