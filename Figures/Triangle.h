#pragma once
#include "Figure.h"

#include <iostream>
class Triangle : public Figure
{

private:

	float a, h;

public:
	Triangle();
	Triangle(float new_a, float new_h);
	virtual float Area();
	virtual Figure* Clone();
};
