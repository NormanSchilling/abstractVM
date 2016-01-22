#include "Int16.hpp"
#include "Int8.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Errors.hpp"

Float::Float(void)
{
	return ;
}

Float::Float( eOperandType type, std::string value, int precision )
{
	this->_type = type;
	this->_value = value;
	this->_precision = precision;
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

IOperand & 		Float::operator=(IOperand const & rhs)
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_precision = rhs.getPrecision();
		this->_value = rhs.toString();
	}

	return *this;
}

int				Float::getMaxPrecision(IOperand const & rhs) const
{
	int			precision;

	if (this->getPrecision() < rhs.getPrecision())
		precision = rhs.getPrecision();
	else
		precision = this->getPrecision();
	return (precision);
}

std::string		Float::getStringValue(int precision, std::string value) const
{
	int pos = value.find(".");
	if (precision == 0 || precision == 1 || precision == 2)
		value = value.substr(0, pos);
	else
		value = value.substr(0, pos + 3);

	return (value);
}

IOperand const * Float::getNewOperand(int precision, std::string value) const
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

IOperand const * Float::operator+(IOperand const & rhs) const
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

IOperand const * Float::operator-(IOperand const & rhs) const
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

IOperand const * Float::operator*(IOperand const & rhs) const
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

IOperand const * Float::operator/(IOperand const & rhs) const
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

IOperand const * Float::operator%(IOperand const & rhs) const
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

void		Float::check_underflow_overflow(double sum) const
{
	std::cout << "SUM FLOAT = " << sum << " = " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "SUM FLOAT = " << sum << " = " << std::numeric_limits<float>::max() << std::endl;
	if (sum < std::numeric_limits<float>::min() )
	{
		throw Errors("Number underflow Float");
	}
	if (sum > std::numeric_limits<float>::max() )
	{
		throw Errors("Number overflow Float");
	}
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