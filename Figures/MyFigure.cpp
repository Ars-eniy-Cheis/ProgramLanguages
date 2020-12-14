
#include "MyFigure.h"

MyFigure::MyFigure()
{
	Cir = new Circle(0);
	Trap = new Trapezium(0, 0, 0);
	Par = new Parallelogram(0, 0);
	Tri = new Triangle(0, 0);
	Rect = new Rectangle(0, 0);
}

MyFigure::MyFigure(Circle* new_Cir, Rectangle* new_Rect, Parallelogram* new_Par, Trapezium* new_Trap, Triangle* new_Tri)
{
	Cir = new_Cir;
	Trap = new_Trap;
	Par = new_Par;
	Tri = new_Tri;
	Rect = new_Rect;
}

float MyFigure::Area()
{
	return (Cir->Area()/2) + Trap->Area() + Par->Area() + Tri->Area() + Rect->Area();
}

Figure* MyFigure::Clone()
{
	return new MyFigure();
}
