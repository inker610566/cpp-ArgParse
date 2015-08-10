#pragma once
#include<Exception>
#include<string>

namespace CUtility
{
	class ArgumentErrorException: std::exception
	{
	public:
		ArgumentErrorException();
		~ArgumentErrorException();
	private:
		string option;
	};
}

