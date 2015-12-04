#include "Float.hpp"

Float::Float(void)
{
	return ;
}

Float::Float( eOperandType type, std::string value )
{
	this->_type = type;
	this->_value = value;
}

Float::Float(Float const & ofloat)
{
	*this = ofloat;
	return ;
}

Float::~Float( void )
{
	return ;
}

IOperand & 		Float::operator=(Float const & ofloat)
{
	if ( this != &ofloat )
	{

	}

	return *this;
}

IOperand const * Float::operator+(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Float::operator-(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Float::operator*(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Float::operator/(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Float::operator%(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

std::string const & Float::toString( void ) const
{
	return (this->_value);
}

int				Float::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Float::getType(void) const
{
	return FLOAT;
}

std::string		Float::getValue(void) const
{
	return this->_value;
}