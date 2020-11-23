#include <iostream>
#include <stdlib.h>

#include <string>

using namespace std;

int main()
{
	float n;
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		n = (int)str[i];
		cout << n << endl;
	}
	}
	

