#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159265  

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

class Vector
{
public:
    friend Matrix;
    int size;
    float* coords;
    Vector();
    Vector(int new_size, float* new_coords);
    Vector(int new_size);
    ~Vector();
    Vector(const Vector& copy);
    void input();
    void output();
    double angle(Vector& a);
    double abs(Vector& a);
    Vector operator= (const Vector& a);
    Vector operator+ (const Vector& a);
    Vector operator- (const Vector& a);
    int operator* (const Vector& a);
    Vector operator* (const int a);
    bool operator> (Vector& a);
    bool operator< (Vector& a);
    bool operator<= (Vector& a);
    bool operator>= (Vector& a);
    bool operator== (Vector& a);
    bool operator!= (Vector& a);

    friend istream& operator>> (istream& in, Vector& a);
    friend ostream& operator<< (ostream& out, const Vector& a);
};

class Matrix
{
    int rows, cols;
    float** nums;

    public:
    friend Vector;
    Matrix();
    Matrix(int new_rows, int new_cols, float** new_nums);
    Matrix(int new_rows, int new_cols);
    Matrix(const Matrix& copy);
    ~Matrix();
    Matrix operator= (const Matrix& a);
    Matrix operator+ (const Matrix& a);
    Matrix operator- (const Matrix& a);

    friend istream& operator>> (istream& in, Matrix& a);
    friend ostream& operator<< (ostream& out, const Matrix& a);
};

void menu();

int main()
{
    //Lab Matrix_class
    menu();
    int num = 1;
    while (num != 0)
    {
        cin >> num;
        switch (num)
        {
        case 1:
        {
            Matrix A, B;
            cin >> A;
            cin >> B;
            cout << A << endl << endl << B;

            menu();
            break;
        }
        case 2:
        {

            menu();
            break;
        }
        case 3:
        {

            menu();
            break;
        }
        case 4:
        {

            menu();
            break;
        }
        case 5:
        {

            menu();
            break;
        }
        case 6:
        {

            menu();
            break;
        }
        case 7:
        {

            menu();
            break;
        }
        case 8:
        {

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
    cout << endl << "MENU" << endl << endl << "1. Matrix + Matrix" << endl << "2. Matrix - Matrix" << endl << "3. Number * Matrix" << endl << "4. Vector * Matrix" << endl << "5. Matrix * Vector " << endl << "6. Matrix * Matrix" << endl << "7. Determinant" << endl << "8. Matrix^(-1)" << endl << "9. Transpotted" << endl << "0. EXIT" << endl;
}

Vector::Vector()
{
    size = 2;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = 0;
    }
}

Vector::Vector(int new_size, float* new_coords)
{
    size = new_size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = new_coords[i];
    }
}

Vector::Vector(int new_size)
{
    size = new_size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = 0;
    }
}

Vector::Vector(const Vector& copy)
{
    size = copy.size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        coords[i] = copy.coords[i];
    }
}

Vector::~Vector()
{
    delete[] coords;
}

void Vector::input()
{
    cout << "Enter size: ";
    cin >> size;
    coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter coordinate: ";
        cin >> coords[i];
    }
}

void Vector::output()
{
    for (int i = 0; i < size; i++)
    {
        cout << coords[i] << " ";
    }
}

double Vector::angle(Vector& a)
{
    if (size == a.size)
    {
        int tmp = *this * a;
        double fabs = 0;
        fabs = tmp / (abs(*this) * abs(a));
        return (acos(fabs) * 180 / PI);
    }
    else
    {
        cout << "Vectors should be the same size";
        return 0;
    }
}

double Vector::abs(Vector& a)
{
    double abs = 0;
    for (int i = 0; i < a.size; i++)
    {
        abs += a.coords[i] * a.coords[i];
    }
    return sqrt(abs);
}

Vector Vector::operator= (const Vector& a)
{
    size = a.size;
    Vector Temp(size);
    Temp.coords = new float[size];
    for (int i = 0; i < size; i++)
    {
        Temp.coords[i] = a.coords[i];
    }
    return Temp;
}

Vector Vector::operator+ (const Vector& a)
{
    if (size == a.size)
    {
        Vector Temp(size);
        for (int i = 0; i < size; i++)
        {
            Temp.coords[i] = coords[i] + a.coords[i];
        }
        return Temp;
    }
    else
    {
        Vector Temp;
        cout << "Vectors should be the same size";
        return Temp;
    }
}

Vector Vector::operator- (const Vector& a)
{
    if (size == a.size)
    {
        Vector Temp(size);
        for (int i = 0; i < size; i++)
        {
            Temp.coords[i] = coords[i] - a.coords[i];
        }
        return Temp;
    }
    else
    {
        Vector Temp;
        cout << "Vectors should be the same size";
        return Temp;
    }
}

