#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <iostream>
#include "IOperand.hpp"

class Float : public IOperand
{
	public:
		Float( void );
		Float(eOperandType type, std::string value, int precision );
		Float( Float const & ofloat );
		virtual ~Float( void );

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
		void						check_underflow_overflow(double sum) const;
		std::string					getValue(void) const;

	private:
		int				_precision;
		eOperandType	_type;
		std::string		_value;

};

#endif