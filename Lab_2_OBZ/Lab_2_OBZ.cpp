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
void trans_sqr(int** a, int n);
void trans_any(int** a, int** b, int n, int m);
void matrix_sum(int** a, int** b, int** c, int n, int m);
void matrix_mult(int** a, int** b, int** c, int n, int m, int k);
void mult_of_num_and_matrix(int** a, int n, int m, int alpha);
void D2_output_Double(double** a, int n, int m);
void output(double a[], int n);
void Gaus_method(double** a, double* b, double* x, int n);
void Gaus_method_output(double* x, double** a, int n);

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
			cout << "Gaus method and SLAE" << endl << "1. Handle input" << endl << "2. Ready input" << endl << "0. Exit" << endl;
			int chos = 1;
			while (chos != 0)
			{
				cin >> chos;
				switch (chos)
				{
				case 1:
				{
					int n;
					cout << "Handle input" << endl;
					cout << "Order: " << endl;
					cin >> n;
					double** a = new double* [n];
					for (int i = 0; i < n; i++)
					{
						a[i] = new double[n];
					}
					double* b = new double[n];
					double* x = new double[n];
					cout << "Enter coefficients and free term: " << endl;
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < n; j++)
						{
							cout << "a[" << i+1 << "," << j+1 << "]= ";
							cin >> a[i][j];
						}
						cout << "b[" << i+1 << "]= ";
						cin >> b[i];
					}
					D2_output_Double(a, n, n);
					output(b, n); cout << endl;
					Gaus_method(a, b, x, n);
					cout << "1. Handle input" << endl << "2. Ready input" << endl << "0. Exit" << endl;
					break;
				}
				case 2:
				{
					cout << "Ready input" << endl;
					double* x_sol = new double[3];
					ifstream UsualMAT, UsualMAT_B, NoSolMat, NoSolMat_B, GilMat, GilMat_B;
					int MAT = 1;
					while (MAT != 0)
					{
						cout << "Chose MAtrix: " << endl << "1. Usual Matrix" << endl << "2. No solution Matrix" << endl << "3. Gilbert MAtrix" << endl << "0. Exit" << endl;
						cin >> MAT;
						switch (MAT)
						{
						case 1:
						{
							double* Usual_B = new double[3];
							double** Usual = new double* [3];
							for (int i = 0; i < 3; i++)
							{
								Usual[i] = new double[3];
							}

							UsualMAT.open("UsualMAT.txt");
							while (!UsualMAT.eof())
							{
								for (int i = 0; i < 3; i++)
								{
									for (int j = 0; j < 3; j++)
									{
										UsualMAT >> Usual[i][j];
									}
								}
							}
							UsualMAT.close();
							UsualMAT_B.open("UsualMAT_Ans.txt");
							while (!UsualMAT_B.eof())
							{
								for (int i = 0; i < 3; i++)
								{
									UsualMAT_B >> Usual_B[i];
								}
							}
							UsualMAT_B.close();
							D2_output_Double(Usual, 3, 3);
							output(Usual_B, 3); cout << endl;
							Gaus_method(Usual, Usual_B, x_sol, 3);
							break;
						}
						case 2:
						{
							double* UnUsual_B = new double[3];
							double** UnUsual = new double* [3];
							for (int i = 0; i < 3; i++)
							{
								UnUsual[i] = new double[3];
							}

							NoSolMat.open("NOsol.txt");
							while (!NoSolMat.eof())
							{
								for (int i = 0; i < 3; i++)
								{
									for (int j = 0; j < 3; j++)
									{
										NoSolMat >> UnUsual[i][j];
									}
								}
							}
							NoSolMat.close();
							NoSolMat_B.open("NOsol_B.txt");
							while (!NoSolMat_B.eof())
							{
								for (int i = 0; i < 3; i++)
								{
									NoSolMat_B >> UnUsual_B[i];
								}
							}
							NoSolMat_B.close();
							D2_output_Double(UnUsual, 3, 3);
							output(UnUsual_B, 3); cout << endl;
							Gaus_method(UnUsual, UnUsual_B, x_sol, 3);
							break;
						}
						case 3:
						{
							double* Gilbert_B = new double[3];
							double** Gilbert = new double* [3];
							for (int i = 0; i < 3; i++)
							{
								Gilbert[i] = new double[3];
							}
							GilMat.open("Gilbert.txt");
							while (!GilMat.eof())
							{
								for (int i = 0; i < 3; i++)
								{
									for (int j = 0; j < 3; j++)
									{
										GilMat >> Gilbert[i][j];
									}
								}
							}
							GilMat.close();
							GilMat_B.open("Gibert_B.txt");
							while (!GilMat_B.eof())
							{
								for (int i = 0; i < 3; i++)
								{
									GilMat_B >> Gilbert_B[i];
								}
							}
							GilMat_B.close();
							D2_output_Double(Gilbert, 3, 3);
							output(Gilbert_B, 3); cout << endl;
							Gaus_method(Gilbert, Gilbert_B, x_sol, 3);
							break;
						}
						case 0:
						{
							cout<< "1. Handle input" << endl << "2. Ready input" << endl << "0. Exit" << endl;
						}
						}
					}	
					break;
				}
				case 0:
				{
					cout << endl;
					menu();
				}
				}
			}
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
			cout << "Coordinates of biggest negative ellemnt: " <<RemiGr << " " << RemjGr << endl<< "Coordinates of lowest positive ellemnt: " << RemiRed << " " << RemjRed << endl;
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
			cout << "Variant 4. Number 2" << endl<<"Do A x C(t) + 2 x B x D(t)";
			int m = 4, n = 3;
			int** A = new int* [m];
			int** C = new int* [m];
			int** CTrans = new int* [n];
			int** AxC = new int* [m];
			for (int i = 0; i < m; i++)
			{
				C[i] = new int[n];
				A[i] = new int[n];
			}
			for (int i = 0; i < n; i++)
			{
				CTrans[i] = new int[m];
			}
			for (int i = 0; i < m; i++)
			{
				AxC[i] = new int[m];
			}
			int** B = new int* [m];
			int** D = new int* [m];
			int** DTrans = new int* [1];
			int** BxD = new int* [m];
			for (int i = 0; i < m; i++)
			{
				B[i] = new int[1];
				D[i] = new int[1];
			}
			for (int i = 0; i < 1; i++)
			{
				DTrans[i] = new int[m];
			}
			for (int i = 0; i < m; i++)
			{
				BxD[i] = new int[m];
			}
			ifstream fMatA, fMatC, fVecB, fVecD;
			fMatA.open("MatrixA.txt");
			while (!fMatA.eof())
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						fMatA >> A[i][j];
					}
				}
			}
			fMatA.close();
			cout << "Matrix A" << endl;
			D2_output(A, m, n);
			fMatC.open("MatrixC.txt");
			while (!fMatC.eof())
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						fMatC >> C[i][j];
					}
				}
			}
			cout << "Matrix C" << endl;
			fMatA.close();
			D2_output(C, m, n);
			trans_any(C, CTrans, m, n);
			cout << "Transpotted C" << endl;
			D2_output(CTrans, n, m);
			for (int i = 0; i < m; i++)
			{
				delete C[i];
			}
			delete C;
			cout << "Multiplication of A and C(t)" << endl;
			matrix_mult(A, CTrans, AxC, m, n, m);
			D2_output(AxC, m, m);
			for (int i = 0; i < m; i++)
			{
				delete A[i];
			}
			delete A;
			for (int i = 0; i < n; i++)
			{
				delete CTrans[i];
			}
			delete CTrans;
			fVecB.open("VectorB.txt");
			while (!fVecB.eof())
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < 1; j++)
					{
						fVecB >> B[i][j];
					}
				}
			}
			fVecB.close();
			fVecD.open("VectorD.txt");
			while (!fVecD.eof())
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < 1; j++)
					{
						fVecD >> D[i][j];
					}
				}
			}
			fVecD.close();
			cout << "Vector B" << endl;
			D2_output(B, m, 1);
			cout << "Vector D" << endl;
			D2_output(D, m, 1);
			cout << "2*B" << endl;
			mult_of_num_and_matrix(B, m, 1, 2);
			D2_output(B, m, 1);
			trans_any(D, DTrans, m, 1);
			cout << "Transpotted D" << endl;
			D2_output(DTrans, 1, m);
			for (int i = 0; i < m; i++)
			{
				delete D[i];
			}
			delete D;
			cout << "Multiplication of 2*B and D(t)" << endl;
			matrix_mult(B, DTrans, BxD, m, 1, m);
			D2_output(BxD, m, m);

			for (int i = 0; i < m; i++)
			{
				delete B[i];
			}
			delete B;
			for (int i = 0; i < 1; i++)
			{
				delete DTrans[i];
			}
			delete DTrans;
			cout << "A x C(t) + 2 x B x D(t)" << endl;
			int** ACplBD = new int* [m];
			for (int i = 0; i < m; i++)
			{
				ACplBD[i] = new int[m];
			}
			matrix_sum(AxC, BxD, ACplBD, m, m);
			D2_output(ACplBD, m, m);
			for (int i = 0; i < m; i++)
			{
				delete AxC[i];
				delete BxD[i];
				delete ACplBD[i];
			}
			delete AxC;
			delete BxD;
			delete ACplBD;
			cout << endl;
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
	/*
	Ф-ция для вывода меню, чтобы не занимать лишнее место в программе. Выводит пункты меню.
	*/
	cout << "MENU" << endl << endl << "Choose number: " << endl << "1. Life Game " << endl << "2.Gaus method and SLAE " << endl << "3. Shooters" << endl << "4. Varint 4 #1" << endl << "5. Varint 4 #2" << endl << "0. Exit" << endl;
}

