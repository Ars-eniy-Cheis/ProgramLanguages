
#include "Rectangle.h"


Rectangle::Rectangle()
{
	a = 0;
	b = 0;

}

Rectangle::Rectangle(float new_a, float new_b)
{
	a = new_a;
	b = new_b;
}

Rectangle::Rectangle(float new_a)
{
	a = new_a;
	b = new_a;
}

float Rectangle::Area()
{
	return a * b;
}

Figure* Rectangle::Clone()
{
	return new Rectangle(a, b);
}

