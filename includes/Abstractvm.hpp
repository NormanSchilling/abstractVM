#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>

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

		void				push(void);
		void				assert(void);
		void				pop(void);
		void				dump(void);
		void				add(void);
		void				sub(void);
		void				mul(void);
		void				div(void);
		void				mod(void);
		void				print(void);
		void				exit(void);

	private:
		std::vector<std::string>		listCommand;
};

typedef void (*executeCommand)(void);

#endif