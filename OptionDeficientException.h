#pragma once
#include<exception>
#include<string>

namespace CUtility
{
	class OptionDeficientException: std::exception
	{
	public:
		OptionDeficientException(std::string option);
		const char* what();
		~OptionDeficientException();
	private:
		std::string option;
	};
}

