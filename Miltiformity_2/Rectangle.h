#pragma once
#include "Figure.h"
#include "Exceptions.h"

class Rectangle : public Figure
{
private:
	float a, b;

public:
	Rectangle();
	Rectangle(float new_a, float new_b) throw (Exceptions);
	Rectangle(float new_a) throw (Exceptions);
	virtual float Area();
	virtual Figure* Clone();
};

