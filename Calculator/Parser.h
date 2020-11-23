#include <string>
#include <stack>

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
