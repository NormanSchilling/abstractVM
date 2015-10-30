#include "Float.hpp"

Float::Float(void)
{
	return ;
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

IOperand const * Float::operator+(Float const & rhs)
{
	this->_precision += rhs._precision;
	return  this;
}

IOperand const * Float::operator-(Float const & rhs)
{
	this->_precision -= rhs._precision;
	return this;
}

IOperand const * Float::operator*(Float const & rhs)
{
	this->_precision *= rhs._precision;
	return this;
}

IOperand const * Float::operator/(Float const & rhs)
{
	this->_precision /= rhs._precision;
	return this;
}

IOperand const * Float::operator%(Float const & rhs)
{
	this->_precision %= rhs._precision;
	return this;
}

// std::string const & Float::toString( void )
// {

// }

int			Float::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Float::getType(void) const
{
	return this->_type;
}
