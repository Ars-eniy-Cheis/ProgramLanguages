#include "Circle.h"

#include <iostream>



Circle::Circle()
{
	r = 0;
}

Circle::Circle(float new_r)
{
	if (new_r < 0)
	{
		Exceptions rad(new_r, "Circle radius < 0");
		throw rad;
	}
	else
	{
		r = new_r;
	}
}

float Circle::Area()
{
	return 3.1415 * r * r;
}

Figure* Circle::Clone()
{
	return new Circle(r);
}
