#include "TooMoreArgumentException.h"
using namespace CUtility;
using namespace std;

const char* TooMoreArgumentException::what()
{
	return "[Option] TooMoreArgumentException";
}

TooMoreArgumentException::~TooMoreArgumentException()
{
}
