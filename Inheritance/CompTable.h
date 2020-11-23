#pragma once
#include "Table.h"

#include "string"
#include <string.h>

using namespace std;

class CompTable: public Table
{
private:
	int h;
	string material;

public:
	CompTable();
	CompTable(int new_size, string new_color, int new_h, string new_material);
	void ShowCT();
	void EnterCT();
	int CalVolumeCT();


};

