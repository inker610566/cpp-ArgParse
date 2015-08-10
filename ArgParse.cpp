#include "ArgParse.h"
#include <cassert>

using namespace std;
namespace CUtility
{
	ArgParse::ArgParse(NoOptionHandler no_option_hanlder)
		:no_option_handler(no_option_hanlder)
	{ }

	void ArgParse::AddOptionHandler(
		string option_string,
		int argument_number,
		OptionHandler handler,
		bool isRequire
	)
	{
		assert(option_string[0] == '-');
		option2Handler[option_string] = make_pair(handler, argument_number);
		if (isRequire)
			requireOptions.insert(option_string);
	}

	void ArgParse::ParseCommand(char* args[]) const
	{
		set<string> requireOptions(this->requireOptions);
		map<string, pair<OptionHandler, int>>::const_iterator iter;
		if (args[0] == nullptr)
		{
			throw ArgumentDeficientException("PROGRAM PATH");
		}
		char* program = *(args++);
		
		for ( ;*args != nullptr; args ++)
		{
			char* p = *args;
			if (*p == '-' && (iter = option2Handler.find(p)) != option2Handler.end())
			{
				const int arg_num = iter->second.second;
				// retrieve next arg_num arguments
				vector<char*> opt_args(arg_num);
				for (int i = 0; i < arg_num && *(++args); i++)
					opt_args[i] = *args;
				if (*args == nullptr)
					throw ArgumentDeficientException(p);

				(iter->second.first)(opt_args);
				requireOptions.erase(p);
			}
			else if (no_option_handler != nullptr)
				no_option_handler(*args);
			else
				throw TooMoreArgumentException();
		}
		if (requireOptions.size() > 0)
			throw OptionDeficientException(*(requireOptions.begin()));
	}
}
