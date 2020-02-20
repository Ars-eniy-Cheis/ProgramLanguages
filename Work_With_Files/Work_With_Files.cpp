
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale>
#include <fstream>

using namespace std;

void output(int a[], int n);
int rand_in_bounds(int a, int b);
void Bubble_sort(int a[], int n);

int main()
{
    //Variant 3, Number 1
    cout << "Number 1" << endl;
    ofstream file_r;
    file_r.open("random.txt");
    for (int i = 0; i < 1000; i++)
    {
        file_r << rand() % 1000-200 << " ";
    }
    file_r.close();
    ifstream file_wr;
    int n = 0;
    file_wr.open("random.txt");
    int x;
    while (!file_wr.eof())
    {
        file_wr >> x;
        if (abs(x % 2) == 0)
        {
            n++;
        }
           
    }
    file_wr.close();
    int* a = new int[n];
    cout << "Quantity of even ellements = " << n << endl;
    file_wr.open("random.txt");
    int j = 0;
    while (!file_wr.eof())
    {
        file_wr >> x;
        if (abs(x % 2) == 0)
        {
            a[j] = x;
            j++;
        }
    }
    Bubble_sort(a, n);
    output(a, n);
    delete[] a;
    //Number 2
    cout<< endl << "Number 2" << endl;
    int A, B;
    cout << "enter int left bound (include)" << endl;
    cin >> A;
    cout << "enter int right bound (include and bigger then left)" << endl;
    cin >> B;
    if (B <= A)
    {
        do
        {
            cout << "right bound should be bigger then left bound" << endl;
            cin >> B;
        } while (B <= A);
        
    }
    cout << "enter quantity of elements of array" << endl;
    cin >> n;
    a = new int[n];
    for (int i = 0; i<n; i++)
    {
        a[i] = rand_in_bounds(A, B);
    }
    output(a, n);


}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}//Вывод массива

int rand_in_bounds(int a, int b)
{
    int g = rand() % (b - a + 1) + a;
    return g;
}//случайное число в заданном диапозоне

void Bubble_sort(int a[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n-1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                int b = a[j]; 
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
}//Пузырьковая сортировка