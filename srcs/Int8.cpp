#include "Int8.hpp"

Int8::Int8(void)
{
	return ;
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

IOperand const * Int8::operator+(Int8 const & rhs)
{
	this->_precision += rhs._precision;
	return  this;
}

IOperand const * Int8::operator-(Int8 const & rhs)
{
	this->_precision -= rhs._precision;
	return this;
}

IOperand const * Int8::operator*(Int8 const & rhs)
{
	this->_precision *= rhs._precision;
	return this;
}

IOperand const * Int8::operator/(Int8 const & rhs)
{
	this->_precision /= rhs._precision;
	return this;
}

IOperand const * Int8::operator%(Int8 const & rhs)
{
	this->_precision %= rhs._precision;
	return this;
}

// std::string const & Int8::toString( void )
// {

// }

int				Int8::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Int8::getType(void) const
{
	return this->_type;
}
