#include "Int16.hpp"
#include "Int8.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Errors.hpp"

Int32::Int32(void)
{
	return ;
}

Int32::Int32( eOperandType type, std::string value, int precision )
{
	std::string::size_type		sz;
	double						v;

	this->_type = type;
	v = std::stod (value, &sz);
	check_underflow_overflow(v);
	this->_value = value;
	this->_precision = precision;
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

IOperand & 		Int32::operator=(IOperand const & rhs)
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_precision = rhs.getPrecision();
		this->_value = rhs.toString();
	}

	return *this;
}

int				Int32::getMaxPrecision(IOperand const & rhs) const
{
	int			precision;

	if (this->getPrecision() < rhs.getPrecision())
		precision = rhs.getPrecision();
	else
		precision = this->getPrecision();
	return (precision);
}

std::string		Int32::getStringValue(int precision, std::string value) const
{
	int pos = value.find(".");
	if (precision == 0 || precision == 1 || precision == 2)
		value = value.substr(0, pos);
	else
		value = value.substr(0, pos + 3);

	return (value);
}

IOperand const * Int32::getNewOperand(int precision, std::string value) const
{
	IOperand const				*newOperand;
	std::map<int, IOperand const *> geteOperandType = {
		{0, new Int8(INT8, value, precision)},
		{1, new Int16(INT16, value, precision)},
		{2, new Int32(INT32, value, precision)},
		{3, new Float(FLOAT, value, precision)},
		{4, new Double(DOUBLE, value, precision)}
	};

	newOperand = geteOperandType.at(precision);
	return (newOperand);
}

IOperand const * Int32::operator+(IOperand const & rhs) const
{
	std::string::size_type		sz;
	double						firstValue;
	double						secondValue;
	double						sum;
	int							precision;
	std::string					value;

	precision = this->getMaxPrecision(rhs);
	firstValue = std::stod (this->toString(), &sz);
	secondValue = std::stod (rhs.toString(), &sz);
	sum = firstValue + secondValue;
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = this->getStringValue(precision, value);

	return (this->getNewOperand(precision, value));
}

IOperand const * Int32::operator-(IOperand const & rhs) const
{
	std::string::size_type		sz;
	double						firstValue;
	double						secondValue;
	double						sum;
	int							precision;
	std::string					value;

	precision = getMaxPrecision(rhs);
	firstValue = std::stod (this->toString(), &sz);
	secondValue = std::stod (rhs.toString(), &sz);
	sum = firstValue - secondValue;
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = getStringValue(precision, value);

	return (getNewOperand(precision, value));
}

IOperand const * Int32::operator*(IOperand const & rhs) const
{
	std::string::size_type		sz;
	double						firstValue;
	double						secondValue;
	double						sum;
	int							precision;
	std::string					value;

	precision = getMaxPrecision(rhs);
	firstValue = std::stod (this->toString(), &sz);
	secondValue = std::stod (rhs.toString(), &sz);
	sum = firstValue * secondValue;
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = getStringValue(precision, value);
	return (getNewOperand(precision, value));
}

IOperand const * Int32::operator/(IOperand const & rhs) const
{
	std::string::size_type		sz;
	double						firstValue;
	double						secondValue;
	double						sum;
	int							precision;
	std::string					value;

	precision = getMaxPrecision(rhs);
	firstValue = std::stod (this->toString(), &sz);
	secondValue = std::stod (rhs.toString(), &sz);
	if (secondValue == 0)
	{
		std::cout << "Error: Division by zero." << std::endl;
		exit(-1);
	}
	sum = firstValue / secondValue;
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = getStringValue(precision, value);

	return (getNewOperand(precision, value));
}

IOperand const * Int32::operator%(IOperand const & rhs) const
{
	std::string::size_type		sz;
	double						firstValue;
	double						secondValue;
	double						sum;
	int							precision;
	std::string					value;

	precision = getMaxPrecision(rhs);
	firstValue = std::stod (this->toString(), &sz);
	secondValue = std::stod (rhs.toString(), &sz);
	sum = fmod(firstValue, secondValue);
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = getStringValue(precision, value);

	return (getNewOperand(precision, value));
}

void		Int32::check_underflow_overflow(double sum) const
{
	if (sum < std::numeric_limits<int>::min() )
	{
		throw Errors("Number underflow Int32");
	}
	if (sum > std::numeric_limits<int>::max() )
	{
		throw Errors("Number overflow Int32");
	}
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
