#pragma once
#include<exception>
#include<string>

namespace CUtility
{
	class TooMoreArgumentException: std::exception
	{
	public:
		const char* what();
		~TooMoreArgumentException();
	};
}

