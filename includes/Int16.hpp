#ifndef INT16_HPP
#define INT16_HPP

#include <iostream>
#include "IOperand.hpp"

#define UNDERFLOW_INT16 -32768
#define OVERFLOW_INT16 32767

class Int16 : public IOperand
{
	public:
		Int16( void );
		Int16(eOperandType type, std::string value, int precision );
		Int16( Int16 const & int16 );
		virtual ~Int16( void );

		IOperand & 				operator=(IOperand const & rhs);

		int						getMaxPrecision(IOperand const & rhs) const;
		std::string				getStringValue(int precision, std::string value) const;
		IOperand const * 		getNewOperand(int precision, std::string value) const;

		virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		virtual std::string const & toString( void ) const; // String representation of the instance
		void						check_underflow_overflow( double ) const;
		std::string					getValue(void) const;

	private:
		int				_precision;
		eOperandType	_type;
		std::string		_value;

};

#endif