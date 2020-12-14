#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
private:
	float a, b;

public:
	Rectangle();
	Rectangle(float new_a, float new_b);
	Rectangle(float new_a);
	virtual float Area();
	virtual Figure* Clone();
};

