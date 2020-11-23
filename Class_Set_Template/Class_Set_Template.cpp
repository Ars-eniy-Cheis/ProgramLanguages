#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

template <typename T>
class Set
{
    int size;
    T* set;
    bool isSet(T a);

public:
    Set(int n = 0);
    Set(const Set& copy);
    ~Set();

    void insert(T a);
    Set Union(Set& a);
    Set Intersection(Set& a);
    bool Find(T a);

    Set operator= (const Set& a);

    template<typename T1> friend istream& operator>> (istream& in, Set& a);
    template<typename T1> friend ostream& operator<< (ostream& out, Set& a);
};

void menu();

int main()
{
    menu();
    int num = 1;
    while (num != 0)
    {
        cin >> num;
        switch (num)
        {
        case 1:
        {

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
    cout << endl << "MENU" << endl << endl << "1. Intersection" << endl << "2. Insert" << endl << "0. EXIT" << endl;
}

template<typename T>
bool Set<T>::isSet(T a)
{
    if (1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
Set<T>::Set(int n)
{
    size = n;
    set = new T[size];
}

template<typename T>
Set<T>::Set(const Set& copy)
{
    size = copy.size;

    set = new T[size];

    for (int i = 0; i < size; i++)
    {
        set[i] = copy.set[i];
    }
}

template<typename T>
Set<T>::~Set()
{
    delete[] set;
}

template<typename T>
void Set<T>::insert(T a)
{
    if (this->isSet(a))
    {
        if (!this->Find())
        {
            Set Temp = *this;
            delete[] this->set;

            set = new T[++size];

            for (int i = 0; i < size - 1; i++)
            {
                set[i] = Temp.set[i];
            }

            set[size - 1] = a;
        }

        else
        {
            cout << "Alredy exsist!" << endl;
        }
    }
    else
    {
        cout << "Can't be part of Set!" << endl;
    }
}

template<typename T>
Set<T> Set<T>::Union(Set& a)
{
    int n = size + a.size;
    int k = size;
    Set Temp(n);

    for (int i = 0; i < size; i++)
    {
        Temp.set[i] = set[i];
    }

    for (int i = 0; i < a.size; i++)
    {
        if (!Temp.Find(a.set[i]))
        {
            Temp.set[k++] = a.set[i];
        }
    }

    Set Buf(k);

    for (int i = 0; i < k; i++)
    {
        Buf.set[i] = Temp.set[i];
    }

    return Buf;
}

template<typename T>
Set<T> Set<T>::Intersection(Set& a)
{
    Set Temp(size);
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (a.Find(set[i]))
        {
            Temp.set[k++] = set[i];
        }
    }

    Set Buf(k);
    for (int i = 0; i < k; i++)
    {
        Buf.set[i] = Temp.set[i];
    }

    return Buf;
}

template<typename T>
bool Set<T>::Find(T a)
{
    for (int i = 0; i < size; i++)
    {
        if (a == set[i])
            return true;
    }

    return false;
}

template<typename T>
Set<T> Set<T>::operator=(const Set<T>& a)
{
    delete[] set;

    size = a.size;

    set = new T[size];

    for (int i = 0; i < size; i++)
    {
        set[i] = a.set[i];
    }
    return Set;
}

template <typename T>
istream& operator>> (istream& in, Set<T>& a)
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
    a.set = new T[a.size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number: ";
        in >> a.set[i];

        if (a.Find(a.set[i]))
        {
            do
            {
                cout << "Already exsists!" << endl;
                in >> a.set[i];
            } while (a.Find(a.set[i]));
        }
    }
    return in;
}

template <typename T>
ostream& operator<< (ostream& out, Set<T>& a)
{
    for (int i = 0; i < size; i++)
    {
        out << set[i] << " ";
    }
    out << endl;

    return out;
}
