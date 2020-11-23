#pragma once
#include <stack>
#include "string"


using namespace std;

class Calculation
{

public:
	double Answer(string rpn);
	string Exp_to_PostFix(string Expr);
	int Priority(char token);
	bool check(string Expr);
	string Exp_minus_reverse(string expr);

};

