#pragma once
#include "Figure.h"

class Parallelogram : public Figure
{
private:
	float a, h;

public:
	Parallelogram();
	Parallelogram(float new_a, float new_h);
	virtual float Area();
	virtual Figure* Clone();
};
