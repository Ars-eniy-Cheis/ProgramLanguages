#include "Parallelogram.h"

Parallelogram::Parallelogram()
{
	a = 0;
	h = 0;
}

Parallelogram::Parallelogram(float new_a, float new_h)
{
	if (new_a < 0 && new_h < 0)
	{
		Exceptions Paral(0, "Parallelogram base and height < 0");
		throw Paral;
	}
	else if (new_a<0)
	{
		Exceptions Paral(new_a, "Parallelogram base < 0");
		throw Paral;
	}
	else if (new_h < 0)
	{
		Exceptions Paral(new_h, "Parallelogram height < 0");
		throw Paral;
	}
	else
	{
		a = new_a;
		h = new_h;
	}
}

float Parallelogram::Area()
{
	return a * h;
}

Figure* Parallelogram::Clone()
{
	return new Parallelogram(a, h);
}
