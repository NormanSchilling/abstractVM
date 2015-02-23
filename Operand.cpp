/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:57:21 by nschilli          #+#    #+#             */
/*   Updated: 2015/02/23 15:53:24 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operand.hpp"

Operand::Operand(void)
{
	return ;
}

Operand::Operand(Operand const & operand)
{
	*this = operand;
	return ;
}

Operand::~Operand( void )
{
	return ;
}

Operand & 		Operand::operator=(Operand const & operand)
{
	if ( this != &operand )
	{

	}

	return *this;
}

Operand const * Operand::operator+(Operand const & rhs)
{
	this->_precision += rhs._precision;
	return  this;
}

Operand const * Operand::operator-(Operand const & rhs)
{
	this->_precision -= rhs._precision;
	return this;
}

Operand const * Operand::operator*(Operand const & rhs)
{
	this->_precision *= rhs._precision;
	return this;
}

Operand const * Operand::operator/(Operand const & rhs)
{
	this->_precision /= rhs._precision;
	return this;
}

Operand const * Operand::operator%(Operand const & rhs)
{
	this->_precision %= rhs._precision;
	return this;
}

// std::string const & Operand::toString( void )
// {

// }

int				Operand::getPrecision(void) const
{
	return this->_precision;
}

eOperandType	Operand::getType(void) const
{
	return this->_type;
}
