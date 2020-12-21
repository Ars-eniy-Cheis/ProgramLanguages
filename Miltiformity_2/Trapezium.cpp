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
	if (new_a < 0 && new_b<0 && new_h<0)
	{
		Exceptions trap(0, "Trapezium bases and height < 0");
		throw trap;
	}
	else if (new_a < 0)
	{
		Exceptions a_base(new_a, "Trapezium a base < 0");
		throw a_base;
	}
	else if (new_b < 0)
	{
		Exceptions b_base(new_b, "Trapezium b base < 0");
		throw b_base;
	}
	else if (new_h < 0)
	{
		Exceptions h_height(new_a, "Trapezium height < 0");
		throw h_height;
	}
	else
	{
		a = new_a;
		b = new_b;
		h = new_h;
	}
}

float Trapezium::Area()
{
	return (a + b) / 2 * h;
}

Figure* Trapezium::Clone()
{
	return new Trapezium(a, b, h);
}
