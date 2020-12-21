#include "Exceptions.h"

#include <iostream>

using namespace std;

Exceptions::Exceptions(int new_value, string new_msg)
{
	value = new_value;
	msg = new_msg;
}

int Exceptions::GetValue()
{
	return value;
}

const string Exceptions::GetMessage()
{
	return msg;
}
