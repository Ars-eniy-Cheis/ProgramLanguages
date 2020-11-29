#pragma once
#include "CompTable.h"

#include <iostream>
#include "string"
#include <string.h>

class CompTableWithPC : public CompTable
{
private:
	float power;
	int PCsize;
	string PCcolor;

public:
	CompTableWithPC();
	CompTableWithPC(int new_size, string new_color, int new_h, string new_material, float new_power, int new_PCsize, string new_PCcolor);
	virtual void Show();
	virtual void Enter();
	virtual int CalcVolume();

};
