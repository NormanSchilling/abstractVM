#include "Int16.hpp"
#include "Int8.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Errors.hpp"

Double::Double(void)
{
	return ;
}

Double::Double( eOperandType type, std::string value, int precision )
{
	std::string::size_type		sz;
	double						v;

	this->_type = type;
	v = std::stod (value, &sz);
	check_underflow_overflow(v);
	this->_value = value;
	this->_precision = precision;
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

IOperand & 		Double::operator=(IOperand const & rhs)
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_precision = rhs.getPrecision();
		this->_value = rhs.toString();
	}

	return *this;
}

int				Double::getMaxPrecision(IOperand const & rhs) const
{
	int			precision;

	if (this->getPrecision() < rhs.getPrecision())
		precision = rhs.getPrecision();
	else
		precision = this->getPrecision();
	return (precision);
}

std::string		Double::getStringValue(int precision, std::string value) const
{
	int pos = value.find(".");
	if (precision == 0 || precision == 1 || precision == 2)
		value = value.substr(0, pos);
	else
		value = value.substr(0, pos + 3);

	return (value);
}

IOperand const * Double::getNewOperand(int precision, std::string value) const
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

IOperand const * Double::operator+(IOperand const & rhs) const
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
	sum = firstValue + secondValue;
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = getStringValue(precision, value);

	return (getNewOperand(precision, value));
}

IOperand const * Double::operator-(IOperand const & rhs) const
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

IOperand const * Double::operator*(IOperand const & rhs) const
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
	std::cout << "mul" << firstValue << " * " << secondValue << std::endl;
	sum = firstValue * secondValue;
	check_underflow_overflow(sum);
	value = std::to_string(sum);
	value = getStringValue(precision, value);

	return (getNewOperand(precision, value));
}

IOperand const * Double::operator/(IOperand const & rhs) const
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

IOperand const * Double::operator%(IOperand const & rhs) const
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

void		Double::check_underflow_overflow(double sum) const
{
	if (sum < std::numeric_limits<double>::lowest() )
	{
		throw Errors("Number underflow Double");
	}
	if (sum > std::numeric_limits<double>::max() )
	{
		throw Errors("Number overflow Double");
	}
}

std::string const & Double::toString( void ) const
{
	return (this->_value);
}

int				Double::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Double::getType(void) const
{
	return DOUBLE;
}

std::string		Double::getValue(void) const
{
	return this->_value;
}
