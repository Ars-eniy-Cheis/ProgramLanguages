#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void menu();
void frm_lft_to_rght(int N, int digit);
void Tr_seq(int n, int counter, int &counter_n);
int units_n_zeros(int a, int b);
void maximumu(int &max, int &quant, int &counter);

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
			cout << "Print all digits of number one by one, in the usual order, separating them with spaces or new lines. Enter the number" << endl;
			int n;
			cin >> n;
			frm_lft_to_rght(n, 10);

			menu();
			break;
		}
		case 2:
		{


			menu();
			break;
		}
		case 3:
		{
			cout << "A monotone sequence is given in which each natural number k occurs exactly k times: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, ... Given a natural integer n, print the first n members of this sequence" << endl;
			cout << "enter n" << endl;
			int n, counter_n;
			cin >> n;
			counter_n = n;
			for (int i = 1; i <= n; i++)
			{
				Tr_seq(i, i, counter_n);
			}

			menu();
			break;
		}
		case 4:
		{
			cout << "The numbers a and b are given. Determine how many sequences of a zeros and b units exist in which no two zeros stand side by side." << endl;
			int a, b;
			cout << "Enter quantity of zeroes" << endl;
			cin >> a;
			cout << "Enter quantity of units" << endl;
			cin >> b;
			cout << "There are " << units_n_zeros(a, b) << " sequnces " << endl;

			menu();
			break;
		}
		case 5:
		{
			cout << "Given a sequence of natural numbers (one number per line), ending with the number 0. Determine how many elements of this sequence are equal to its largest element. It is guaranteed that the sequence contains at least one number (except zero)." << endl;
			int n, max = 0, quant = 0;
			do
			{
				cout << "enter quantity of elements (more than zero)" << endl;
				cin >> n;
			} while (n < 1);

			maximumu(max, quant, n);
			cout << "Number of maximums: " << quant << endl;
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
	//Ф-ия вывода Меню.
	cout << endl << "MENU" << endl << endl << "Choose number: " << endl << "1. Numbers from left to right" << endl << "2. " << endl << "3. Triangular sequence" << endl << "4. Without 2 zeroes" << endl << "5. Quantity of maximums" << endl  << "0. Exit" << endl;
}

void frm_lft_to_rght(int n, int digit)
{
	/* На вход получаем целочисленные переменные n - число, которое нам нужно разбить на разряды и digit - которое будет подсчитывать кол-во разрядов в числе.
	В функции присутствует две рекурсии. Первая считает кол-во разрядов в числе путём умножения переменной digit на 10 до тех пор, пока n / digit не станет равно 0 (Т.е. кол-во разрядов в digit не станет на один больше чем в n).
	Вторая рекурсия - само выведение числа цифр числа. Работает следущим образом: На экран будет выводиться n/digit до тех пор, пока счётчик разрядов не станет равным еденице.
	На каждом шаге счётчик разрядов digit и исходное число n уменьшаются.
	Ф-ия ничего не возвращает, т.к. она типа void.
	Хоть ф-ия и рекурсивна, она не имеет обратного хода, т.к. не нуждается в нём.
	*/
	if ((n / digit) != 0)
	{
		frm_lft_to_rght(n, (digit * 10));
	}
	else 
	{
		digit /= 10;
		cout << (n / digit) << " ";
		n %= digit;
		if (digit != 1)
		{
			frm_lft_to_rght(n, digit);
		}
	}
}

void Tr_seq(int n, int counter, int &counter_n)
{
	/* На вход получаем целочисленные переменные n - выводимое число последовательности и counter - счётчик того, сколько раз нужно вывести это число, а также по ссылке передаём переменную counter_n. , отвечающую за обшее кол-во членов последовательности.
	Ф-ия будет выводить числа треугольной посл-ности до тех пор, пока счётчик counter_n не станет равным нулю. 
	Также за то, какое число нужно выводить в данный момент отвечает переменная counter, которая задаётся циклом в main.
	Ф-ия ничего не возвращает, т.к. она типа void.
	Хоть ф-ия и рекурсивна, она не имеет обратного хода, т.к. не нуждается в нём.
	*/
	if (counter_n != 0)
	{
		if (counter != 0)
		{
			cout << n << " ";
			counter_n--;
			Tr_seq(n, counter - 1, counter_n);
		}
	}
}

int units_n_zeros(int a, int b)// a - ноль; b - еденица
{
	/*На вход получам две целочисленные переменные a - кол-во нулей и b - кол-во едениц.
	Сперва идёт проверка условий. Если ни одно из них не выполняется, то возвращается сумма нашей ф-ии от a-1 и b-1 и этой же ф-ии от a и b-1.
	Подробнее прямой и обратный ходы будут описаны в отчёте.
	В конечном счёте ф-ия возвращает число, соответствующее максимальному числу последовательностей, где два 0 не стоят рядом.
	*/
	if (a == 0)
		return 1;
	else if (a == 1)
		return b + 1;
	else if (a > 1 && b == 0)
		return 0;
	else
	{
		return units_n_zeros(a - 1, b - 1) + units_n_zeros(a, b - 1);
	}
}

void maximumu(int& max, int& quant, int& counter)
{
	/* На вход получаем три целочисленные переменные, передаваеммые по ссылке. max отвечает за текущий Максимум в последовательности. quant за количество максимумов и counter за кол-во чисел в последовательности.
	Ф-ия будет выполняться до тех пор, пока не закончится кол-во чисел в последовательности.
	По условию задачи мы не можем иметь массива и вводимые числа нигде не должны храниться. Поэтому число вводится каждый раз, когда запрашивается ф-ия.
	В ф-ии присутствует три условия в зависимости от которых будет либо меняться максимум и следовательно их количество становится равным 1, либо увеличиваться кол-во максимумов, либо ничего из вышеперечисленного.
	В кажом условии стоит счётчик counter, который уменьшается не зависимо от того, какое условие подтвердилось.
	Ф-ия не имеет обратного хода, т.к. не нуждается в нём, а также ничекго не возвращает, т.к. имеет тип void и все нужные переменные передаются по ссылке.
	*/
	if (counter != 0)
	{
		int num;
		cout << "enter number" << endl;
		cin >> num;
		if (num > max)
		{
			counter--;
			return maximumu(max = num, quant = 1, counter);
		}
		else if (num == max)
		{
			quant++;
			counter--;
			return maximumu(max, quant, counter);
		}
		else if (num < 0 && max == 0)
		{
			counter--;
			return maximumu(max, quant = 1, counter);
		}
		else
		{
			counter--;
			return maximumu(max, quant, counter);
		}
	}
}