#pragma once
#include "Figure.h"

#include <iostream>

class Circle : public Figure
{

private:

	float r;

public:
	Circle();
	Circle(float new_r);
	virtual float Area();
	virtual Figure* Clone();
};


