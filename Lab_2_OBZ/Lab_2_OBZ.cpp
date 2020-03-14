// Lab_2_OBZ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include <fstream>
#include "iomanip"
#include <windows.h>

using namespace std;

void menu();
void D2_input(int** a, int n, int m);
void D2_output(int** a, int n, int m);
void outer_bound(int** a, int n, int m);
void input_space(int** a, int n, int m);
void space_output(int** a, int n, int m);
int scan(int** a, int j, int k);
int scan_for_dead(int** a, int n, int m);
void D2_input_for_sportsmen(int** a, int n, int m);
void D2_output_for_sportsmen(int** a, int n, int m);
int D2_max_for_sportsmen(int** a, int n, int m);
int quantity_of_max_shots(int** a, int b[], int n, int m, int max);
int array_max(int a[], int n);
void D2_rand_in_bounds(int** A, int n, int m, int a, int b);
int scan_for_positive(int** A, int n, int m);
int scan_for_negative(int** A, int n, int m);
void max_neg_inGreen(int** A, int n, int m, int& Remi, int& Remj);
void min_pos_inRed(int** A, int n, int m, int& Remi, int& Remj);

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
			cout << "Life Game" << endl; // 0 - живая клетка; X - мёртвая
			int cols, rows;
			do
			{
				cout << "Enter quantity of rows" << endl;
				cin >> rows;
				if (rows < 1)
				{
					cout << "quantity of rows should be bigger than 0." << endl;
				}
			} while (rows < 1);
			do
			{
				cout << "Enter quantity of colms" << endl;
				cin >> cols;
				if (cols < 1)
				{
					cout << "quantity of colmns should be bigger than 0." << endl;
				}
			} while (cols < 1);
			cols += 2; rows += 2;

			int** space = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				space[i] = new int[cols];
			}
			outer_bound(space, rows, cols);
			input_space(space, rows, cols);
			cout << "enter quantity of generations" << endl;
			int gen;
			cin >> gen;
			int** space_2 = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				space_2[i] = new int[cols];
			}
			outer_bound(space_2, rows, cols);
			cout << endl << "Zero generation" << endl << endl;
			space_output(space, rows, cols);
			cout << endl;
			if (scan_for_dead(space, rows, cols) == (rows - 2) * (cols - 2))
			{
				cout << "Zero generation is dead" << endl << endl;
				for (int i = 0; i < rows; i++)
				{
					delete space[i];
				}
				delete space;
				for (int i = 0; i < rows; i++)
				{
					delete space_2[i];
				}
				delete space_2;
				menu();
				break;
			}
			for (int i = 1; i <= gen; i++)
			{
				for (int j = 1; j < rows - 1; j++)
				{
					for (int k = 1; k < cols - 1; k++)
					{
						if (space[j][k] == 0)
						{
							if (scan(space, j, k) < 2)
							{
								space_2[j][k] = 1;
							}
							else if (scan(space, j, k) == 2 || scan(space, j, k) == 3)
							{
								space_2[j][k] = 0;
							}
							else if (scan(space, j, k) > 3)
							{
								space_2[j][k] = 1;
							}
						}
						else
						{
							if (scan(space, j, k) == 3)
							{
								space_2[j][k] = 0;
							}
							else
							{
								space_2[j][k] = 1;
							}
						}
					}
				}
				for (int j = 1; j < rows - 1; j++)
				{
					for (int k = 1; k < cols - 1; k++)
					{
						space[j][k] = space_2[j][k];
					}
				}
				cout << "Generation " << i << endl << endl;
				space_output(space, rows, cols);
				cout << endl << endl;
				if (scan_for_dead(space, rows, cols) == (rows - 2) * (cols - 2))
				{
					cout << "All cells are dead" << endl << endl;
					break;
				}
			}
			for (int i = 0; i < rows; i++)
			{
				delete space[i];
			}
			delete space;
			for (int i = 0; i < rows; i++)
			{
				delete space_2[i];
			}
			delete space_2;
			menu();
			break;
		}
		case 2:
		{
			cout << "Gaus method and SLAE" << endl;

			menu();
			break;
		}
		case 3:
		{
			cout << "Shooters" << endl;
			int n, m, max;
			do
			{
				cout << "Enter quantity of sportsmen" << endl;
				cin >> n;
				if (n <= 1)
				{
					cout << "quantity of sportsmen should be bigger than 1." << endl;
				}
			} while (n <= 1);
			do
			{
				cout << "Enter quantity of shoots" << endl;
				cin >> m;
				if (m < 1)
				{
					cout << "quantity of shoots should be bigger than 0." << endl;
				}
			} while (m < 1);
			m++;
			int** table = new int* [n];
			for (int i = 0; i < n; i++)
			{
				table[i] = new int[m];
			}
			D2_input_for_sportsmen(table, n, m);
			cout << "RESULTS: " << endl << endl;
			D2_output_for_sportsmen(table, n, m);
			max = D2_max_for_sportsmen(table, n, m);
			int* quant = new int[n];
			int q = quantity_of_max_shots(table, quant, n, m, max);
			if (q > 1)
			{
				int* gen_score = new int[q];
				int score = 0;
				for (int i = 0; i < q; i++)
				{
					for (int j = 1; j < m; j++)
					{
						score += table[quant[i]][j];
					}
					gen_score[i] = score;
					cout << "Sportsman #" << quant[i] + 1 << " general score: " << gen_score[i] << endl;
					score = 0;
				}
				max = array_max(gen_score, q);
				int num_of_win = 0;
				int* winners = new int[q];
				int l = 0;
				for (int i = 0; i < q; i++)
				{
					if (gen_score[i] == max)
					{
						winners[l] = quant[i];
						num_of_win++;
						l++;
					}
				}
				if (num_of_win == 1)
				{
					cout << "Winner is shooter " << winners[0] + 1 << endl;
				}
				else
				{
					cout << "Winners are shooters: " << endl;
					for (int i = 0; i < num_of_win; i++)
					{
						cout << winners[i] + 1 << ", ";
					}
					cout << endl;
				}
				delete[] winners;
				delete[] gen_score;

			}
			else
			{
				cout << "Max score: " << max << endl << "Winner: shooter #" << quant[0] + 1 << endl;

			}
			for (int i = 0; i < n; i++)
			{
				delete table[i];
			}
			delete table;
			delete[] quant;

			cout << endl;
			menu();
			break;
		}
		case 4:
		{
			cout << "Variant 4. Number 1" << endl;
			int n, m, a, b;
			do
			{
				cout << "Enter size of matrix (square and bigger than 2)" << endl;
				cin >> n;
				if (n < 3)
				{
					cout << "size should be bigger than 2." << endl;
				}
			} while (n < 3);
			m = n;
			cout << "Enter left bound a" << endl;
			cin >> a;
			cout << "Enter right bound b (bigger than a)" << endl;
			cin >> b;
			if (b <= a)
			{
				do
				{
					cout << "right bound should be bigger than left. Enter it again" << endl;
					cin >> b;
				} while (b <= a);
			}
			int S = 0;
			int** A = new int* [n];
			for (int i = 0; i < n; i++)
			{
				A[i] = new int[m];
			}
			D2_rand_in_bounds(A, n, m, a, b);
			D2_output(A, n, m);
			if (scan_for_positive(A, n, m) == 0)
			{
				if (scan_for_negative(A, n, m) == 0)
				{
					cout << "There isn't any positive ellements in Red zone and any negative in Green zone" << endl;
				}
				else
				{
					cout << "There isn't any positive ellements in Red zone" << endl;
				}	
				for (int i = 0; i < n; i++)
				{
					delete A[i];
				}
				delete A;
				cout << endl;
				menu();
				break;
			}
			if (scan_for_negative(A, n, m) == 0)
			{
				cout << "There isn't any negative ellements in Green zone" << endl;
				for (int i = 0; i < n; i++)
				{
					delete A[i];
				}
				delete A;
				cout << endl;
				menu();
				break;
			}
			int RemiGr, RemjGr, RemiRed, RemjRed, temp;
			max_neg_inGreen(A, n, m, RemiGr, RemjGr);
			min_pos_inRed(A, n, m, RemiRed, RemjRed);
			cout << RemiGr << " " << RemjGr << endl << RemiRed << " " << RemjRed << endl;
			temp = A[RemiGr][RemjGr];
			A[RemiGr][RemjGr] = A[RemiRed][RemjRed];
			A[RemiRed][RemjRed] = temp;
			cout << "Matrix with reversed ellements" << endl;
			D2_output(A, n, m);
			for (int i = 0; i < n; i++)
			{
				delete A[i];
			}
			delete A;
			cout << endl;
			menu();
			break;
		}
		case 5:
		{
			cout << "Variant 4. Number 2" << endl;
			menu();
			break;
		}
		case 0:
			return 0;
		}

	}
	return 0;
}

