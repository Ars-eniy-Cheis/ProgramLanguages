#pragma once
#include "Figure.h"
#include "Exceptions.h"

#include <iostream>
class Trapezium : public Figure
{

private:

	float a, b, h;

public:
	Trapezium();
	Trapezium(float new_a, float new_b, float new_h) throw (Exceptions);
	virtual float Area();
	virtual Figure* Clone();
};