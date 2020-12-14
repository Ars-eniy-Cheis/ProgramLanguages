#pragma once
#include "Figure.h"

class Cylinder
{
private:
	Figure* figure;
	float h;

public:
	Cylinder();
	Cylinder(Figure* F, float new_h);
	~Cylinder();

	float Volume();
};

