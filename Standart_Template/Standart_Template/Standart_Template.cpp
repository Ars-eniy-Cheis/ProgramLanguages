#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include "string"
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include "numeric"

using namespace std;

void menu();
stack<char> ToStack(stack<char> s, const string& str);
queue<char> ToQueue(queue<char> s, const string& str);
void vec_output(vector<int>& V, int n);
bool is_palindrom(stack<char> &S, queue<char> &Q, int n);
bool bkt_check(stack<char>& S, int n);
void quantity_of_el(vector<int>& V, int n);
int quant_of_even(vector<int>& V, int n);
int quant_of_odd(vector<int>& V, int n);
int sum_of_even(vector<int>& V, int n);
int sum_of_all(vector<int>& V, int n);

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
			string word;
			stack<char> polindrom_S;
			queue<char> polindrom_Q;
			cout << "Input word" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, word);
			polindrom_S = ToStack(polindrom_S, word);
			polindrom_Q = ToQueue(polindrom_Q, word);
			if (is_palindrom(polindrom_S, polindrom_Q, word.length()))
			{
				cout << "palindrom" << endl;
			}
			else
			{
				cout << "not palindrom" << endl;
			}
			menu();
			break;
		}
		case 2:
		{
			stack<char> sentence;
			string sentence_S;
			cout << "Input sentence" << endl;
			cin.clear();
			cin.ignore();
			getline(cin, sentence_S);
			sentence = ToStack(sentence, sentence_S);
			if (bkt_check(sentence, sentence_S.length()))
			{
				cout << "balance is followed" << endl;
			}
			else
			{
				cout << "balance isn't followed" << endl;
			}
			menu();
			break;
		}
		case 3:
		{
			ifstream numbers1("nums.txt");
			int m = 0, l;
			while (!numbers1.eof())
			{
				numbers1 >> l;
				m++;
			}
			numbers1.close();
			ifstream numbers("nums.txt");
			vector<int> vec(m);
			int i = 0;
			while (!numbers.eof())
			{
				numbers >> vec.at(i);
				i++;
			}
			numbers.close();
			vec_output(vec, m);
			cout << endl << "enter number n, which you want to find in vector" << endl;
			int n;
			cin >> n;
			cout << "" << endl;
			cout<< n << " meets " << count(vec.begin(), vec.end(), n) << " times" << endl;
			cout << "Quantity of even elements of vector = " << quant_of_even(vec, m) << endl << "Quantity of odd elements of vector = " << quant_of_odd(vec, m) << endl;
			if (quant_of_even(vec, m) > quant_of_odd(vec, m))
			{
				cout << "Sum of even elements = " << sum_of_even(vec, m) << endl;
			}
			else if (quant_of_even(vec, m) < quant_of_odd(vec, m))
			{
				cout << "Sum of all elements = " << sum_of_all(vec, m) << endl;
			}
			else
			{
				cout << "I don't know what to do, if quantity of even = quantity of odd" << endl;
			}
			cout << "sort of vector" << endl << "Original: ";
			vec_output(vec, m);
			cout << endl << "sorted: ";
			sort(vec.begin(), vec.end());
			vec_output(vec, m);
			cout << endl << "swap first and last element" << endl;
			swap(vec[0], vec[m-1]);
			vec_output(vec, m);
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
	cout << endl << "MENU" << endl << endl << "1. Polindrom" << endl << "2. Bracket Check" << endl << "3. Exercise 2" << endl << "0. EXIT" << endl;
}

stack<char> ToStack(stack<char> s, const string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		s.push(str[i]);
	}
	return s;
}

queue<char> ToQueue(queue<char> s, const string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		s.push(str[i]);
	}
	return s;
}

void vec_output(vector<int>& V, int n)
{
	cout << "( ";
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			cout << V[i] << " )";
		}
		else
		{
			cout << V[i] << ", ";
		}
	}
}


bool is_palindrom(stack<char>& S, queue<char>& Q, int n)
{
	int count = 0;
	for (int i = 0; i < n/2; i++)
	{
		if (S.top() == Q.front())
		{
			count++;
		}
		S.pop();
		Q.pop();
	}
	if (count == n / 2)
		return true;
	else
		return false;
}

bool bkt_check(stack<char>& S, int n)
{
	int rount_count_open = 0, sqr_count_open = 0, fig_count_open = 0;
	int rount_count_cls = 0, sqr_count_cls = 0, fig_count_cls = 0;
	for (int i = 0; i < n; i++)
	{
		if (S.top() == '(')
		{
			rount_count_open++;
		}
		if (S.top() == '[')
		{
			sqr_count_open++;
		}
		if (S.top() == '{')
		{
			fig_count_open++;
		}
		if (S.top() == ')')
		{
			rount_count_cls++;
		}
		if (S.top() == ']')
		{
			sqr_count_cls++;
		}
		if (S.top() == '}')
		{
			fig_count_cls++;
		}
		S.pop();
	}
	if (rount_count_open == rount_count_cls && sqr_count_open == sqr_count_cls && fig_count_open == fig_count_cls)
	{
		return true;
	}
	else
		return false;
}

void quantity_of_el(vector<int>& V, int n)
{
}

int quant_of_even(vector<int>& V, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (V.at(i) % 2 == 0)
		{
			k++;
		}
	}
	return k;
}

int quant_of_odd(vector<int>& V, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (V.at(i) % 2 == 1)
		{
			k++;
		}
	}
	return k;
}

int sum_of_even(vector<int>& V, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (V.at(i) % 2 == 0)
		{
			k += V.at(i);
		}
	}
	return k;
}

int sum_of_all(vector<int>& V, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
			k += V.at(i);
	}
	return k;
}
