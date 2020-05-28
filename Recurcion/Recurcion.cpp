
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void menu();
int factorial_rec(int n, int &d, int &p);
int factorial(int n, int& d, int& p);
int F(int n);
bool is2pow(int num);
int Max(int a[], int n);
void input(int a[], int n);
void output(int a[], int n);
int digits(int n);
int F_2(int n);
int G(int n);

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
			int fac, d1 = 0, p1 = 0, d2 = 0, p2 = 0;
			cout << "Factorial (with recurcion and without)"<< endl << "Enter number" <<endl;
			cin >> fac; 
			factorial_rec(fac, d1, p1);
			factorial(fac, d2, p2);
			cout << "Recurcion" << endl << fac << "! = " << factorial_rec(fac, d1, p1) << " Memory: " << p1 << " Actions: " << d1 << endl;
			cout << "Not recurcion" << endl << fac << "! = " << factorial(fac, d2, p2) << " Memory: " << p2 << " Actions: " << d2 << endl;
			menu();
			break;
		}

		case 2:
		{
			int N;
			cout << "Function: F(n) = F(n-1) * (n-1) | F(1) = 3" << endl << "enter n" << endl;
			cin >> N;
			cout << F(N) << endl;
			menu();
			break;
		}

		case 3:
		{
			int p2w;
			cout << "Enter number" << endl;
			cin >> p2w;
			if (is2pow(p2w) == 1)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
			menu();
			break;
		}

		case 4:
		{
			int n;
			cout << "Enter size of array" << endl;
			cin >> n;
			int* a = new int[n];
			input(a, n);
			cout << "Array: " << endl;
			output(a, n);
			cout << "Max in array: " << endl << Max(a, n) << endl;
			menu();
			break;
		}

		case 5:
		{
			int n;
			cout << "Enter number" << endl;
			cin >> n;
			cout << "Number of digits = " << digits(n) << endl;
			menu();
			break;
		}

		case 6:
		{
			int num_f, num_g;
			cout << "Enter number from Function F(n) = F(n - 1) - 2 * G(n - 1) | F(1) = 4" << endl;
			cin >> num_f;
			cout << "Enter number from Function G(n) = F(n - 1) - G(n - 1) | G(1) = -2" << endl;
			cin >> num_g;
			cout << "F(" << num_f << ") = " << F_2(num_f) << endl;
			cout << "G(" << num_g << ") = " << G(num_g) << endl;
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
	cout << "MENU" << endl << endl << "Choose number: " << endl << "1. Factorial" << endl << "2. Function F(n)" << endl << "3. Pow of 2" << endl << "4. Variant 4 N1" << endl << "5. Variant 4 N2" << endl << "6. Variant 4 N3" << endl << "0. Exit" << endl;
}

int factorial_rec(int n, int& d, int& p)
{
	/* На вход получаем целочисленое число n - число до которого нам нужно вычислять факториал.
	Ф-ия рекурсивно запрашивает себя до f(0), при котором она возвращает 0.
	В конечном счёте ф-ия возвращает факториал заданного числа n.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	// d - действие (сравнение ,присвоение, умножение и т.д.); p - кол-во затраченной памяти.
	p++;//Создаётся локальная переменная n.
	d++;//Сравнение n
	if (n == 0) return 1;
	d++;//Умножение n
	return n * factorial_rec(n - 1, d, p);
}

int factorial(int n, int& d, int& p)
{
	/* на вход получаем целочисленое число n - число до которого нам нужно вычислять факториал.
	Факториал вычисляется в цикле до заданного n.
	Возвращается переменная f - факториал числа n.
	*/
	// d - действие (сравнение ,присвоение, умножение и т.д.); p - кол-во затраченной памяти.
	p++;//Создаётся локальная переменная n.
	int f = 1;
	d+=2;//Присвоение f = 1 и i = 1
	p+=2;//Создание переменной f и i
	for (int i = 1; i <= n; i++)
	{
		d+=4;//Сравнение i с n, увелечение i на 1, присвоение f = f * i, умножение f * i
		f = f * i;
	}
	return f;
}

int F(int n)
{
	/* На вход получаем целочисленное значение n - число, от которого запрашивается ф-ия.
	Ф-ия рекурсивно запрашивает сама себя до f(1), при котором она возвращает 3.
	В конечном счёте ф-ия возвращает значание ф-ии от заданного числа n.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	if (n == 1) return 3;
	return F(n - 1) * (n - 1);
}

bool is2pow(int num) 
{
	/*На вход получаем целочисленное значение num - предполагаемую степень двойки.
	Если число нечётное, то сразу возвращается 0 - т.е. "NO".
	Если число чётное, то ф-ия рекурсивно запрашивает себя до тех пор, пока num не станет равно 2 (или другому неподходящему значению).
	При num = 2, ф-ия возвращает 1, что значит "YES" в основной программе.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	if (num % 2 == 1) return 0;
	else
	{
		if (num == 2) return 1;
		else return is2pow(num / 2);
	}

}

int Max(int a[], int n)
{
	/*На вход получаем массив a[] из целочисленных эл-тов и n - кол-во эл-тов массивов.
	Если кол-во эл-тов массива становится равным 1 (или равно 1 изначально), ф-ия возвращает первый эл-т массива.
	Далее идёт проверка: Больше ли последущий эл-т чем предыдущий. Если да, то ф-ия возвращает его, если нет, то возвращается текущее значение максимума.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	int max;
	if (n == 1) 
	{
		return a[0];
	}
	else 
	{
		max = Max(a, n - 1);
		if (a[n - 1] > max)
		{
			return a[n - 1];
		}
		return max;
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}//Вывод массива

void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%20-10;
	}
}//Случайный ввод массива

int digits(int n)
{
	/*На вход получаем целочисленное значение n - введённое число.
	Если число равно 0, возвращаем 0, в другом случае рекурсивно запршиваем ф-ию и вместе с этим считаем кол-во разрядов в числе.
	В конечном счёте возвращается кол-во цифр в числе.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	if (n == 0) return 0;
	return digits(n / 10) + 1;
}

int F_2(int n)
{
	/* На вход получаем целочисленное значение n - число, от которого запрашивается ф-ия.
	Ф-ия рекурсивно запрашивает сама себя и другую ф-ию: G до f(1), при котором она возвращает 4.
	В конечном счёте ф-ия возвращает значание ф-ии от заданного числа n.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	if (n == 1) return 4;
	return F_2(n - 1) - 2 * G(n - 1); //F(2) = 4 - 2*(-2) = 8
}

int G(int n)
{
	/* На вход получаем целочисленное значение n - число, от которого запрашивается ф-ия.
	Ф-ия рекурсивно запрашивает сама себя и другую ф-ию: F до G(1), при котором она возвращает -2.
	В конечном счёте ф-ия возвращает значание ф-ии от заданного числа n.
	Прямой и обратный ходы будут подробно описаны в отчёте.
	*/
	if (n == 1) return -2;
	return F_2(n - 1) - G(n - 1); //G(2) = 4 +2 = 6
}