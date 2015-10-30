#ifndef INT16_HPP
#define INT16_HPP

#include <iostream>
#include "IOperand.hpp"

class Int16 : public IOperand
{
	public:
		Int16( void );
		Int16( Int16 const & int16 );
		virtual ~Int16( void );

		IOperand & 				operator=(Int16 const & int16);

		virtual IOperand const * operator+( Int16 const & rhs ); // Sum
		virtual IOperand const * operator-( Int16 const & rhs ); // Difference
		virtual IOperand const * operator*( Int16 const & rhs ); // Product
		virtual IOperand const * operator/( Int16 const & rhs ); // Quotient
		virtual IOperand const * operator%( Int16 const & rhs ); // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		// virtual std::string const & toString( void ); // String representation of the instance

	private:
		int				_precision;
		eOperandType	_type;

};

#endif