
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

void input(float a[], int n);
void output(float a[], int n);
float midl_val(float a[], int n);
float max(float a[], int n);
int num_max(float a[], int n);
float neg_el(float a[], int n);
int num_neg(float a[], int n);
void change_place(float a[], int n);
float min(float a[], int n);
int num_min(float a[], int n);
void D2_input(int** a, int n, int m);
void D2_output(int** a, int n, int m);

int main()
{
    //Variant 1
    cout << "Variant 1, Number 1 " << endl<<"Enter quantity of elements of array"<<endl;
	int n; float mid;
    cin >> n;
	float* a = new float[n];
    cout << "enter elements of array" << endl;
	input(a, n); cout << endl;
    //А)
    cout << "A)" <<endl<<"Midle value of arrays elements = "<< midl_val(a, n) <<endl;

	mid = midl_val(a, n);
	for (int i = 0; i < n; i++)
	{
		a[i] -= mid;
	}
	output(a, n);
	//B)
	cout<< endl << "B) Change place firs negative and max ellements of array: "<<endl;
	float fir_neg = neg_el(a,n);
	if (fir_neg == 0)
	{
		cout << "There is no negative ellements";
	}
	else
	{
		change_place(a, n);
		output(a, n);
	}
	//C)
	cout << endl << "C) Calculate midl value of array without min and max: " << endl;
	a[num_max(a, n)] = 0;
	a[num_min(a, n)] = 0;
	cout << midl_val(a, n) << endl;
	//number 2
	cout << endl << "Number 2" << endl;
	int m;
	cout << "enter quantity of columns ";
	cin >> n;
	cout << "enter quantity of strings ";
	cin >> m;
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[m];
	}
	D2_input(A, n, m);
	D2_output(A, n, m);
	int str = 0, charct = 0, i_charct = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j]>0 && (A[i][j]%2==0))
			{
				str += A[i][j];
			}

		}
		if (str > charct)
		{
			charct = str;
			i_charct = i+1;
		}
		str = 0;
	}
	if (charct == 0)
	{
		cout << endl << "There isn't any positiv and even ellement";
	}
	else
	{
		cout << "Max character: " << charct << endl << "In a raw: " << i_charct;
	}
}

void input(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}//Ввод с клавиатуры


void output(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}//Вывод массива

float midl_val(float a[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	sum = sum / n;
	return sum;
}//Ср.Знач суммы эл-тов массива

float max(float a[], int n)
{
	float max = a[0], n_max = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}// Max эл-т

int num_max(float a[], int n)
{
	int n_max = 0;
	float max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			n_max = i;
			max = a[i];
		}
	}
	return n_max;
}// Max эл-т номер

float neg_el(float a[], int n)
{
	float neg = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			neg = a[i];
			break;
		}
	}
	if (neg == 0)
	{
		return 0;
	}
	else
	{
		return neg;
	}
}//Первый отриц. эл-т

int num_neg(float a[], int n)
{
	int n_neg = -1;
	float neg = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			n_neg = i;
			neg = a[i];
			break;
		}
	}
	if (n_neg == -1)
	{
		return -1;
	}
	else
	{
		return n_neg;
	}
}//номер первого отриц. эл-та

void change_place(float a[], int n)
{
	int i_max, i_neg;
	float neg_ch, max_ch;
	i_max = num_max(a, n);
	i_neg = num_neg(a, n);
	max_ch = max(a, n);
	neg_ch = neg_el(a, n);
	a[i_max] = neg_ch;
	a[i_neg] = max_ch;

}//Изменение местами neg и max эл-тов массива

float min(float a[], int n)
{
	float min = a[0], n_min = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}//Мин эл-т массива

int num_min(float a[], int n)
{
	int n_min = 0;
	float min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			n_min = i;
			min = a[i];
		}
	}
	return n_min;
}//Номер min эл-та массива

void D2_input(int** a, int n, int m)
{
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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%5d", a[i][j]);
		}
		cout << endl;
	}
}//Вывод двумерного массива