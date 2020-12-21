#include "Triangle.h"

Triangle::Triangle()
{
	a = 0;
	h = 0;
}

Triangle::Triangle(float new_a, float new_h)
{
	if (new_a < 0 && new_h < 0)
	{
		Exceptions aNh(0, "Triangle base and height < 0");
		throw aNh;
	}
	else if (new_a < 0)
	{
		Exceptions a_base(new_a, "Triangle base < 0");
		throw a_base;
	}
	else if (new_h < 0)
	{
		Exceptions h_height(new_h, "Triangle height < 0");
		throw h_height;
	}
	else
	{
		a = new_a;
		h = new_h;
	}
}

float Triangle::Area()
{
	return h / 2 * a;
}

Figure* Triangle::Clone()
{
	return new Triangle(a, h);
}
