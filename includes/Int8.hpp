#ifndef INT8_HPP
#define INT8_HPP

#include <iostream>
#include "IOperand.hpp"

class Int8 : public IOperand
{
	public:
		Int8( void );
		Int8( Int8 const & int8 );
		virtual ~Int8( void );

		IOperand & 				operator=(Int8 const & int8);

		virtual IOperand const * operator+( Int8 const & rhs ); // Sum
		virtual IOperand const * operator-( Int8 const & rhs ); // Difference
		virtual IOperand const * operator*( Int8 const & rhs ); // Product
		virtual IOperand const * operator/( Int8 const & rhs ); // Quotient
		virtual IOperand const * operator%( Int8 const & rhs ); // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		// virtual std::string const & toString( void ); // String representation of the instance

	private:
		int				_precision;
		eOperandType	_type;

};

#endif