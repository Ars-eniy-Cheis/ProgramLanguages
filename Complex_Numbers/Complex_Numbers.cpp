#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

struct complex 
{
    float re, im;
    void print();
    complex operator+ (complex a);
    complex operator* (complex a);
    void set(float, float b);
    void input();
};

int main()
{
    complex c1, c2, sum, mult;
    cout << "Enter c1: " << endl;
    c1.input();
    cout << "Enter c2: " << endl;
    c2.input();
    cout << "c1 = ";
    c1.print();
    cout << "c2 = ";
    c2.print();
    sum = c1 + c2;
    cout << "c1 + c2 = ";
    sum.print();
    mult = c1 * c2;
    cout << "c1 * c2 = ";
    mult.print();

    return 0;
}

void complex::input()
{
    cout << "Real part: ";
    cin >> re;
    cout << "Imagine part: ";
    cin >> im;
}

void complex::print()
{
    if (re != 0)
    {
        cout << re;
    }
    if (im > 0 && im != 1 && re == 0)
    {
        cout << im << "*i";
    }
    if (im > 0 && im != 1)
    {
        cout << "+" << im << "*i";
    }
    if (im < 0 && im != -1)
    {
        cout << im << "*i";
    }
    if (im == 0 && re == 0)
    {
        cout << "0";
    }
    if (im == 1 && re != 0)
    {
        cout << "+i";
    }
    if (im == 1 && re == 0)
    {
        cout << "i";
    }
    if (im == -1)
    {
        cout << "-i";
    }
    cout << endl;
}

complex complex::operator+ (complex a)
{
    complex temp;
    temp.re = re + a.re;
    temp.im = im + a.im;
    return temp;
}

void complex::set(float a, float b)
{
    re = a;
    im = b;
}

complex complex::operator* (complex a)
{
    complex temp;
    temp.re = re * a.re - im * a.im;
    temp.im = re * a.im + a.re * im;
    return temp;
}