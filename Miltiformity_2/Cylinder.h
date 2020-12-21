#pragma once
#include "Figure.h"
#include "Exceptions.h"

class Cylinder
{
private:
	Figure* figure;
	float h;

public:
	Cylinder();
	Cylinder(Figure* F, float new_h) throw (Exceptions);
	~Cylinder();

	float Volume();
};