void D2_input(int** a, int n, int m)
{
	/*
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция заполняет его случайными эл-тами от -4 до 16
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
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция форматировано выводит двумерный массив с пробелмами между эл-тами в 5 символов
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
	/*
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция заполняет "Внешние ободки" массива 2-ками для задания "Игра Жизнь"
	*/
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
	/*
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция заполняет массив с "клетками" (без внешних ободков). 0 - живая клетка, 1 - мёртвая.  
	*/
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
	/*
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция выводит на экран массив с "клетками" (без внешних ободков). Если клетка жива, то выводится 0, если метрва - Х
	*/
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
	/*
	На вход получаем двумерный масиив int** a, номер строки int j и номер столбца int k. Тем самым определяем на каком эл-те останаволись программа.
	Функция "сканирует" все эллементы вокруг текущего и вычисляет количество "живых клеток".
	Возвращает int live - количество "живых клеток".
	*/
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
}//считатет количество живых клеток вокруг

int scan_for_dead(int** a, int n, int m)
{
	/*
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция считает количество "мёртвых клеток" в массиве.
	Возвращает int dead - количество "мёртвых клеток"
	*/
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
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Сперва функция проверяет, не находится ли она в первом столбце. Если да, то она записывает  номер спортсмена  в соотвествии с тем, в какой строке он находится + 1(т.к. отсчёт идёт с нулевой строки)
	Если нет, то функция заполняет остальной массив случайными числами от 0 до 10 - "выстрелами" спортсменов
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
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Сперва функция проверяет, не находится ли она в первом столбце. Если да, то она выводит "Shooter №стрелка и | для создания образа таблицы"
	если нет, то функция выводит остальной массив с "выстрелами" спортсменов, ставя между ними | для создания таблицы.
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
	/*
	На вход получаем двумерный масиив int** a, и его размерности int n, int m.
	Функция вычисляет самый точный "выстрел" среди всех спортсменов. 
	Возвращает int max - максимальное число в таблице спортсменов (не считая номер самих спортсменов)
	*/
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
	/*
	На вход получаем двумерный масиив int** a, одномерный массив int b[], размерности int** a: int n, int m. И int max
	Функция считает количество самых точных выстрелов и записывает в масиив int b[] номер спортсмена, еоторый его сделал
	Возвращает int quant - количество спортсменов с самыми точными выстрелами.
	*/
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
	/*
	На вход получаем одномерный масиив int a[], и его размерность int n
	Функция вычисляет максимальный эллемент в массиве
	Возвращает int max - самый большой эл-т массива
	*/
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
	/*
	На вход получаем двумерный масиив int** A, его размерности int n, int m. Левую границу заданной области int a и правую границу int b
	Функция заполняет двумерный массив int** A в заданном диапозоне [a,b]
	*/
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
	/*
	На вход получаем двумерный масиив int** A, его размерности int n, int m. 
	Функция сканирует область выше главной диагонали и ниже побочной на наличие положительных эл-тов
	Возвращает int pos - количество положительных эл-тов в вышеописанной области.
	*/
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
	/*
	На вход получаем двумерный масиив int** A, его размерности int n, int m.
	Функция сканирует область выше главной диагонали и выше побочной на наличие отрицательных эл-тов
	Возвращает int neg - количество отрицательных эл-тов в вышеописанной области.
	*/
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
	/*
	На вход получаем двумерный масиив int** A, его размерности int n, int m и переданные по ссылке int& Remi и int& Remj  - которые запоминают номер эл-та в двумерном массиве.
	Функция ищет максимальный отрицательный э-т в облвсти выше главной диагонали и выше побочной
	Передаёт по ссылке номер максимального отрицательно эл-та в двумерном массиве 
	*/
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
	/*
	На вход получаем двумерный масиив int** A, его размерности int n, int m и переданные по ссылке int& Remi и int& Remj  - которые запоминают номер эл-та в двумерном массиве.
	Функция ищет минимальный положительный э-т в области выше главной диагонали и ниже побочной
	Передаёт по ссылке номер минимального положительного эл-та в двумерном массиве
	*/
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

void matrix_sum(int** a, int** b, int** c, int n, int m)
{
	/*
	На вход получаем двумерные массивы int** a, int** b, int** c и их размерности int n, int m
	В матрицу int** c записывается сумма матриц int** a и int** b
	Считаем по правилу: c[i][j] = a[i][j]+b[i][j]
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
	На вход получаем двумерные массивы int** a размерностью int n int m на int** b размерностью int m на int k и int** c размерностью int n на int k
	В матрицу int** c записываем произведение матрицы int** a на матрицу  int** b
	Считаем по правилу: c[i][j] = a[i][1]*b[1][j]+a[i][2]*b[2][j]+...+a[i][k]*b[k][j]
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

}//умножение матрицы на матрицу

void mult_of_num_and_matrix(int** a, int n, int m, int alpha)
{
	/*
	На вход получаем двумерны1 массивы int** a  размерностью int n на int m и число int alpha
	В матрицу int** a записываем произведение числа на эту же матрицу 
	Считаем по правилу a[i][j] = alpha * a[i][j];
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = alpha * a[i][j];
		}
	}
}//Умножение числа на матрицу

void D2_output_Double(double** a, int n, int m)
{
	/*
	На вход получаем двумерный масиив double** a, и его размерности int n, int m.
	Функция форматировано выводит двумерный массив c пробелами между эл-тами в 10 символов и 3 наками после запятой
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%10.3f", a[i][j]);
		}
		cout << endl;
	}
}//Вывод 2D массива (double)

void output(double a[], int n)
{
	/*
	На вход получаем одномерный масиив double a[] и его размерность int n
	Функция выводит одномерный массив в строчку 
	*/
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}//Вывод массива

void Gaus_method(double** a, double* b, double* x, int n)
{
	/*
	На вход получаем матрицу double** a размерностью int n на int n, вектор свободных членов double* b размерностью int n и векор решений double* x разиерностью int n
	Все формулы указаны в файле с отчётом, т.к. в Visual Studio писать их  неудобно

	*/
	int i, j, k;
	double d, s;
	for (k = 0; k < n; k++)//Прямой ход
	{
		for (j = k + 1; j < n; j++)
		{
			d = a[j][k] / a[k][k];
			for (i = k; i < n; i++)
			{
				a[j][i] = a[j][i] - d * a[k][i];
			}
			b[j] = b[j] - d * b[k];
		}
	}
	for (k = n - 1; k >= 0; k--)//Обратный ход
	{
		d = 0;
		for (j = k + 1; j < n; j++)
		{
			s = a[k][j] * x[j];
			d = d + s;
		}
		x[k] = (b[k] - d) / a[k][k];
	}
	Gaus_method_output(x, a, n);
	
}//Метод Гауса

void Gaus_method_output(double* x, double** a, int n)
{
	/*
	На вход получаем вектор решений double* x размерностью int n и двумерный массив double** a размерностью int n на int n
	Функция выводит Корни системы double** a
	*/
	cout << "System roots: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i + 1 << "]=" << x[i] << " " << endl;
	}
}