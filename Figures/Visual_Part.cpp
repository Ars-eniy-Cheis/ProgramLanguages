#include "Visual_Part.h"
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "MyFigure.h"
#include "Cylinder.h"

#include <iostream>

using namespace std;

Visual_Part::Visual_Part()
{
}


Visual_Part::~Visual_Part()
{
}

int Visual_Part::Run()
{
	Figure* f;
	MENU();
	int n = 1;
	while (n != 0)
	{
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "Enter Lengt and Width: " << endl;
			float a, b;
			cin >> a;
			cin >> b;
			f = new Rectangle(a, b);
			cout << "Area of Rectangle: " << endl;
			cout << f->Area() << endl;
			MENU();
			break;
		}
		case 2:
		{
			cout << "Enter radius: " << endl;
			float r;
			cin >> r;
			f = new Circle(r);
			cout << "Area of Circle: " << endl;
			cout << f->Area() << endl;
			MENU();
			break;
		}
		case 3:
		{
			float r, a1, b1, h1, a2, h2, h3;
			cout << "Enter radius of Circle" << endl;
			cin >> r;
			cout << "Enter 1st base of Trapezium" << endl;
			cin >> a1;
			cout << "Enter 2nd base of Trapezium" << endl;
			cin >> b1;
			cout << "Enter height of Trapezium" << endl;
			cin >> h1;
			cout << "Enter base of Parallelogram" << endl;
			cin >> a2;
			cout << "Enter height of Parallelogram" << endl;
			cin >> h2;
			cout << "Enter height of Triangle" << endl;
			cin >> h3;
			Circle* C = new Circle(r);
			Rectangle* R = new Rectangle(a1, r*2);
			Parallelogram* P = new Parallelogram(a2, h2);
			Trapezium* Tra = new Trapezium(a1, b1, h1);
			Triangle* Tri = new Triangle(r*2, h3);
			f = new MyFigure(C, R, P, Tra, Tri);
			cout << "Area of My Figure: " << endl;
			cout << f->Area() << endl;
			MENU();
			break;
		}
		case 4:
		{
			Cylinder* Cyl = NULL;
			float a, b, h, height;
			int m = 1;
			while (m != 0)
			{
				cout << endl << "1. Rectangle" << endl << "2. Triangle" << endl << "3. Parallelogram" << endl << "4. Trapezium" << endl << "5. My Figure" << endl;
				cin >> m;

				switch (m)
				{
				case 1:
					cout << "Enter base and width" << endl;
					cin >> a;
					cin >> b;
					f = new Rectangle(a, b);
					cout << "Enter height: " << endl;
					cin >> height;
					Cyl = new Cylinder(f, height);
					cout << "Volume: " << Cyl->Volume() << endl;
					break;
				case 2:
					cout << "Enter base and triangle height" << endl;
					cin >> a;
					cin >> h;
					f = new Triangle(a, h);
					cout << "Enter height: " << endl;
					cin >> height;
					Cyl = new Cylinder(f, height);
					cout << "Volume: " << Cyl->Volume() << endl;
					break;
				case 3:
					cout << "Enter base and Parallelogram height" << endl;
					cin >> a;
					cin >> h;
					f = new Parallelogram(a, h);
					cout << "Enter height: " << endl;
					cin >> height;
					Cyl = new Cylinder(f, height);
					cout << "Volume: " << Cyl->Volume() << endl;
					break;
				case 4:
					cout << "Enter 1st base, 2nd base and Trapezium height" << endl;
					cin >> a;
					cin >> b;
					cin >> h;
					f = new Trapezium(a, b, h);
					cout << "Enter height: " << endl;
					cin >> height;
					Cyl = new Cylinder(f, height);
					cout << "Volume: " << Cyl->Volume() << endl;
					break;
				case 5:

					float r, a1, b1, h1, a2, h2, h3;
					cout << "Enter radius of Circle" << endl;
					cin >> r;
					cout << "Enter 1st base of Trapezium" << endl;
					cin >> a1;
					cout << "Enter 2nd base of Trapezium" << endl;
					cin >> b1;
					cout << "Enter height of Trapezium" << endl;
					cin >> h1;
					cout << "Enter base of Parallelogram" << endl;
					cin >> a2;
					cout << "Enter height of Parallelogram" << endl;
					cin >> h2;
					cout << "Enter height of Triangle" << endl;
					cin >> h3;
					Circle* C = new Circle(r);
					Rectangle* R = new Rectangle(a1, r * 2);
					Parallelogram* P = new Parallelogram(a2, h2);
					Trapezium* Tra = new Trapezium(a1, b1, h1);
					Triangle* Tri = new Triangle(r * 2, h3);
					f = new MyFigure(C, R, P, Tra, Tri);
					cout << "Enter height: " << endl;
					cin >> height;
					Cyl = new Cylinder(f, height);
					cout << "Volume: " << Cyl->Volume() << endl;
					break;
				}
				break;
			}
			MENU();
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
}

void Visual_Part::MENU()
{
	cout << "MENU: " << endl << endl << "1. Rectangle" << endl << "2. Circle" << endl << "3. My Figure" << endl << "4. Volumetric Figure" << endl << "0. EXIT" << endl;
}