#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

class Abstractvm
{
	public:
		Abstractvm(void);
		Abstractvm(std::vector<std::string> listCommand);
		Abstractvm(Abstractvm const & command);
		~Abstractvm(void);

		Abstractvm & 		operator=(Abstractvm const & abstractvm);

		void				manager(void);
		void				managerCommands(void);
		void				displayCommands(void);
		void				assignString(std::string cmd);
		void				assignType();
		void				assignValue();

		void				push(std::string command);
		void				assert(std::string command);
		void				pop(std::string command);
		void				dump(std::string command);
		void				add(std::string command);
		void				sub(std::string command);
		void				mul(std::string command);
		void				div(std::string command);
		void				mod(std::string command);
		void				print(std::string command);
		void				exit(std::string command);

		IOperand const		*createInt8( std::string const &value ) const;
		IOperand const		*createInt16( std::string const &value) const;
		IOperand const		*createInt32( std::string const &value) const;
		IOperand const		*createFloat( std::string const &value) const;
		IOperand const		*createDouble( std::string const &value) const;

	private:
		std::vector<std::string>		listCommand;
		std::vector<IOperand>			stack;
		std::string						firstString;
		std::string						secondString;
		std::string						type;
		std::string						value;
};

typedef void (Abstractvm::*executeCommand)(std::string command);
typedef IOperand const *(Abstractvm::*createOperand)(std::string const &value) const;

#endif