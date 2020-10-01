#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

void menu();

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
    friend bool operator== (complex& left, complex& right);
    friend bool operator!= (complex& left, complex& right);
    friend bool operator> (complex& left, complex& right);
    friend bool operator< (complex& left, complex& right);
    friend bool operator<= (complex& left, complex& right);
    friend bool operator>= (complex& left, complex& right);

    friend ostream& operator<< (ostream& out, const complex& c);
    friend istream& operator>> (istream& in, complex& c);
};

int main()
{
    //Lab Complex_class

    menu();
    int num = 1;
    while (num != 0)
    {
        cin >> num;
        switch (num)
        {
        case 1:
        {
            complex c1, c2, sum, mult;
            float re, im;
            cout << "Enter c1:" << endl << "re = "; // 1)2-8i 2) 2i 3)11+9i 4)4 5)2-i
            cin >> re;
            cout << "im = ";
            cin >> im;
            c1.input(re, im);
            cout << "Enter c2:" << endl << "re = "; //1)5+10i 2) 6i 3) 20i 4)20 5)-2+i
            cin >> re;
            cout << "im = ";
            cin >> im;
            c2.input(re, im);
            cout << "c1 = ";
            c1.output();
            cout << endl << "c2 = ";
            c2.output();
            sum = c1 + c2; // 1) 7+2i 2) +8i 3) 11+29i 4)24 5)0
            cout << endl << "c1 + c2 = ";
            sum.output();
            mult = c1 * c2; // 1) 90-20i 2) -12 3-180+220i) 4)80 5) -3+4i
            cout << endl << "c1 * c2 = ";
            mult.output();
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
    cout << endl << "MENU" << endl << endl << "1. Plus and mult complex numbers" << endl << "0. EXIT" << endl;
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

bool operator== (complex& left, complex& right)
{
    return left.module() == right.module();
}

bool operator!= (complex& left, complex& right)
{
    return left.module() != right.module();
}

bool operator> (complex& left, complex& right)
{
    return left.module() > right.module();
}

bool operator< (complex& left, complex& right)
{
    return left.module() < right.module();
}

bool operator<= (complex& left, complex& right)
{
    return left.module() <= right.module();
}

bool operator>= (complex& left, complex& right)
{
    return left.module() >= right.module();
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
    if (c.im > 0 && c.im != 1)
    {
        out << "+" << c.im << "*i";
    }
    if (c.im < 0 && c.im != -1)
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
    in >> c.re >> c.im;
    in >> c.im;
    return in;
}