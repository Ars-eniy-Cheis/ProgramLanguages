// 2DArrays.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>

using namespace std;

void trans_sqr(int** a, int n);
void trans_any(int** a, int** b, int n, int m);
void D2_input(int** a, int n, int m);
void D2_output(int** a, int n, int m);
void matrix_sum(int** a, int** b, int** c, int n, int m);
void matrix_mult(int** a, int** b, int** c, int n, int m, int k);

int main()
{
	int n, m;
	cout << "Enter quantity of columns" << endl;
	cin >> n; //колонки
	cout << "Enter quantity of strings" << endl;
	cin >> m; //строки
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	D2_input(a, n, m);

	//Обязательные задания. №1
	cout << "Required task №1. Transpotting if Matrix" << endl;
	cout <<"original matrix: "<< endl;
	D2_output(a, n, m);
	if (n == m)
	{
		trans_sqr(a, n);
		cout << "Transpotted sqare matrix: " << endl;
		D2_output(a, n, m);
	}
	else
	{
		int** b = new int* [m];
		for (int i = 0; i < m; i++)
		{
			b[i] = new int[n];
		}
		trans_any(a, b, n, m);
		cout << "Transpotted not-sqare matrix: " << endl;
		D2_output(b, m, n);
		for (int i = 0; i < m; i++)
		{
			delete b[i];
		}
		delete b;
	}
	

	//Обязательные задания. №2
	cout << "Required task №2. Sum of 2 Matrix" << endl;
	cout << "matrix a: " << endl;
	D2_output(a, n, m);
	cout << "matrix b: " << endl;
	int** b = new int* [n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[m];
	}
	D2_input(b, n, m);
	D2_output(b, n, m);
	cout << "a + b = " << endl;
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[m];
	}
	matrix_sum(a, b, c, n, m);
	D2_output(c, n, m);
	for (int i = 0; i < n; i++)
	{
		delete b[i];
	}
	delete b;
	for (int i = 0; i < n; i++)
	{
		delete c[i];
	}
	delete c;

	//Обязательные задания. №3
	cout << "Required task №3. multiplication of matrix " << endl;
	cout << "matrix a: " << endl;
	D2_output(a, n, m);
	cout << "enter quantity of columns for Matrix b" << endl;
	int k;
	cin >> k;
	cout << "matrix b: " << endl;
	b = new int* [m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new int[k];
	}
	D2_input(b, m, k);
	D2_output(b, m, k);
	cout << "a * b = " << endl;
	c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[k];
	}
	matrix_mult(a, b, c, n, m, k);
	D2_output(c, n, k);
	for (int i = 0; i < m; i++)
	{
		delete b[i];
	}
	delete b;
	for (int i = 0; i < n; i++)
	{
		delete c[i];
	}
	delete c;

	//Обязательные задания. №4
	cout << "Required task №4. multiplicate matrix on a vector " << endl;
	cout << "matrix a: " << endl;
	D2_output(a, n, m);
	cout << "vector b: " << endl;
	b = new int* [m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new int[1];
	}
	D2_input(b, m, 1);
	D2_output(b, m, 1);
	cout << "matrix a * vector b = " << endl;
	c = new int* [n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new int[m];
	}
	matrix_mult(a, b, c, n, m, 1);
	D2_output(c, n, 1);
	for (int i = 0; i < m; i++)
	{
		delete b[i];
	}
	delete b;
	for (int i = 0; i < n; i++)
	{
		delete c[i];
	}
	delete c;
	//Variant 4. Номер 1


	return 0;
}

void trans_sqr(int** a, int n)
{
	/*На вход получаем двумерный массив a из целых чисел размером n на n.
	Матрица транспонируется по следующей формуле: Меняем местами строки со столбцами
	На выходе получаем транспонированную матрицу*/
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}

}//Транспонирование квадратной матрицы

void trans_any(int** a, int** b, int n, int m)
{
	/*На вход получаем два двумерных массивa a и b из целых чисел размером n на m и m на n соответственно.
	Матрица транспонируется по следующей формуле: Меняем местами строки со столбцами
	На выходе получаем новую транспонированную матрицу*/

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[j][i];
		}
	}

}//Транспонимрование любой матрицы

void D2_input(int** a, int n, int m)
{
	/*
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
}//Случайный ввод двумерного массива

void D2_output(int** a, int n, int m)
{
	/*
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d", a[i][j]);
		}
		cout << endl;
	}
}//Вывод двумерного массива

void matrix_sum(int** a, int** b, int** c ,int n, int m)
{
	/*
	считаем по правилу: c[i][j] = a[i][j]+b[i][j]

	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}


}//Сумма двух матриц

void matrix_mult(int** a, int** b, int** c, int n, int m, int k)
{
	/*

	считаем по правилу: c[i][j] = a[i][1]*b[1][j]+a[i][2]*b[2][j]+...+a[i][k]*b[k][j]

	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++) 
		{
			c[i][j] = 0;
			for (int l = 0; l < m; l++) 
			{
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}

}
