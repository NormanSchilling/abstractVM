#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <iostream>
#include <string>
#include <regex>
#include <vector>

class Abstractvm
{
	public:
		Abstractvm(void);
		Abstractvm(std::vector<std::string> listCommand);
		Abstractvm(Abstractvm const & command);
		~Abstractvm(void);

		Abstractvm & 		operator=(Abstractvm const & abstractvm);



		std::std::vector<std::string>		getListCommand();

	private:
		std::vector<std::string>		listCommand;
};

#endif