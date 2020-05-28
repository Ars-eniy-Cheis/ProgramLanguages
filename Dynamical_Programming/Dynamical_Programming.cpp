#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void menu();
long long int fib(long long int n, long long int cache[]);
void fib_dynamic(long long int n, long long int Fib[]);
void output(long long int a[], int n);
int trajectories(int n, int K[]);

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
			cout << "Enter the number of fibonacci numbers you want to calculate (From 0 to n include)" << endl;
			int n;
			cin >> n;
			long long int* cache = new long long int[n+2];
			for (int i = 0; i <= n+1; i++)
			{
				cache[i] = 0;
			}
			for (long long int i = 0; i <= n; i++)
			{
				cout << "fib " << i << " = " << fib(i, cache) << endl;
			}
			menu();
			break;
		}

		case 2:
		{
			cout << "Enter the number of fibonacci numbers you want to calculate (From 0 to n include)" << endl;
			int n;
			cin >> n;
			long long int* Fib = new long long int[n + 1];
			fib_dynamic(n, Fib);
			output(Fib, n);

			menu();
			break;
		}

		case 3:
		{
			cout << "Enter number of cities" << endl;
			int n;
			cin >> n;
			int* K = new  int[n + 1];
			cout << "Cricket has " << trajectories(n, K) << " trajectories from city 1 to city " << n << endl;
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
	cout << "MENU" << endl << endl << "Choose number: " << endl << "1. Fibonacci numbers (recurcion with cache)" << endl << "2. Fibonacci numbers (fully dynamic)" << endl << "3. Number of cricket trajectorys" << endl  << "0. Exit" << endl;
}

long long int fib(long long int n, long long int cache[])
{
	if (n <= 1) return n;
	if (cache[n] == 0)
	{
		cache[n] = fib(n - 1, cache) + fib(n - 2, cache);
	}
	return cache[n];
}

void fib_dynamic(long long int n, long long int Fib[])
{
	Fib[0] = 0;
	Fib[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}

}

void output(long long int a[], int n)
{
	for (int i = 0; i < n +1 ; i++)
	{
		cout << "Fib " << i << " = " << a[i] << endl;
	}
}

int trajectories(int n, int K[])
{
	K[0] = 0;
	K[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		K[i] = K[i - 1] + K[i - 2];
	}
	return K[n];
}// Ничем не отличается от функции вычисления числа Фибоначчи.