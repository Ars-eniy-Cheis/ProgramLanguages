// Strings_Lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

void menu();
int str_len (char str[]);
void D2_output(char** a, int n);
bool Poli(char* text);
int q_words(char text[], char sep[], char* token);
int q_sent(char text[], char sep[], char* token);

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
            cin.clear();
            cin.ignore();
            cout << "Number 1" << endl << "Input the string (less than 256 symbols)" << endl;
            char* word = new char[256];
            cin.getline(word, 256);
            cout << "String length = " << str_len(word) << endl;
            menu();
            break;
        }
        case 2:
        {
            //Задание 2
            cout << "Number 2" << endl << "" << endl;

            char** words = new char* [1];
            for (int i = 0; i < 2; i++)
            {
                words[i] = new char[15];
            }
            ifstream nc_file("nouns.txt");
            if (!nc_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            int num_of_nouns = 0;
            while (!nc_file.eof())
            {
                int j = 0;
                nc_file.getline(words[j], 10);
                j++;
                num_of_nouns++;
            }
            ifstream vc_file("verbs.txt");
            if (!vc_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            int num_of_verbs = 0;
            while (!vc_file.eof())
            {
                int j = 0;
                vc_file.getline(words[j], 10);
                j++;
                num_of_verbs++;
            }
            ifstream pc_file("preposes.txt");
            if (!pc_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            int num_of_preposes = 0;
            while (!pc_file.eof())
            {
                int j = 0;
                pc_file.getline(words[j], 10);
                j++;
                num_of_preposes++;
            } 
            cout << "Number of nouns:"<< num_of_nouns << endl;
            cout << "Number of verbs:" << num_of_verbs  <<endl;
            cout << "Number of prepositions:" << num_of_preposes <<endl;

            char** article = new char* [2];
            for (int i = 0; i < 2; i++)
            {
                article[i] = new char[4];
            }
            char** noun = new char* [num_of_nouns];
            for (int i = 0; i < num_of_nouns; i++)
            {
                noun[i] = new char[10];
            }
            char** verb = new char* [num_of_verbs];
            for (int i = 0; i < num_of_verbs; i++)
            {
                verb[i] = new char[10];
            }
            char** prepos = new char* [num_of_preposes];
            for (int i = 0; i < num_of_preposes; i++)
            {
                prepos[i] = new char[10];
            }
            char* sentence  = new char[256];
            for (int i = 0; i < 256; i++)
            {
                sentence[i] = NULL;
            }

            ifstream a_file("articles.txt");
            if (!a_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            for (int i = 0; i < 2; i++)
            {
                a_file.getline(article[i], 4);
            }

            ifstream n_file("nouns.txt");
            if (!n_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            for (int i = 0; i < num_of_nouns; i++)
            {
                n_file.getline(noun[i], 10);
            }

            ifstream v_file("verbs.txt");
            if (!v_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            for (int i = 0; i < num_of_verbs; i++)
            {
                v_file.getline(verb[i], 10);
            }

            ifstream p_file("preposes.txt");
            if (!p_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            for (int i = 0; i < num_of_preposes; i++)
            {
                p_file.getline(prepos[i], 10);
            }

            strcat(sentence, article[rand() %2]);
            strcat(sentence, " ");
            strcat(sentence, noun[rand() % num_of_nouns]);
            strcat(sentence, " ");
            strcat(sentence, verb[rand() % num_of_verbs]);
            strcat(sentence, " ");
            strcat(sentence, prepos[rand() % num_of_preposes]);
            strcat(sentence, " ");
            strcat(sentence, article[rand() % 2]);
            strcat(sentence, " ");
            strcat(sentence, noun[rand() % num_of_nouns]);
            strcat(sentence, ".");
            if (sentence[0] == 't')
            {
                sentence[0] = 'T';
            }
            else
            {
                sentence[0] = 'A';
            }
            cout << sentence << endl << endl;
            
            menu();
            break;
        }

        case 3:
        {
            //Задание 3
            cout << "Number 3 polindrom" << endl << "enter word or sentence (less than 255 symbols)" << endl;
            cin.clear();
            cin.ignore();
            char* pol = new char[256];
            cin.getline(pol, 256);
            if (Poli(pol))
            {
                cout << "This is a polindrom" << endl;
            }
            else
            {
                cout << "it isn't polindrom" << endl;
            }

            menu();
            break;
        }

        case 4:
        {
            //Задание 4
            cout << "Number 4 " << endl << "quantity of sentences and words" << endl;

            ifstream t_file("text.txt");
            if (!t_file)
            {
                cout << "File error" << endl;
                return 1;
            }
            char* text = new char[256];
            char* text_cp = new char[256];
            t_file.getline(text, 256);
            cout << text << endl;
            strcpy(text_cp, text);
            char seps_words[] = " ,.;!?";
            char seps_sent[] = ".!?";
            char* token_w = NULL;
            char* token_s = NULL;
            cout << "quantity of words: " << q_words(text, seps_words, token_w) << endl;
            cout << "quantity of sentences : " << q_sent(text_cp, seps_sent, token_s) << endl;

            menu();
            break;
        }

        case 0:
        {
            return 0;
        }
        }
    }
    return 0;
}

void menu()
{
    cout << "MENU" << endl << endl << "Choose number: " << endl << "1. Number 1" << endl << "2. Number 2" << endl << "3. Number 3" << endl << "4. Number 4" << endl << "0. Exit" << endl;
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

bool Poli(char* text) 
{
    for (int i = 0, j = strlen(text) - 1; i < j;)
    {
        if (isalpha((unsigned char)text[i])) 
        {
            if (isalpha((unsigned char)text[j]))
            {
                if (tolower(text[i]) != tolower(text[j])) return 0;
                i++; j--;
            }
            else j--;
        }
        else i++;
    }

    return 1;
}

int q_words(char text[], char sep[], char* token)
{
    int count = 0;
    token = strtok(text, sep);
    while (token != NULL) 
    {
        token = strtok(NULL, sep);
        count++;
    }

    return count;
}

int q_sent(char text[], char sep[], char* token)
{
    int count = 0;
    token = strtok(text, sep);
    while (token != NULL)
    {
        token = strtok(NULL, sep);
        count++;
    }

    return count;
}