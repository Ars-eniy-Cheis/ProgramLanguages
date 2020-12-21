#include "Rectangle.h"

Rectangle::Rectangle()
{
	a = 0;
	b = 0;

}

Rectangle::Rectangle(float new_a, float new_b)
{
	if (new_a < 0 && new_b < 0)
	{
		Exceptions rect_aNb_side(0, "Rectangle a side and b side < 0");
		throw rect_aNb_side;
	}
	else if (new_a < 0)
	{
		Exceptions rect_a_side(new_a, "Rectangle a side < 0");
		throw rect_a_side;
	}
	else if (new_b < 0)
	{
		Exceptions rect_b_side(new_b, "Rectangle b side < 0");
		throw rect_b_side;
	}
	else
	{
		a = new_a;
		b = new_b;
	}
}

Rectangle::Rectangle(float new_a)
{
	if (new_a < 0)
	{
		Exceptions rect_side(new_a, "Rectangle side < 0");
		throw rect_side;
	}
	else
	{
		a = new_a;
		b = new_a;
	}
}

float Rectangle::Area()
{
	return a * b;
}

Figure* Rectangle::Clone()
{
	return new Rectangle(a, b);
}
