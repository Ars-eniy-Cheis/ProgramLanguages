#include "Triangle.h"

Triangle::Triangle()
{
	a = 0;
	h = 0;
}

Triangle::Triangle(float new_a, float new_h)
{
	a = new_a;
	h = new_h;
}

float Triangle::Area()
{
	return h/2 * a;
}

Figure* Triangle::Clone()
{
	return new Triangle(a, h);
}
