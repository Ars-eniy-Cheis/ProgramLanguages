#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

struct City
{
    char* name = new char[25];
    unsigned int region, scale, population;
};

struct Book
{
    char* author = new char[30];
    char* name = new char[30];
    unsigned int lib_card, cost;
};

void menu(); 
void D2_output(char** a, int n);
void output_cities(City a[], int n);
void output_books(Book a[], int n);
void sort_p(Book a[], int size);

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
            char** words = new char* [255];
            for (int i = 0; i < 255; i++)
            {
                words[i] = new char[30];
            }
            cout << "General task" << endl;
            ifstream cit_file("cit.txt");
            if (!cit_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            int n = 0;
            while (!cit_file.eof())
            {
                
                cit_file.getline(words[n], 30);
                n++;
            }
            City* cities = new City[n/4];
            for (int i = 0; i < n; i+=4)
            {
                    strcpy(cities[i/4].name, words[i]);
                    cities[i/4].region = atoi(words[i + 1]);
                    cities[i/4].scale = atoi(words[i + 2]);
                    cities[i/4].population = atoi(words[i + 3]);
            }
            output_cities(cities, n/4);
            for (int i = 0; i < n; i++)
            {
                delete words[i];
            }
            delete words;
            delete cities;
            menu();
            break;
        }
        case 2:
        {
            cout << "Variant 4" << endl << "Output all books" << endl;
            char** words = new char* [100];
            for (int i = 0; i < 100; i++)
            {
                words[i] = new char[30];
            }
            ifstream bok_file("bok.txt");
            if (!bok_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            int n = 0;
            int j = 0;
            while (!bok_file.eof())
            {
                n++;
                bok_file.getline(words[j], 30);
                j++;
            }
            Book* books = new Book[n / 4];
            cout << n;
            for (int i = 0; i < n; i += 4)
            {
                books[i / 4].lib_card = atoi(words[i]);
                strcpy(books[i / 4].author, words[i + 1]);
                strcpy(books[i / 4].name, words[i + 2]);
                books[i / 4].cost = atoi(words[i + 3]);
            }
            for (int i = 0; i < n; i++)
            {
                delete words[i];
            }
            delete words;
            output_books(books, n / 4);

            cout << "Output all Nabokov's books that were taken" << endl;
            int count = 0;
            for (int i = 0; i < n / 4; i++)
            {
                if (strcmp(books[i].author, "Vladimir Nabokov") == 0)
                {
                    count++;
                    cout << books[i].name << endl;
                }
            }
            if (count == 0)
            {
                cout << "All Nobokov's books are in library" << endl;
            }
            count = 0; 
            Book* sort_auth = new Book[n / 4];
            cout << "Output all books that costs more than 1000 rubles (Sort by author)" << endl;
            for (int i = 0; i < n / 4; i++)
            {
                if (books[i].cost > 1000 && books[i].cost < 3000)
                {
                    strcpy(sort_auth[count].author, books[i].author);
                    strcpy(sort_auth[count].name, books[i].name);
                    sort_auth[count].lib_card = books[i].lib_card;
                    sort_auth[count].cost = books[i].cost;
                    count++;
                }
            }
            if (count == 0)
            {
                cout << "There aren't any books that cost more than 1000 rubles" << endl;
            }
            else
            {
                sort_p(sort_auth, count);
                output_books(sort_auth, count);
            }
            delete books;
            delete sort_auth;
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
    /*Вывод меню*/
	cout << "MENU" << endl << endl << "1. General task" << endl << "2. Variant 4"  << endl;
}

void D2_output(char** a, int n)
{
    /*
    На вход получаем двумерный массив a символьных переменных и кол-во строк в нём - int n;
    Ф-ия выводит каждую строку, пока те не кончатся.
    Ничего не возвращает, т.к. тип void.
    */
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}//Вывод двумерного массива

void output_cities(City a[], int n)
{
    /*Специальная ф-ия для вывода структуры типа "City". 
    На вход получаем массив эл-тов City и его размерность - int n. Выводим эл-ты массива, а именно все поля структуры поочерёдно, пока они не закончатся.
    Ничего не возвращает, т.к. тип void.
    */
    for (int i = 0; i < n; i++)
    {
        cout << "City name: " << a[i].name << endl << "Region: " << a[i].region << endl << "Scale: "<< a[i].scale << " km^2" << endl << "Population: " << a[i].population << " people" << endl;
    }
}

void output_books(Book a[], int n)
{
    /*Специальная ф-ия для вывода структуры типа "Book".
   На вход получаем массив эл-тов Book и его размерность - int n. Выводим эл-ты массива, а именно все поля структуры поочерёдно, пока они не закончатся.
   Ничего не возвращает, т.к. тип void.
   */
    for (int i = 0; i < n; i++)
    {
        cout << "Library Card Number: " << a[i].lib_card << endl << "Author: " << a[i].author << endl << "Name of the book: " << a[i].name << endl << "Cost: " << a[i].cost << " rub" << endl;
    }
}

void sort_p(Book a[], int size)
{
    /*
    Пузырьковая сортировка для эл-тов типа Book.
    На вход получаем массив эл-тов Book и его размерность - int n.
    Ф-ия сортирует эл-ты опираясь на первый символ (а именно - букву) поля author. 
    То есть "книги" сортируются по именам авторов.
    Ф-ия ничего не возвращает, т.к. тип void.
    */
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j].author[0] > a[j + 1].author[0])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}