#ifndef INT32_HPP
#define INT32_HPP

#include <iostream>
#include "IOperand.hpp"

class Int32 : public IOperand
{
	public:
		Int32( void );
		Int32( eOperandType type, std::string value );
		Int32( Int32 const & int32 );
		virtual ~Int32( void );

		IOperand & 				operator=(Int32 const & int32);

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