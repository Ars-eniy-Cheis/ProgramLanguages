// Strings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream> //библиотека для работы с файлами
#include <string.h>
#include <ctype.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int len = 81; // максимальная длина строки
    char word[len], s[len];
    ifstream  fin("text.txt");
    if (!fin) 
    {
        cout << "ошибка открытия файла" << endl;
        return 1; // если файл не найден, выходим из программы
    }

    cout << "Введите слово, которое хотите найти в тексте (не более 80 символов)" << endl;
    cin.getline(word, len);

    int n = strlen(word); // длина введенного слова
    int count = 0; // количество вхождений слова в текстовый файл
    while (fin.getline(s, len)) // пока есть строки в файле
    {
        if (strcmp(word, s) == 0)//сравниваем слова через функцию strcmp
        {
            count++;
        }
    }
    cout << "Слово  " << word << " встречается в тексте " << count << " раз " << endl;
    return 0;
}
