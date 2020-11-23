//#include "App.h"
//
//int main()
//{
//
//	App* app = new App();
//	app->Run();
//
//	return 0;
//
//}

#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include <malloc.h>

using namespace std;

int prior(char a)  // функция, возвращающая приоритет операции
{
    if (a == '^')
        return 4;
    else
        if (a == '*' || a == '/' || a == '%')
            return 3;
        else
            if (a == '+' || a == '-')
                return 2;
            else
                if (a == '(' || a == ')')
                    return 1;
                else
                    return 0;
}
int calc(int a, int b, char c) // функция действия с двумя числами
{
    switch (c)
    {
    case '+': return a + b; break;
    case '-': return a - b; break;
    case '*': return a * b; break;
    case '/': return a / b; break;
    case '%': return a % b; break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int number = 0;
    char x = '1';
    stack<char> st;
    vector<int> a;
    stack<int> st2;
    vector<char> output;
    bool flag = false;
    while (int(x) != 10) // (int) x = 10 признак enter
    {
        cin.get(x); // считываем символ
        if (x == '0' || atoi(&x) != 0) // если символ - цифра, или 0, то символ является частью числа или самим числом
        {
            number *= 10; // добавляем разряд к числу
            number += atoi(&x); // прибавляем к числу введенную только что цифру
            flag = true; // признак ввода числа
        }
        else// если введен символ, не являющийся цифрой -> ввод числа окончен, его можно полложить в массив для чисел
            if (flag == true)
            {
                a.push_back(number);// добавляем число в массив чисел 
                output.push_back('1'); // '1' =  признак числа
                number = 0; // обнуляем переменную для числа
                flag = false; // ввод числа окончен
            }
        if (x == '*' || x == '/' || x == '%' || x == '+' || x == '-' || x == '(' || x == '^')
            // если введен символ, то следуем алгоритму перевода в постфиксную запись
            // алгоритм перевода ->
        {
            while (!st.empty() && prior(x) <= prior(st.top()) && x != '(')
            {
                output.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
        if (x == ')')
        {
            while (st.top() != '(')
            {
                output.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty())
    {
        output.push_back(st.top());
        st.pop();
    }
    // 2 часть (подсчет выражения в постфиксной записи)
    char v; // переменная для atoi
    int j = 0; // переменная для нивелирования погрешности сдвига
    for (int i = 0; i < output.size(); i++) // просматриваем вектор вызова
    {
        v = output[i];
        if (atoi(&v) != 0) { // если элемент - какое-то число, значит пушим в стек число из массива чисел
            st2.push(a[j]);
            j++;
        }
        else // если элемент - операция, тогда вытаскиваем 2 числа из стека, производим между ними операцию, добавляем в стек результат
        {
            int k = st2.top();
            st2.pop();
            int b = st2.top();
            st2.pop();
            if (v == '/' && k == 0) {
                cout << "Ошибка деления на 0";
                system("PAUSE");
                exit(1);
            }
            st2.push(calc(b, k, v));
            j--; // уменьшаем переменную, созданную для удаления погрешности сдвига
        }
    }
    cout << " = " << st2.top() << endl;  // в конце, в стеке будет единственный элемент - результат вычислений

    system("PAUSE");
    return 0;
}