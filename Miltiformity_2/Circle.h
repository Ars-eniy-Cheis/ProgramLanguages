#pragma once
#include "Figure.h"
#include "Exceptions.h"

#include <iostream>

class Circle : public Figure
{

private:

	float r;

public:
	Circle();
	Circle(float new_r) throw (Exceptions);
	virtual float Area();
	virtual Figure* Clone();
};


