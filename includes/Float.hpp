#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <iostream>
#include "IOperand.hpp"

class Float : public IOperand
{
	public:
		Float( void );
		Float(eOperandType type, std::string value);
		Float( Float const & ofloat );
		virtual ~Float( void );

		IOperand & 				operator=(Float const & ofloat);

		virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		// virtual std::string const & toString( void ); // String representation of the instance

	private:
		int				_precision;
		eOperandType	_type;
		std::string		_value;

};

#endif