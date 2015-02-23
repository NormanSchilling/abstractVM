/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:56:55 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/23 15:13:45 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
#define OPERAND_H

#include <iostream>
#include "IOperand.hpp"

class Operand : public IOperand
{
	public:
		Operand( void );
		Operand( Operand const & operand );
		virtual ~Operand( void );	

		Operand & 				operator=(Operand const & operand);

		virtual Operand const * operator+( Operand const & rhs ); // Sum
		virtual Operand const * operator-( Operand const & rhs ); // Difference
		virtual Operand const * operator*( Operand const & rhs ); // Product
		virtual Operand const * operator/( Operand const & rhs ); // Quotient
		virtual Operand const * operator%( Operand const & rhs ); // Modulo

		virtual int 				getPrecision( void ) const; // Precision of the type of the instance
		virtual eOperandType		getType( void ) const; // Type of the instance

		// virtual std::string const & toString( void ); // String representation of the instance

	private:
		int				_precision;
		eOperandType	_type;

};

#endif