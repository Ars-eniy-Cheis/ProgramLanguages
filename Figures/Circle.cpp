
#include "Circle.h"

#include <iostream>



Circle::Circle()
{
	r = 0;
}

Circle::Circle(float new_r)
{
	r = new_r;
}

float Circle::Area()
{
	return 3.1415 * r * r;
}

Figure* Circle::Clone()
{
	return new Circle(r);
}
