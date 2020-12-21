#include "Cylinder.h"


Cylinder::Cylinder()
{
	figure = nullptr;
	h = 0;
}

Cylinder::Cylinder(Figure* F, float new_h) throw (Exceptions)
{
	if (new_h < 0)
	{
		Exceptions cyl_height(new_h, "Cylinder height < 0");
		throw cyl_height;
	}
	else
	{
		figure = F;
		h = new_h;
	}
}

Cylinder::~Cylinder()
{
	delete figure;
}

float Cylinder::Volume()
{
	return figure->Area() * h;
}
