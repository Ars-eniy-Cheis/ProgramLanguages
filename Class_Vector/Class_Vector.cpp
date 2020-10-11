#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265  

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

class Vector
{
public:

    int size;
    float* coords;
    Vector();
    Vector(int new_size, float* new_coords);
    Vector(int new_size);
    ~Vector();
    Vector(const Vector& copy);
    void input();
    void output();
    double angle(Vector& a);
    double abs(Vector& a);
    Vector operator= (const Vector& a);
    Vector operator+ (const Vector& a);
    Vector operator- (const Vector& a);
    int operator* (const Vector& a);
    Vector operator* (const int a);
    bool operator> (Vector& a);
    bool operator< (Vector& a);
    bool operator<= (Vector& a);
    bool operator>= (Vector& a);
    bool operator== (Vector& a);
    bool operator!= (Vector& a);

    friend istream& operator>> (istream& in, Vector& a);
    friend ostream& operator<< (ostream& out, const Vector& a);
};

void menu();

int main()
{
    //Lab Vector_class

    menu();
    int num = 1;
    while (num != 0)
    {
        cin >> num;
        switch (num)
        {
        case 1:
        {
            Vector a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; //(2, 5, 7)
            cout << "Enter Vector b: (should be same size with Vector a)" << endl;
            cin >> b; //(1, 22, 12)
            if (a.size != b.size)
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Отыет: (3, 27, 19)
                Vector c = a + b;
                cout << endl << a << " + " << b << " = " << c << endl;
            }
            menu();
            break;
        }
        case 2:
        {
            Vector a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; //(4, 5, 6)
            cout << "Enter Vector b (should be same size with Vector a):" << endl;
            cin >> b; //(6, 7, 8)
            if (a.size != b.size)
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Отыет: 107
                cout << endl << a << " * " << b << " = " << a * b << endl;
            }
            menu();
            break;
        }
        case 3:
        {
            Vector a;
            int n;
            cout << "Enter Vector a: " << endl;
            cin >> a; // (9, 7, 1, 4)
            cout << "Enter number: " << endl;
            cin >> n; //3
            //Отыет: (27, 21, 3, 12)
            cout << endl << n << " * " << a << " = " << a * n << endl;
            menu();
            break;
        }
        case 4:
        {
            Vector a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; // Координаты  а: (2, 6)
            cout << "Enter Vector b: (should be same size with Vector a)" << endl;
            cin >> b; // Координаты  b: (8, 4)
            if (a.size != b.size)
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Ответ: 45 Градусов
                cout << endl << "Angle between a and b: " << a.angle(b) << " degree" << endl; 
            }
            menu();
            break;
        }
        case 5:
        {
            Vector a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; //(1, 22, 12, 8)
            cout << "Enter Vector b: (should be same size with Vector a)" << endl;
            cin >> b;//(2, 5, 7, 12)
            if (a.size != b.size)
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Отыет: (-1, 17, 5, -4)
                cout << endl << a << " - " << b << " = " << a - b << endl;
            }
            menu();
            break;
        }
        case 6:
        {
            Vector a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a;//(3,4,0)
            cout << "Enter Vector b: " << endl;
            cin >> b;//(5,0,0)
            //Сравнени векторов происходит по их модулю, а не по координатам
            //Вывод: a>=b; a<=b; a==b;
            if (a >= b)
            {
                cout << "a>=b" << endl;
            }
            if (a > b)
            {
                cout << "a>b" << endl;
            }
            if (a <= b)
            {
                cout << "a<=b" << endl;
            }
            if (a < b)
            {
                cout << "a<b" << endl;
            }
            if (a == b)
            {
                cout << "a==b" << endl;
            }
            menu();
            break;
        }
        case 0:
        {
            return 0;
        }
        }
    }
}

void menu()
{
    cout << endl << "MENU" << endl << endl << "1. Vector + Vector" << endl << "2. Vector * Vector (scalar)" << endl << "3. Vector * Number" << endl << "4. Angle beetweeen Vectors" << endl << "5.  Vector - Vector" << endl << "6. Comparison" << endl << "0. EXIT" << endl;
}

Vector::Vector()
{
    size = 2;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = 0;
    }
}

