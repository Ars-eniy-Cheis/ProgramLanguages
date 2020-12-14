#include "Trapezium.h"

#include <iostream>

Trapezium::Trapezium()
{
	a = 0;
	b = 0;
	h = 0;
}

Trapezium::Trapezium(float new_a, float new_b, float new_h)
{
	a = new_a;
	b = new_b;
	h = new_h;
}

float Trapezium::Area()
{
	return (a + b)/2 * h;
}

Figure* Trapezium::Clone()
{
	return new Trapezium(a, b, h);
}
