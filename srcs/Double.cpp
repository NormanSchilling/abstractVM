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

IOperand const * Double::operator+(IOperand const & rhs) const
{
	(void)rhs;
	return  this;
}

IOperand const * Double::operator-(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Double::operator*(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Double::operator/(IOperand const & rhs) const
{
	(void)rhs;
	return this;
}

IOperand const * Double::operator%(IOperand const & rhs) const
{
	(void)rhs;
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
	return DOUBLE;
}
