#include "App.h"
#include "Calculation.h"

#include <iostream>
#include "string"
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

void App::Run() 
{
	cout << "Enter Expression" << endl;
	string str;
	cin >> str;

	Calculation* calc = new Calculation();
	str = calc->Exp_minus_reverse(str);
	if (calc->check(str) == true)
	{
		cout << calc->Exp_to_PostFix(str) << endl;;
		cout << calc->Answer(calc->Exp_to_PostFix(str)) << endl;
	}
	else
	{
		cout<<" "<<endl;
	}

}