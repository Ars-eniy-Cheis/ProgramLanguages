
#include "Cylinder.h"

Cylinder::Cylinder()
{
	figure = nullptr;
	h = 0;
}

Cylinder::Cylinder(Figure* F, float new_h)
{
	figure = F;
	h = new_h;
}

Cylinder::~Cylinder()
{
	delete figure;
}

float Cylinder::Volume()
{
	return figure->Area() * h;
}
