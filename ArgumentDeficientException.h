#pragma once
#include<exception>
#include<string>

namespace CUtility
{
	class ArgumentDeficientException : std::exception
	{
	public:
		ArgumentDeficientException(std::string option);
		const char* what();
		~ArgumentDeficientException();
	private:
		std::string option;
	};
}

