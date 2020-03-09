
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include <fstream>

using namespace std;

void output(int a[], int n);
int rand_in_bounds(int a, int b);
void Bubble_sort(int a[], int n);

int main()
{
	//Variant 3, Number 1
	//Все тестовые данные берутся из случайнго сгенерированного файла с расширением .txt
	int num, n = 0;
	cout << "Enter number (1 or 2)" << endl;
	cin >> num;
	if (num != 1 && num != 2)
	{
		do
		{
			cout << "There aren't such number" << endl;
			cin >> num;
		} while (num != 1 && num != 2);
	}
	if (num == 1) 
	{
		cout << "Number 1" << endl;
		ofstream file_r;
		file_r.open("random.txt");
		for (int i = 0; i < 1000; i++)
		{
			file_r << rand() % 1000 - 200 << " ";
		}
		file_r.close();
		ifstream file_wr;
		
		file_wr.open("random.txt");
		int x;
		while (!file_wr.eof())
		{
			file_wr >> x;
			if (abs(x % 2) == 0)
			{
				n++;
			}

		}
		file_wr.close();
		int* a = new int[n];
		cout << "Quantity of even ellements = " << n << endl;
		file_wr.open("random.txt");
		int j = 0;
		while (!file_wr.eof())
		{
			file_wr >> x;
			if (abs(x % 2) == 0)
			{
				a[j] = x;
				j++;
			}
		}
		Bubble_sort(a, n);
		output(a, n);
		delete[] a;
	}
	
	else if (num == 2)
	{
		//Number 2
		cout << endl << "Number 2" << endl;
		int A, B;
		cout << "enter int left bound (include)" << endl;
		cin >> A; //Левая граница: 100 
		cout << "enter int right bound (include and bigger then left)" << endl;
		cin >> B; //Правая граница 250 
		if (B <= A)// (для примера можно ввести правую границу 90, тогда программа попросит ввести правую границу больше, чем левую) 
		{
			do
			{
				cout << "right bound should be bigger then left bound" << endl;
				cin >> B;
			} while (B <= A);
		}
		cout << "enter quantity of elements of array" << endl;
		cin >> n; //Размерность массива: 7
		int* a = new int[n];
		int m = 0;
		for (int i = 0; i < n; i++)//Цикл случайно генерирует числа для массива в заданном диапозоне и считает кол-во чётных чисел m
		{
			a[i] = rand_in_bounds(A, B);
			if (a[i] % 2 == 0)
			{
				m++;
			}
		}
		cout << "Initial array: " << endl;
		output(a, n); //Вывод начального массива (В моём случае сгенерировалась послледовательность: {191 118 203 112 227 200 168}
		int* b = new int[m];// Создаём новый массив размерностью m для чётных чисел 
		int k = 0;
		for (int i = 0; i < n; i++)//Перезаписываем чётные эл-ты в новый массив
		{
			if (a[i] % 2 == 0)
			{
				b[k] = a[i];
				k++;
			}
		}
		cout << endl << "Final array: " << endl;
		delete[] a;
		output(b, k); //При выводе массива с чётными эл-тами сравниваем его с начальным и видим, что программа выполняется правильно (Мой случай: {118 112 200 168})
		delete[] b;
	}
	
}

void output(int a[], int n) 
{
	/*
	На вход получаем целочисленный массив a его размерность n (тоже целочисленную)
	Через цикл for осуществляется вывод массива
	*/
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}//Вывод массива

int rand_in_bounds(int a, int b)
{
	/*
	На вход получаем целочисленное число a (левая граница) и b (правая граница)
	Через заданную формулу генерируется случайное число в заданном диапозоне и присваивается целочисленной переменной g
	функция возвращает целочисленную переменную g - случайно сгенерированое значение в заданном диапозоне [a;b]
	*/
	int g = rand() % (b - a + 1) + a;
	return g;
}//Cлучайное число в заданном диапозоне

void Bubble_sort(int a[], int n)
{
	/*
	На вход получаем целочисленный масссив a и его размерность n (тоже целочисленную)
	Сортировк происходит методом "Пузырька". По очереди берётся каждый эллемент массива и сравнивается со следующим. Если текущий элемент оказывается больше следущего, то они меняются местами и так до конца.
	В итоге получаем отсортированный по возрастанию массив
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
}//Пузырьковая сортировка