#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265  

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

class complex
{
    float re, im;
public:

    complex(float input_re = 0, float input_im = 0);
    complex(const complex& copy);

    void input(float input_re, float input_im);
    void output();
    float module();

    complex operator+ (const complex& a);
    complex operator* (const complex& a);
    bool operator== (complex& a);
    bool operator!= (complex& a);
    bool operator> (complex& a);
    bool operator< (complex& a);
    bool operator<= (complex& a);
    bool operator>= (complex& a);

    friend ostream& operator<< (ostream& out, const complex& c);
    friend istream& operator>> (istream& in, complex& c);
};

template <class T>
class Vector
{
    int size;
    T* coords;

public:

    Vector();
    Vector(int new_size, T* new_coords);
    Vector(int new_size);
    ~Vector();
    Vector(const Vector& copy);
    double angle(Vector& a);
    T abs(Vector& a);
    Vector operator= (const Vector<T>& a);
    Vector operator+ (const Vector& a);
    Vector operator- (const Vector& a);
    T operator* (const Vector& a);
    Vector operator* (const T a);
    bool operator> (Vector& a);
    bool operator< (Vector& a);
    bool operator<= (Vector& a);
    bool operator>= (Vector& a);
    bool operator== (Vector& a);
    bool operator!= (Vector& a);

