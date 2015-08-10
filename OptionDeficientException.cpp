#include "OptionDeficientException.h"
using namespace CUtility;
using namespace std;

OptionDeficientException::OptionDeficientException(string option)
: option(option)
{
}

const char* OptionDeficientException::what()
{
	return ("[Option] no required option " + option + " found.").c_str();
}

OptionDeficientException::~OptionDeficientException()
{
}
