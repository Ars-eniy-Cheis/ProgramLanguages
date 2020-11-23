#include "CompTableWithPC.h"

CompTableWithPC::CompTableWithPC():CompTable()
{
	power = 0;
	PCsize = 0;
	PCcolor = "NONE";
}

CompTableWithPC::CompTableWithPC(int new_size, string new_color, int new_h, string new_material, float new_power, int new_PCsize, string new_PCcolor) : CompTable(new_size, new_color, new_h, new_material)
{
	power = new_power;
	PCsize = new_PCsize;
	PCcolor = new_PCcolor;
}

int CompTableWithPC::CalcVolumeCompTableWithPC()
{
	return PCsize * PCsize * PCsize + CalVolumeCT();
}
