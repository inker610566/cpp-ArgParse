#include "ArgumentDeficientException.h"
using namespace CUtility;
using namespace std;

ArgumentDeficientException::ArgumentDeficientException(string option)
: option(option)
{
}

const char* ArgumentDeficientException::what()
{
	return ("[Option] " + option + " lack of required arugments.").c_str();
}

ArgumentDeficientException::~ArgumentDeficientException()
{
}
