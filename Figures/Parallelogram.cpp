
#include "Parallelogram.h"

Parallelogram::Parallelogram()
{
	a = 0;
	h = 0;
}

Parallelogram::Parallelogram(float new_a, float new_h)
{
	a = new_a;
	h = new_h;
}

float Parallelogram::Area()
{
	return a * h;
}

Figure* Parallelogram::Clone()
{
	return new Parallelogram(a, h);
}
