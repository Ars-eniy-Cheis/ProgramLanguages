﻿// Strings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

void menu();
int palindrom(char* a);
void changeString(char* a);
int palindrom1(char* a);
void newString(char* a, char* b);
int palindrom3(char* a);

int main()
{
    setlocale(LC_ALL, "Russian");

    /* Задание №1 - сравнение алгоритмов вычисления палиндромов (делаю его здесь, т.к. в прошлый раз его не заметил.)*/
    menu();
    cout << "Палиндромы" << endl;
    int num = 1;
    while (num != 0)
    {
        cin >> num;
        switch (num)
        {
        case 1:
        {
            cin.clear();
            cin.ignore();
            char* s = new char[80];
            cout << "Введите строку - ";
            cin.getline(s, 255);// вводится строка 

            if (palindrom(s))
                cout << "палиндром" << endl;
            else
                cout << "не палиндром" << endl;

            menu();
            break;
        }
        case 2:
        {
            cin.clear();
            cin.ignore();
            int n;
            char* s = new char[256];
            cout << "Введите строку - ";
            cin.getline(s, 255);// вводится строка 
            n = strlen(s);// вычисляем длину строки

            cout << n << ' ' << s << endl; // выводим длину строки и саму строку
            cout << endl;

            changeString(s); //преобразуем строку
            cout << s << ' ' << strlen(s) << endl;  //выводим преобразованную строку  на экран

        // проверяем является ли строка палиндромом    
            if (palindrom1(s))
                cout << "палиндром" << endl;
            else
                cout << " не палиндром" << endl;

            menu();
            break;
        }
        case 3:
        {
            cin.clear();
            cin.ignore();
            int n;
            char* s = new char[1];// исходная строка
            cout << "Введите строку - ";
            cin.getline(s, 255);// вводится строка, не более 255 символов
            n = strlen(s);// вычисляем длину строки
            cout << n << ' ' << s << endl; // выводим длину строки и саму строку
            char* s1 = new char[1]; // новая строка
            newString(s, s1); // получаем новую строку
            cout << s1 << ' ' << strlen(s1) << endl; // выводим новую строку и ее длину
            if (palindrom3(s1))
                cout << "палиндром" << endl;
            else
                cout << " не палиндром" << endl;

            menu();
            break;
        }
        case 0:
        {
            cin.clear();
            cin.ignore();
            cout << "Количество вхождений слова в текст" << endl;
            int count = 0;
            const int len = 81;
            char word[len], s[len];
            ifstream  fin("text.txt");
            cout << "Введите заданное слово (не более 80 символов): ";
            cin >> word;
            fin.getline(s, len);
            char* token;
            token = strtok(s, " ,.;:!?");
            while (token != NULL)
            {
                if (strcmp(word, token) == 0)
                {
                    count++;
                }
                token = strtok(NULL, " ,.;:?!");
            }
            cout << "Cлово " << word << " встречается в тексте: " << count << " раз(а)" << endl;

            return 0;
        }
        }
    } 
}

void menu()
{
    cout << "MENU" << endl << endl << "1. Алгоритм 1" << endl << "2. Алгоритм 2" << endl << "3. Алгоритм 3" << endl << "0. переход к заданию с подсчётом количества вхождений слова в текст." << endl;
}

int palindrom(char* a)
// а – исходная строка
// функция возвращает значение 1, если строка является палиндромом и 0 в //противном случае.
//сама строка не изменяется

{
    bool t = 1; //t=1, если строка палиндром, t=1 в противном случае
 // перебираем все символы строки до середины строки. 
 // i –индекс рассматриваемого символа слева, j – индекс символа справа,    

    for (int i = 0, j = strlen(a) - 1; i < j;)
    {
        if (isalpha(a[i])) // если символ справа - буква
        {
            if (isalpha(a[j])) // если символ слева - буква
            {
                if (tolower(a[i]) != tolower(a[j]))
                {
                    t = 0; break;
                    // если  символы не совпали, то прекращаем перебор – 
                    //строка не являет ся палиндромом 
                }
                i++; j--; // переходим к следующим символам слева и справа
            }
            else j--; // если символ права не буква, переходим к следующему справа
        }
        else i++; // если символ слева не буква, переходим к следующему слева


    }
    return t;  // t=1, если строка –палиндром; t=1, t=0 - если строка –палиндром; 

}

void changeString(char* a)
// a - исходная строка
// После выполнения функции строка a  изменится – в не будут только буквы, //преобразованные в нижний регистр
{
    int n = strlen(a);
    int i = 0;
    while (i < n)
    {
        if (!isalpha(a[i])) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }

            n--;
        }
        a[i] = tolower(a[i]); i++;
    }
    a[n] = '\0'; // записываем нуль символ в конец строки

}

int palindrom1(char* a)
// а – исходная строка
// функция возвращает значение 1, если строка является палиндромом и 0 в //противном случае. Строка остается без изменений

{
    bool t = 1; //t=1, если строка палиндром, t=1 в противном случае
 // перебираем все символы строки до середины строки. 
//Сравниваем символы на  одном расстоянии от начала и от конца строки  
    int n = strlen(a);
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            // если какие-то символы не совпали, то прекращаем перебор – строка не //является палиндромом
            t = 0; break;
        }

    }
    return t;
}

void newString(char* a, char* b)
//a - исходная строка
//в функции получаем новую строку b - состоящюю только из букв строки a,
//преобразованных в нижний регистр
//строка a не изменяется
{
    int n = strlen(a);
    // i - индекс символа в строке a, k - индекс символа в строке b
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(a[i])) {
            b[k++] = tolower(a[i]);
        }
    }
    b[k] = '\0'; // нуль символ к конце строки b
}

int palindrom3(char* a)
// а – исходная строка
// функция возвращает значение 1, если строка является палиндромом и 0 в //противном случае. Строка остается без изменений
{
    bool t = 1; //t=1, если строка палиндром, t=1 в противном случае
// перебираем все символы строки до середины строки. Сравниваем символы на //одном расстоянии от начала и от конца строки  
    int n = strlen(a);
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            // если какие-то символы не совпали, то прекращаем перебор – строка не //является палиндромом
            t = 0; break;
        }
    }
    return t;
}
