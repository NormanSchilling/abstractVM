#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include "IOperand.hpp"

class Double : public IOperand
{
	public:
		Double( void );
		Double( Double const & odouble );
		virtual ~Double( void );

		IOperand & 				operator=(Double const & odouble);

		virtual IOperand const * operator+( Double const & rhs ); // Sum
		virtual IOperand const * operator-( Double const & rhs ); // Difference
		virtual IOperand const * operator*( Double const & rhs ); // Product
		virtual IOperand const * operator/( Double const & rhs ); // Quotient
		virtual IOperand const * operator%( Double const & rhs ); // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		// virtual std::string const & toString( void ); // String representation of the instance

	private:
		int				_precision;
		eOperandType	_type;

};

#endif