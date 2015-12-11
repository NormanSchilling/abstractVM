#include <exception>
#include <iostream>
#include <string>

class Errors
{
	public:
		Errors(std::string error) throw() : error(error) {}
		~Errors() throw(){}

		void display() throw()
		{
			std::cout << this->error << std::endl;
		}
	private:
		std::string		error;
};