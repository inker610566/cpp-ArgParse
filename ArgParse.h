#include<map>
#include<set>
#include<vector>
#include<string>
#include<functional>
#include "OptionDeficientException.h"
#include "ArgumentDeficientException.h"
#include "TooMoreArgumentException.h"


namespace CUtility
{

	typedef std::function<void(std::vector<char*>)> OptionHandler;
	typedef std::function<void(char*)> NoOptionHandler;

	class ArgParse
	{
	public:
		ArgParse(NoOptionHandler no_option_hanlde = nullptr);
		void AddOptionHandler(std::string option_string, int argument_number, OptionHandler handler, bool isRequire = false);
		void ParseCommand(char* args[]) const
			throw (OptionDeficientException, ArgumentDeficientException, TooMoreArgumentException);
	private:
		std::map<std::string, std::pair<OptionHandler, int>> option2Handler;
		std::set<std::string> requireOptions;
		NoOptionHandler no_option_handler;
	};
}