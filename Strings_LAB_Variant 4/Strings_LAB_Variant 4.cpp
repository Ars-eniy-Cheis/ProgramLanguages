
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

void menu();
int words_cmp(char* word1, char* word2);
int str_len(char str[]);
void D2_output(char** a, int n);

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
            //Задание 1
            cout << "Number 1" << endl << "enter 2 words (less than 256 symbols)"<<endl;
            char* word1 = new char[256];
            char* word2 = new char[256];
            cout << "Word 1: ";
            cin.clear();
            cin.ignore();
            cin.getline(word1, 256);
            cout << "Word 2: ";
            cin.clear();
            cin.ignore();
            cin.getline(word2, 256);
            cout<<words_cmp(word1, word2)<<endl;
            menu();
            break;
        }

        case 2:
        {
            //Задание 2
            cout << "Number 2" << endl;
            ifstream t_file("text.txt");
            if (!t_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            char** text = new char* [3];
            for (int i = 0; i < 3; i++)
            {
                text[i] = new char[50];
            }

            cout << text << endl;

            menu();
            break;
        }

        case 3:
        {
            //Задание 3
            cout << "Number 3" << endl;

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
    cout << "MENU" << endl << endl << "1. Strings Compare" << endl << "2. Shoterst word" << endl << "3. Decrease row of words" << endl;
}

int words_cmp(char* word1, char* word2)
{
    int len1 = str_len(word1), len2 = str_len(word2);
    if (len1 > len2+1)
    {
        return 1;
    }
    else if (len2+1 > len1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int str_len(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {

    }
    return i;
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
