
#include "string"
#include "stack"

using namespace std;

class Parser
{
private:
	stack<char> St;

public:
	Parser();
	Parser(stack<char> new_st);
	Parser(const Parser& copy);
	void PostFix_Conversion(string str);
	double calculate();
};

