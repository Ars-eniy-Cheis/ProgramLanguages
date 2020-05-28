
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
int shotest_word(char** a, int &row, int &col);
int str_len(char** str, int num_of_line);
void bubble_sort(char** a);
int q_of_words(char** str, int line);

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
            cout << words_cmp(word1, word2) << endl;
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
            char* short_word = new char[10];
            for (int i = 0; i < 3; i++)
            {
                t_file.getline(text[i], 50);
                cout << text[i] << endl;
            }
            int row, col, length = shotest_word(text, row, col);
            cout << "length of shorterst word: " << length << endl;
            cout << "Shortest word: " << endl;
            int j = col;
            while ( j > 0 )
            {
                for (int i = 0; i < 10; i++)
                {
                    
                    if (isalpha(text[row][j - 1]))
                    {
                        short_word[i] = text[row][j - 1];
                    }
                    else
                    {
                        break;
                    }
                    j--;
                } 
                if (!isalpha(text[row][j - 1]))
                {
                    break;
                }
            }   
            for (int i = length-1; i >= 0; i--)
            {
                cout << short_word[i];
            }
            cout << endl;
            menu();
            break;
        }

        case 3:
        {
            //Задание 3
            cout << "Number 3" << endl;
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
            for (int i = 0; i < 3; i++)
            {
                t_file.getline(text[i], 50);
                cout << text[i] << endl;
            }
            bubble_sort(text);
            for (int i = 0; i < 3; i++)
            {
                cout << text[i] << endl;
            }

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
}//Меню

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
}//Посимвольное равнение слов

int str_len(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {

    }
    return i;
}//Вычисление длины строки

void D2_output(char** a, int n)
{
    /*
    */
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}//Вывод двумерного массива типа char

int shotest_word(char** a, int& row, int& col)
{
    int len = 0, min_len = 50;
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        while (a[i][j] != '\0')
        {
            if (isalpha(a[i][j]))
            {
                len++;
            }
            else
            {
                if(len <= min_len)
                {
                    min_len = len;
                    row = i;
                    col = j;
                }
                len = 0;
            }
            j++;
        }
    }
    return min_len;
}//Поиск самого короткого слова в 2D масииве

int str_len(char** str, int num_of_line)
{
    int j = 0;
        while (str[num_of_line][j] != '\0')
        {
            j++;
        }
    return j;
}//Вычисление длины строки в 2D массиве

void bubble_sort(char** a)
{
    for (int i = 0; i < 3; i++) 
    {
        bool flag = true;
        for (int j = 0; j < 3 - (i + 1); j++) 
        {
            if (q_of_words(a, j) < q_of_words(a, j+1))
            {
                flag = false;
                swap(a[j], a[j + 1]);
            }
        }
        if (flag) 
        {
            break;
        }
    }
}//Пузырьковая сортировка

int q_of_words(char** str, int line)
{
    int quant = 0, j = 0;
    while (str[line][j] != '\0')
    {
        if (str[line][j] == ' ')
        {
            quant++;
        }
        j++;
    }
    return quant+1;
}//Подсчёт количества слов в 2D массиве