void menu()
{
	cout << "MENU" << endl << endl << "Choose number: " << endl << "1. Life Game " << endl << "2.Gaus method and SLAE " << endl << "3. Shooters" << endl << "4. " << endl << "5. " << endl << "0. Exit" << endl;
}

void D2_input(int** a, int n, int m)
{
	/*
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 20 - 4;
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

void outer_bound(int** a, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		a[0][i] = 2;
	}
	for (int i = 1; i < n; i++)
	{
		a[i][0] = 2;
	}
	for (int i = 1; i < m; i++)
	{
		a[n - 1][i] = 2;
	}
	for (int i = 1; i < n - 1; i++)
	{
		a[i][m - 1] = 2;
	}
}//Заполнение внешнего "ободка" 2-ками

void input_space(int** a, int n, int m)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			a[i][j] = rand() % 2;
		}
	}
}//Ввод клеток

void space_output(int** a, int n, int m)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (a[i][j] == 1)
			{
				cout << setw(3) << "X";
			}
			else
			{
				cout << setw(3) << "0";
			}
		}
		cout << endl;
	}
}//Вывод клеточного пространства

int scan(int** a, int j, int k)
{
	int live = 0;
	for (int i = k - 1; i <= k + 1; i++)
	{
		if (a[j - 1][i] == 0)
		{
			live++;
		}
	}
	for (int i = k - 1; i <= k + 1; i++)
	{
		if (a[j + 1][i] == 0)
		{
			live++;
		}
	}
	if (a[j][k - 1] == 0)
	{
		live++;
	}
	if (a[j][k + 1] == 0)
	{
		live++;
	}
	return live;
}//считатет количество ждивых клеток вокруг

int scan_for_dead(int** a, int n, int m)
{
	int dead = 0;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (a[i][j] == 1)
			{
				dead++;
			}
		}
	}
	return dead;
}//Проверка, если все клетки умерли

void D2_input_for_sportsmen(int** a, int n, int m)
{
	/*
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				a[i][j] = i + 1;
			}
			else
			{
				a[i][j] = rand() % 11;
			}
		}
	}
}

void D2_output_for_sportsmen(int** a, int n, int m)
{
	/*
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				printf("shooter %2i:|", a[i][j]);
			}
			else
			{
				printf("%2d|", a[i][j]);
			}
		}
		cout << endl;
	}
}//Вывод таблицы с результатами

int D2_max_for_sportsmen(int** a, int n, int m)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (a[i][j] >= max)
			{
				max = a[i][j];
			}
		}
	}
	return max;
}//Максимальный эллемент в таблице спортсменов

int quantity_of_max_shots(int** a, int b[], int n, int m, int max)
{
	int k = 0;
	int quant = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (a[i][j] == max)
			{
				quant++;
				b[k] = i;
				k++;
				break;
			}
		}
	}
	return quant;
}

int array_max(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void D2_rand_in_bounds(int** A, int n, int m, int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = rand() % (b - a + 1) + a;
		}
	}
}//Cлучайное число в заданном диапозоне записывается в 2D массив

int scan_for_positive(int** A, int n, int m)
{
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j > n - i - 1) && (j > i))
			{
				if (A[i][j] > 0)
				{
					pos++;
				}
			}
		}
	}

	return pos;
}//Сканирование на наличие положительных эл-тов в "красной" области

int scan_for_negative(int** A, int n, int m)
{
	int neg = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j < n - i - 1) && (j > i))
			{
				if (A[i][j] < 0)
				{
					neg++;
				}
			}
		}
	}
	return neg;
}

void max_neg_inGreen(int** A, int n, int m, int& Remi, int& Remj)
{
	int max_neg = -10000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j < n - i - 1) && (j > i))
			{
				if (A[i][j] < 0 && A[i][j] >= max_neg)
				{
					Remi = i;
					Remj = j;
					max_neg = A[i][j];
				}
			}
		}
	}
}

void min_pos_inRed(int** A, int n, int m, int& Remi, int& Remj)
{
	int min_pos = 10000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j > n - i - 1) && (j > i))
			{
				if (A[i][j] > 0 && A[i][j] <= min_pos)
				{
					Remi = i;
					Remj = j;
					min_pos = A[i][j];
				}
			}
		}
	}
}