int Vector::operator* (const Vector& a)
{
    int Temp = 0;
    if (size == a.size)
    {
        for (int i = 0; i < size; i++)
        {
            Temp += coords[i] * a.coords[i];
        }
        return Temp;
    }
    else
    {
        cout << "Vectors should be the same size";
        return 0;
    }
}

Vector Vector::operator* (const int a)
{
    Vector Temp(size);
    for (int i = 0; i < size; i++)
    {
        Temp.coords[i] = coords[i] * a;
    }
    return Temp;
}

istream& operator>> (istream& in, Vector& a)
{
    cout << "Enter size: ";
    in >> a.size;
    if (a.size < 2)
    {
        do
        {
            cout << "Size should be >= 2. Try again" << endl;
            in >> a.size;
        } while (a.size < 2);
    }
    a.coords = new float[a.size];
    for (int i = 0; i < a.size; i++)
    {
        cout << "Enter coordinate: ";
        in >> a.coords[i];
    }
    return in;
}

ostream& operator<< (ostream& out, const Vector& a)
{
    cout << "(";
    for (int i = 0; i < a.size; i++)
    {
        if (i < (a.size - 1))
        {
            out << a.coords[i] << ", ";
        }
        else out << a.coords[i] << ")";
    }
    return out;
}

bool Vector::operator> (Vector& a)
{
    if (abs(*this) > abs(a))
        return 1;
    else return 0;
}

bool Vector::operator< (Vector& a)
{
    if (abs(*this) < abs(a))
        return 1;
    else return 0;
}

bool Vector::operator<= (Vector& a)
{
    if (abs(*this) <= abs(a))
        return 1;
    else return 0;
}

bool Vector::operator>= (Vector& a)
{
    if (abs(*this) >= abs(a))
        return 1;
    else return 0;
}

bool Vector::operator== (Vector& a)
{
    if (abs(*this) == abs(a))
        return 1;
    else return 0;
}

bool Vector::operator!= (Vector& a)
{
    if (abs(*this) != abs(a))
        return 1;
    else return 0;
}

Matrix::Matrix()
{
    cout << "Default constructor" << endl;
    rows = 2;  cols = 2;
    nums = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        nums[i] = new float[cols];
        for (int j = 0; j < cols; j++)
        {
            nums[i] = 0;
        } 
    }
}

Matrix::Matrix(int new_rows, int new_cols, float** new_nums)
{
    rows = new_rows; cols = new_cols;
    nums = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        nums[i] = new float[cols];
        for (int j = 0; j < cols; j++)
        {
            nums[i][j] = new_nums[i][j];
        }
    }
}

Matrix::Matrix(int new_rows, int new_cols)
{
    cout << "Constructor with parametrs" << endl;
    rows = new_rows; cols = new_cols;
    nums = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        nums[i] = new float[cols];
        for (int j = 0; j < cols; j++)
        {
            nums[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& copy)
{
    rows = copy.rows; cols = copy.cols;
    nums = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        nums[i] = new float[cols];
        for (int j = 0; j < cols; j++)
        {
            nums[i][j] = copy.nums[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete nums[i];
    }
    delete nums;
}

Matrix Matrix::operator= (const Matrix& a)
{
    rows = a.rows; cols = a.cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            nums[i][j] = a.nums[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+ (const Matrix& a)
{
    if (rows == a.rows && cols == a.cols)
    {
        Matrix Temp(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            Temp.nums[i][j] = nums[i][j] + a.nums[i][j];
        }
        return Temp;
    }
    else
    {
        Matrix Temp;
        cout << "Vectors should be the same size";
        return Temp;
    }
}

Matrix Matrix::operator- (const Matrix& a)
{
    if (rows == a.rows && cols == a.cols)
    {
        Matrix Temp(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                Temp.nums[i][j] = nums[i][j] - a.nums[i][j];
        }
        return Temp;
    }
    else
    {
        Matrix Temp;
        cout << "Vectors should be the same size";
        return Temp;
    }
}

istream& operator>> (istream& in, Matrix& a)
{
    cout << "Enter quantity of rows: ";
    in >> a.rows;
    if (a.rows < 2)
    {
        do
        {
            cout << "Quantity of rows >= 2. Try again" << endl;
            in >> a.rows;
        } while (a.rows < 2);
    }
    cout << "Enter quantity of cols: ";
    in >> a.cols;
    if (a.cols < 2)
    {
        do
        {
            cout << "Quantity of cols >= 2. Try again" << endl;
            in >> a.cols;
        } while (a.cols < 2);
    }
    a.nums = new float* [a.rows];
    for (int i = 0; i < a.rows; i++)
    {
        a.nums[i] = new float[a.cols];
        for (int j = 0; j < a.cols; j++)
        {
            cout << "Enter row: ";
            in >> a.nums[i][j];
        }
    }
    return in;
}

ostream& operator<< (ostream& out, const Matrix& a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            printf("%.3f", a.nums[i][j]);
        }
    }
    return out;
}