Vector::Vector(int new_size, float* new_coords)
{
    size = new_size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = new_coords[i];
    }
}

Vector::Vector(int new_size)
{
    size = new_size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = 0;
    }
}

Vector::Vector(const Vector& copy)
{
    size = copy.size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = copy.coords[i];
    }
}

Vector::~Vector()
{
    delete[] coords;
}

void Vector::input()
{
    cout << "Enter size: ";
    cin >> size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter coordinate: ";
        cin >> coords[i];
    }
}

void Vector::output()
{
    for (int i = 0; i < size; i++)
    {
        cout << coords[i] << " ";
    }
}

double Vector::angle(Vector& a)
{
    if (size == a.size)
    {
        int tmp = *this * a;
        double fabs = 0;
        fabs = tmp / (abs(*this) * abs(a));
        return (acos(fabs) * 180 / PI);
    }
    else
    {
        cout << "Vectors should be the same size";
        return 0;
    }
}

double Vector::abs(Vector& a)
{
    double abs = 0;
    for (int i = 0; i < a.size; i++)
    {
        abs += a.coords[i] * a.coords[i];
    }
    return sqrt(abs);
}

Vector Vector::operator= (const Vector& a)
{
    Vector Temp(size);
    Temp.coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        Temp.coords[i] = a.coords[i];
    }
    return Temp;
}

Vector Vector::operator+ (const Vector& a)
{
    if (size == a.size)
    {
        Vector Temp(size);
        for (int i = 0; i < size; i++)
        {
            Temp.coords[i] = coords[i] + a.coords[i];
        }
        return Temp;
    }
    else
    {
        Vector Temp;
        cout << "Vectors should be the same size";
        return Temp;
    }
}

Vector Vector::operator- (const Vector& a)
{
    if (size == a.size)
    {
        Vector Temp(size);
        for (int i = 0; i < size; i++)
        {
            Temp.coords[i] = coords[i] - a.coords[i];
        }
        return Temp;
    }
    else
    {
        Vector Temp;
        cout << "Vectors should be the same size";
        return Temp;
    }
}

int Vector::operator* (const Vector& a)
{
    int Temp = 0;
    if (size == a.size)
    {
        for (int i = 0; i < size; i++)
        {
            Temp += coords[i] * a.coords[i];
        }
        return Temp;
    }
    else
    {
        cout << "Vectors should be the same size";
        return 0;
    }
}

Vector Vector::operator* (const int a)
{
    Vector Temp(size);
    for (int i = 0; i < size; i++)
    {
        Temp.coords[i] = coords[i] * a;
    }
    return Temp;
}

istream& operator>> (istream& in, Vector& a)
{
    cout << "Enter size: ";
    in >> a.size;
    if (a.size < 2)
    {
        do
        {
            cout << "Size should be >= 2. Try again" << endl;
            in >> a.size;
        } while (a.size < 2);
    }
    a.coords = new float[a.size];
    for (int i = 0; i < a.size; i++)
    {
        cout << "Enter coordinate: ";
        in >> a.coords[i];
    }
    return in;
}

ostream& operator<< (ostream& out, const Vector& a)
{
    cout << "(";
    for (int i = 0; i < a.size; i++)
    {
        if (i < (a.size - 1))
        {
            out << a.coords[i] << ", ";
        }
        else out << a.coords[i] << ")";
    }
    return out;
}

bool Vector::operator> (Vector& a)
{
    if (abs(*this) > abs(a))
        return 1;
    else return 0;
}

bool Vector::operator< (Vector& a)
{
    if (abs(*this) < abs(a))
        return 1;
    else return 0;
}

bool Vector::operator<= (Vector& a)
{
    if (abs(*this) <= abs(a))
        return 1;
    else return 0;
}

bool Vector::operator>= (Vector& a)
{
    if (abs(*this) >= abs(a))
        return 1;
    else return 0;
}

bool Vector::operator== (Vector& a)
{
    if (abs(*this) == abs(a))
        return 1;
    else return 0;
}

bool Vector::operator!= (Vector& a)
{
    if (abs(*this) != abs(a))
        return 1;
    else return 0;
}