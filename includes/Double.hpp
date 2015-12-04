#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include "IOperand.hpp"

class Double : public IOperand
{
	public:
		Double( void );
		Double(eOperandType type, std::string value);
		Double( Double const & odouble );
		virtual ~Double( void );

		IOperand & 				operator=(Double const & odouble);

		virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		virtual std::string const & toString( void ) const; // String representation of the instance
		std::string					getValue(void) const;

	private:
		int				_precision;
		eOperandType	_type;
		std::string		_value;

};

#endif