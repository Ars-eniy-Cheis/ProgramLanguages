#pragma once
#include "Figure.h"
#include "Exceptions.h"

class Parallelogram : public Figure
{
private:
	float a, h;

public:
	Parallelogram();
	Parallelogram(float new_a, float new_h) throw (Exceptions);
	virtual float Area();
	virtual Figure* Clone();
};
