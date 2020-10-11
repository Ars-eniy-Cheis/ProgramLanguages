#define _CRT_SECURE_NO_WARNINGS
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

void menu();

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
            cout << "Enter c1:" << endl; // 1)2-8i 2) 2i 3)11+9i 4)4 5)2-i
            cin >> c1;
            cout << "Enter c2:" << endl; //1)5+10i 2) 6i 3) 20i 4)20 5)-2+i
            cin >> c2;
            cout << "c1 = " << c1;
            cout << endl << "c2 = " << c2;
            sum = c1 + c2; // 1) 7+2i 2) +8i 3) 11+29i 4)24 5)0
            cout << endl << "c1 + c2 = " << sum;
            mult = c1 * c2; // 1) 90-20i 2) -12 3-180+220i) 4)80 5) -3+4i
            cout << endl << "c1 * c2 = " << mult << endl;
            menu();
            break;
        }
        case 2:
        {
            complex c1, c2;
            cout << "Enter c1:" << endl;
            cin >> c1;// 1)4+3i 2)4+3i
            cout << "Enter c2:" << endl;
            cin >> c2;//1)5 2) 5+i
            //Ответ: 1)c1>=c2 c1<=c2 c1==c2; 2)c1<=c2 c1<c2 c1 != c2
            if (c1 >= c2)
            {
                cout << "c1 >= c2" << endl;
            }
            if (c1 <= c2)
            {
                cout << "c1 <= c2" << endl;
            }
            if (c1 > c2)
            {
                cout << "c1 > c2" << endl;
            }
            if (c1 < c2)
            {
                cout << "c1 < c2" << endl;
            }
            
            if (c1 == c2)
            {
                cout << "c1 == c2" << endl;
            }
            if (c1 != c2)
            {
                cout << "c1 != c2" << endl;
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
    cout << endl << "MENU" << endl << endl << "1. Plus and mult complex numbers" << endl << "2. Comparison" << endl << "0. EXIT" << endl;
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
    in >> c.re;
    in >> c.im;
    return in;
}