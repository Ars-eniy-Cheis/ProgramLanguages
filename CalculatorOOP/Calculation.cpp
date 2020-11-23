#include "Calculation.h"

#include <iostream>
#include "string"
#include <stack>
#include <queue>
#include <string.h>

double Calculation::Answer(string rpn)
{
	string operand;
	stack<double> St;

	for (int i = 0; i < rpn.length(); i++)
	{
		if (rpn[i] == ' ') continue;
		if (Priority(rpn[i]) == 0)
		{
			while (rpn[i] != ' ' && Priority(rpn[i]) == 0)
			{
				operand += rpn[i++];
				if (i == rpn.length()) break;
			}
			St.push(stof(operand));
			operand = "";
		}

		if (Priority(rpn[i]) > 1)
		{
			double a = St.top(), b;
			St.pop();
			b = St.top();
			St.pop();
			if (rpn[i] == '+')St.push(b + a);
			if (rpn[i] == '-')St.push(b - a);
			if (rpn[i] == '*')St.push(b * a);
			if (rpn[i] == '/')
			{
				if (a == 0)
				{
					cout << "ERROR (zero division)" << endl;
					return 0;
				}
				else St.push(b / a);
			}

		}
	}

	return St.top();
}

string Calculation::Exp_to_PostFix(string Expr)
{
	string current = "";
	stack<char> St;

	int prior;
	for (int i = 0; i < Expr.length(); i++)
	{
		prior = Priority(Expr[i]);
		if (prior == 0)
		{
			current += Expr[i];
		}
		if (prior == 1)
		{
			St.push(Expr[i]);
		}
		if (prior > 1)
		{
			current += ' ';
			while (!St.empty())
			{
				if (Priority(St.top()) >= prior)
				{
					current += St.top();
					St.pop();
				}
				else break;
			}
			St.push(Expr[i]);
		}
		if (prior == -1)
		{
			while (Priority(St.top()) != 1)
			{
				current += St.top();
				St.pop();
			}
			St.pop();
		}

	}
	while (!St.empty())
	{
		current += St.top();
		St.pop();
	}
	return current;
}

int Calculation::Priority(char token)
{
	if (token == '*' || token == '/')
	{
		return 3;
	}
	else if (token == '+' || token == '-')
	{
		return 2;
	}
	else if (token == '(')
	{
		return 1;
	}
	else if (token == ')')
	{
		return -1;
	}
	else
		return 0;
}

bool Calculation::check(string Expr)
{
	int Remi = -1;
	for (int i = 0; i < Expr.length(); i++)
	{
		if (Expr[0] == '+' || Expr[0] == '*' || Expr[0] == '/' || Expr[0] == ')')
		{
			cout << "Incorrect expression" << endl;
			return  false;
		}
		if ((Expr[i] == '+' || Expr[i] == '-' || Expr[i] == '*' || Expr[i] == '/') && (Expr[i + 1] == ')' || Expr[i + 1] == '+' || Expr[i + 1] == '-' || Expr[i + 1] == '*' || Expr[i + 1] == '/'))
		{
			cout << "Incorrect expression" << endl;
			return  false;
		}
		else if (Expr[i] == ')')
		{
			Remi = i;
		}
		if (Expr[i] == '(' && Remi < i && Remi>0)
		{
			cout << "unbalanced brackets" << endl;
			return false;
		}
	}
	return true;
}

string Calculation::Exp_minus_reverse(string expr)
{
	string preparedExp;
	for (int i = 0; i < expr.length(); i++)
	{
		char symbol = expr[i];
		if (symbol == '-')
		{
			if (i == 0) preparedExp += '0';
			else if (expr[i - 1] == '(') preparedExp += '0';
		}
		preparedExp += symbol;

	}
	return preparedExp;
}
