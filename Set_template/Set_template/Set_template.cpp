#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
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
	void Elimination(T a);
	Set Union(Set& a); //объединение
	Set Intersection(Set& a); //пересечение
	bool Find(T a); //Проверка на эл-т в множестве
	int get_size();
	bool isContain(Set& a);

	Set& operator= (const Set& a);
	bool operator> (const Set& a);
	bool operator< (const Set& a);
	bool operator== (const Set& a);
	bool operator!= (const Set& a);
	template<typename T1> friend istream& operator>> (istream& in, Set<T1>& a);
	template<typename T1> friend ostream& operator<< (ostream& out, Set<T1>& a);
	template<typename T> friend ifstream& operator>> (ifstream& fin, Set<T>& a); 
};

void menu();
void max(int a, int b, int c);

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
			Set <int> a, b;
			cout << "input Set a" << endl;
			cin >> a;
			cout << "input Set b" << endl;
			cin >> b;
			Set <int> c = a.Intersection(b);
			cout << "Intersection of sets a and b: " << c;
			menu();
			break;
		}
	case 2:
		{
			Set <int> a;
			int n;
			cout << "input Set a" << endl;
			cin >> a;
			cout << "input n" << endl;
			cin >> n;
			a.insert(n);
			cout << a;
			menu();
			break;
		}
		case 3:
		{
			Set <int> a, b;
			cout << "input Set a" << endl;
			cin >> a;
			cout << "input Set b" << endl;
			cin >> b;
			Set <int> c = a.Union(b);
			cout << "Union of sets a and b: " << c;
			menu();
			break;
		}
		case 4:
		{
			Set <int> a;
			int n;
			cout << "input Set a" << endl;
			cin >> a;
			cout << "input n" << endl;
			cin >> n;
			if (a.Find(n) == true)
			{
				cout << n << " is part of set" << endl;
			}
			else
			{
				cout << n << " isn't part of set" << endl;
			}
			menu();
			break;
		}
		case 5:
		{
			Set <int> a;
			int n;
			cout << "input Set a" << endl;
			cin >> a;
			cout << "input n" << endl;
			cin >> n;
			a.Elimination(n);
			cout << a;
			menu();
			break;
		}
		case 6:
		{
			Set <int> M, M1(5), M2(6), M3(3);
			ifstream set("values.txt");
			if (!set)
			{
				cout << "Error";
				break;
			}
			set >> M1;//{3 7 991 53 5}
			set >> M2; //{997 991 397 307 499 977}
			set >> M3; //{2 3 5}
			set.close();
			cout << "M1 has size: " << M1.get_size() << endl << "M2 has size: " << M2.get_size() << endl << "M3 has size: " << M3.get_size() << endl;
			max(M1.get_size(), M2.get_size(), M3.get_size());
			cout << endl;
			if (M1.isContain(M2) == true)
			{
				cout << "M1 contains M2" << endl;
			}
			else
			{
				cout << "M1 doesnt contain M2" << endl;
			}
			M = M1.Intersection(M2);
			cout << "M1 has intersection with M2 : " << M << endl << "add element to M1" << endl;
			int a;
			cout << "input a" << endl;
			cin >> a;
			M1.insert(a);
			cout << M1;
			int b;
			cout << "delete element from M2" << endl << "input b" << endl;
			cin >> b;
			M2.Elimination(b);
			cout << M2 << endl;
			Set <int> M4;
			M4 = M2.Union(M3);
			cout << "Union of M2 and M3: " << M4 << endl;
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
	cout << endl << "MENU" << endl << endl << "1. Intersection" << endl << "2. Insert" << endl << "3. Union" << endl << "4. Is element part of set" << endl << "5. Elimination" << endl << "6. Exercise 2" << endl<< "0. EXIT" << endl;
}

void max(int a, int b, int c)
{
	
	if (a >= c && a >= b) 
	{
		if (a == b)
		{
			cout << "M1 and M2 has biggest size";
		}
		else if (a == c)
		{
			cout << "M1 and M3 has biggest size";
		}
		
		else if (a == c && a == b)
		{
			cout << "M1, M2 and M3 has the same size";
		}
		else
		{
			cout << "M1 is biggest set";
		}
	}
	if (b > a && b >= c) 
	{
		if(b==c)
		{
			cout << "M2 and M3 has biggest size";
		}
		else
		{
			cout << "M2 is biggest set";
		}
	}
	if (c > a && c > b) cout << "M3 is biggest set";
}

template<typename T>
bool Set<T>::isSet(T a)//Является ли простым
{
	for (int i = 2; i < sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
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
		if (!this->Find(a))
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

template<class T>
void Set<T>::Elimination(T a)
{
	if (isSet(a))
	{
		if (Find(a))
		{
			Set Temp = *this;
			delete[] set;
			set = new T[--size];
			int k = 0;
			for (int i = 0; i < Temp.size; i++)
			{
				if (Temp.set[i] == a)
				{
					continue;
				}
				else
					set[k++] = Temp.set[i];
			}
		}
		else
		{
			cout << "doesn't exist" << endl;
		}
	}
	else
	{
		cout << "Can't be part of set" << endl;
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
	Set<T> Temp(size);
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (a.Find(set[i]))
		{
			Temp.set[k++] = set[i];
		}
	}

	Set<T> Buf(k);
	for (int i = 0; i < k; i++)
	{
		Buf.set[i] = Temp.set[i];
	}

	return Buf;
}

template<typename T>
int Set<T>::get_size()
{
	return this ->size;
}

template<class T>
bool Set<T>::isContain(Set<T>& a)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < a.size; j++)
		{
			if (set[i] == a.set[j]) count++;
		}
	}
	if (count == size)
		return true;
	else
		return false;
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
Set<T>& Set<T>::operator=(const Set<T>& a)
{
	delete[] set;

	size = a.size;

	set = new T[size];

	for (int i = 0; i < size; i++)
	{
		set[i] = a.set[i];
	}
	return *this;
}

template<typename T>
bool Set<T>::operator>(const Set& a)
{
	if (size > a.size)
		return true;
	return false;
}

template<typename T>
bool Set<T>::operator<(const Set& a)
{
	if (size < a.size)
		return true;
	return false;
}

template<typename T>
bool Set<T>::operator==(const Set& a)
{
	if (size == a.size)
		return true;
	return false;
}

template<typename T>
bool Set<T>::operator!=(const Set& a)
{
	if (size != a.size)
		return true;
	return false;
}

template <typename T1>
istream& operator>> (istream& in, Set<T1>& a)
{
	T1 x;
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

	a.set = new T1[a.size];
	for (int i = 0; i < a.size; i++)
	{
		do
		{
			cout << "Enter number: ";
			cin >> x;
			if (a.isSet(x) && !a.Find(x))
			{

				a.set[i] = x;
				break;
			}
			else
			{
				cout << "Can't be part of set!" << endl;
			}
		} while (1);
	}
	return in;
}

template <typename T1>
ostream& operator<< (ostream& out, Set<T1>& a)
{
	cout << "{";
	for (int i = 0; i < a.size; i++)
	{
		out << a.set[i] << " ";
	}
	cout << "}";
	out << endl;

	return out;
}

template<typename T>
ifstream& operator>>(ifstream& fin, Set<T>& a)
{
	T temp;
	for (int i = 0; i < a.size; i++)
	{
		fin >> temp;
		a.set[i] = temp;
	}
	return fin;
}
