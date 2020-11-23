#include "App.h"
#include "Parser.h"


#include <stdio.h>
#include <conio.h>

#include <iostream>
#include <stdlib.h>

#include <string>

using namespace std;

void App::Run()
{

	cout << "Enter expression" << endl;
	string str;
	cin.clear();
	cin.ignore();
	getline(cin, str);

	Parser* parser = new Parser();
	parser->PostFix_Conversion(str);
	double res = parser->calculate();
	cout << res;

}