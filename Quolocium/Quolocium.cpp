// Quolocium.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>

using namespace std;
void non_even(char* string, int n);
void D2_output(char** a, int n);

int main()
{
    //Задание 1
    cout << "number 1" << endl;
    cout << "Enter string" << endl;
    char* string = new char [256];
    cin.clear();
    cin.ignore();
    cin.getline(string, 256);
    non_even(string, 256);
    cout<< "String without even elements: " << string << endl;

    //Задание 2

    char s[13] = "Hello world!";
    cout<<sizeof(s);
    return 0;
}

void non_even(char* string, int n)
{
    /*
    Задание 1
    Алгоритм идёт по строке и смотри, есть ли в ней эл-ты 0, 2, 4, 6 и 8.
    если эл-т не чётный, то он перебрасывается назад на место идущее после последнего не чётного эл-та. 
    Если чётные эл-ты стоят в начале массива, то нечётный переходит на первое место, т.е. s[0]
    */
    int j;
    j = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != '0' && string[i] != '2' && string[i] != '4' && string[i] != '6' && string[i] != '8')
        {
            if (i != j)
            {
                string[j] = string[i];
            }
            j++;
        }
    }
    string[j] = '\0';
}

void D2_output(char** a, int n)
{
    /*
    */
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}//Вывод двумерного массива