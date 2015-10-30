#include "Double.hpp"

Double::Double(void)
{
	return ;
}

Double::Double(Double const & odouble)
{
	*this = odouble;
	return ;
}

Double::~Double( void )
{
	return ;
}

IOperand & 		Double::operator=(Double const & odouble)
{
	if ( this != &odouble )
	{

	}

	return *this;
}

IOperand const * Double::operator+(Double const & rhs)
{
	this->_precision += rhs._precision;
	return  this;
}

IOperand const * Double::operator-(Double const & rhs)
{
	this->_precision -= rhs._precision;
	return this;
}

IOperand const * Double::operator*(Double const & rhs)
{
	this->_precision *= rhs._precision;
	return this;
}

IOperand const * Double::operator/(Double const & rhs)
{
	this->_precision /= rhs._precision;
	return this;
}

IOperand const * Double::operator%(Double const & rhs)
{
	this->_precision %= rhs._precision;
	return this;
}

// std::string const & Double::toString( void )
// {

// }

int			Double::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Double::getType(void) const
{
	return this->_type;
}
