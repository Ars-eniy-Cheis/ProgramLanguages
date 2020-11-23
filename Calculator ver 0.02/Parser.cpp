#include "Parser.h"
#include <cmath>
#include <math.h>

using namespace std;

Parser::Parser()
{
	St.push('0');
}

Parser::Parser(stack<char> new_st)
{
	St = new_st;
}

Parser::Parser(const Parser& copy)
{
	St = copy.St;
}

void Parser::PostFix_Conversion(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		i++;
	}
}

double Parser::calculate()
{

	return 0;
}
