#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Trapezium.h"
#include "Triangle.h"

#include <iostream>
class MyFigure : public Figure
{

private:

	Circle* Cir;
	Rectangle* Rect;
	Parallelogram* Par;
	Trapezium* Trap;
	Triangle* Tri;


public:
	MyFigure();
	MyFigure(Circle* new_Cir, Rectangle* new_Rect, Parallelogram* new_Par, Trapezium* new_Trap, Triangle* new_Tri);
	virtual float Area();
	virtual Figure* Clone();
};