    template<class T> friend istream& operator>> (istream& in, Vector<T>& a);
    template<class T> friend ostream& operator<< (ostream& out, const Vector<T>& a);
    template<class T> friend int get_size(Vector<T>& a);
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
            Vector<complex> a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; //(3+2i, 5i, 9)
            cout << "Enter Vector b: (should be same size with Vector a)" << endl;
            cin >> b; //(5+4i, 4, 1i)
            if (get_size(a) != get_size(b))
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Отыет: (8+6i, 4+5i, 9+1)
                Vector<complex> c = a + b;
                cout << endl << a << " + " << b << " = " << c << endl;
            }
            menu();
            break;
        }
        case 2:
        {
            Vector<complex> a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; //(8+3i, 3i, 10, 4+10i)
            cout << "Enter Vector b (should be same size with Vector a):" << endl;
            cin >> b; //(7+5i, 9, 2i, 12+5i)
            if (get_size(a) != get_size(b))
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Отыет: 39 + 248i
                cout << endl << a << " * " << b << " = " << a * b << endl;
            }
            menu();
            break;
        }
        case 3:
        {
            Vector<complex> a;
            complex n;
            cout << "Enter Vector a: " << endl;
            cin >> a; // (11+10i, 7+6i)
            cout << "Enter number: " << endl;
            cin >> n; //3+2i
            //Отыет: (13+52i, 9+32i)
            cout << endl << n << " * " << a << " = " << a * n << endl;
            menu();
            break;
        }
        case 4:
        {
            Vector<int> a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; // Координаты  а: (2, 6)
            cout << "Enter Vector b: (should be same size with Vector a)" << endl;
            cin >> b; // Координаты  b: (8, 4)
            if (get_size(a) != get_size(b))
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
            Vector<float> a, b;
            cout << "Enter Vector a: " << endl;
            cin >> a; //(1.11, 22.2, 12.12, 8.88)
            cout << "Enter Vector b: (should be same size with Vector a)" << endl;
            cin >> b;//(2.21, 5.55, 7.71, 12.22)
            if (get_size(a) != get_size(b))
            {
                cout << "Vectors should be the same size";
            }
            else
            {
                //Отыет: (-1.1, 16.65, 4.41, -3.34)
                cout << endl << a << " - " << b << " = " << a - b << endl;
            }
            menu();
            break;
        }
        case 6:
        {
            Vector<unsigned int> a, b;
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

template <class T>
Vector<T>::Vector()
{
    size = 2;
    coords = new T[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = 0;
    }
}

template <class T>
Vector<T>::Vector(int new_size, T* new_coords)
{
    size = new_size;
    coords = new T[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = new_coords[i];
    }
}

template <class T>
Vector<T>::Vector(int new_size)
{
    size = new_size;
    coords = new T[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = 0;
    }
}

template <class T>
Vector<T>::Vector(const Vector& copy)
{
    size = copy.size;
    coords = new T[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = copy.coords[i];
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete[] coords;
}

template <class T>
double Vector<T>::angle(Vector& a)
{
    if (size == a.size)
    {
        T tmp = *this * a;
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

template <class T>
T Vector<T>::abs(Vector& a)
{
    T abs = 0;
    for (int i = 0; i < a.size; i++)
    {
        abs += a.coords[i] * a.coords[i];
    }
    return sqrt(abs);
}

template <class T>
Vector<T> Vector<T>::operator= (const Vector<T>& a)
{
    ~Vector();
    this->coords = new T[size];
    for (int i = 0; i < size; i++)
    {
        this->coords[i] = a.coords[i];
    }
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector& a)
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

template <class T>
Vector<T> Vector<T>::operator- (const Vector& a)
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

template <class T>
T Vector<T>::operator* (const Vector& a)
{
    T Temp = 0;
    if (size == a.size)
    {
        for (int i = 0; i < size; i++)
        {
            Temp = Temp + coords[i] * a.coords[i];
        }
        return Temp;
    }
    else
    {
        cout << "Vectors should be the same size";
        return 0;
    }
}

template <class T>
Vector<T> Vector<T>::operator* (const T a)
{
    Vector<complex> Temp(size);
    for (int i = 0; i < size; i++)
    {
        Temp.coords[i] = coords[i] * a;
    }
    return Temp;
}

template <class T>
istream& operator>> (istream& in, Vector<T>& a)
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
    a.coords = new T[a.size];
    for (int i = 0; i < a.size; i++)
    {
        cout << "Enter coordinate: ";
        in >> a.coords[i];
    }
    return in;
}

template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
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

template <class T>
bool Vector<T>::operator> (Vector& a)
{
    if (abs(*this) > abs(a))
        return 1;
    else return 0;
}

template <class T>
bool Vector<T>::operator< (Vector& a)
{
    if (abs(*this) < abs(a))
        return 1;
    else return 0;
}

template <class T>
bool Vector<T>::operator<= (Vector& a)
{
    if (abs(*this) <= abs(a))
        return 1;
    else return 0;
}

template <class T>
bool Vector<T>::operator>= (Vector& a)
{
    if (abs(*this) >= abs(a))
        return 1;
    else return 0;
}

template <class T>
bool Vector<T>::operator== (Vector& a)
{
    if (abs(*this) == abs(a))
        return 1;
    else return 0;
}

template <class T>
bool Vector<T>::operator!= (Vector& a)
{
    if (abs(*this) != abs(a))
        return 1;
    else return 0;
}

template <class T>
int get_size(Vector<T>& a)
{
    return a.size;
}

complex::complex(float input_re, float input_im)
{
    re = input_re;
    im = input_im;
}

complex::complex(const complex& copy)
{
    re = copy.re;
    im = copy.im;
}

void complex::output()
{
    if (re != 0)
    {
        cout << re;
    }
    if (im > 0 && im != 1 && re == 0)
    {
        cout << im << "*i";
    }
    else if (im > 0 && im != 1)
    {
        cout << "+" << im << "*i";
    }
    else if (im < 0 && im != -1)
    {
        cout << im << "*i";
    }
    else if (im == 0 && re == 0)
    {
        cout << "0";
    }
    else if (im == 1 && re != 0)
    {
        cout << "+i";
    }
    else if (im == 1 && re == 0)
    {
        cout << "i";
    }
    else if (im == -1)
    {
        cout << "-i";
    }
}

void complex::input(float input_re, float input_im)
{
    re = input_re;
    im = input_im;
}

float complex::module()
{
    return sqrt(re * re + im * im);
}

complex complex::operator+ (const complex& a)
{
    complex temp;
    temp.re = re + a.re;
    temp.im = im + a.im;
    return temp;
}

complex complex::operator* (const complex& a)
{
    complex temp;
    temp.re = re * a.re - im * a.im;
    temp.im = re * a.im + a.re * im;
    return temp;
}

bool complex::operator== (complex& a)
{
    if (this->module() == a.module())
        return 1;
    else return 0;
}

bool complex::operator!= (complex& a)
{
    if (this->module() != a.module())
        return 1;
    else return 0;
}

bool complex::operator> (complex& a)
{
    if (this->module() > a.module())
        return 1;
    else return 0;
}

bool complex::operator< (complex& a)
{
    if (this->module() < a.module())
        return 1;
    else return 0;
}

bool complex::operator<= (complex& a)
{
    if (this->module() <= a.module())
        return 1;
    else return 0;
}

bool complex::operator>= (complex& a)
{
    if (this->module() >= a.module())
        return 1;
    else return 0;
}

ostream& operator<< (ostream& out, const complex& c)
{
    if (c.re != 0)
    {
        out << c.re;
    }
    if (c.im > 0 && c.im != 1 && c.re == 0)
    {
        out << c.im << "*i";
    }
    else if (c.im > 0 && c.im != 1)
    {
        out << "+" << c.im << "*i";
    }
    else if (c.im < 0 && c.im != -1)
    {
        out << c.im << "*i";
    }
    if (c.im == 0 && c.re == 0)
    {
        out << "0";
    }
    if (c.im == 1 && c.re != 0)
    {
        out << "+i";
    }
    if (c.im == 1 && c.re == 0)
    {
        out << "i";
    }
    if (c.im == -1)
    {
        out << "-i";
    }
    return out;
}

istream& operator>> (istream& in, complex& c)
{
    in >> c.re;
    in >> c.im;
    return in;
}