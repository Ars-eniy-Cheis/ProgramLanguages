#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>

using namespace std;

struct Date
{
	int day, year, month;
	int* MONTH = new int[12];
	bool leap; //Високосный или нет
};

void menu();
void day_output(Date d);
Date day_input(Date day_of_calen);
bool is_leap(Date d);
Date add_day(Date d, int D);
Date add_month(Date d, int M);
Date add_year(Date d, int Y);
Date subtract_day(Date d, int D);
Date subtract_month(Date d, int M);
Date subtract_year(Date d, int Y);
void month_fill(Date day_of_calen);

int main()
{
   //Lab 1. Number 1

	ifstream date_file("dates.txt");
	if (!date_file)
	{
		cout << "File error" << endl;
		return 1;
	}
	int n = 0;
	int* dat = new int[255];
	while (!date_file.eof())
	{
		date_file >> dat[n];
		n++;
	}
	date_file.close();
	Date* date_list = new Date[n/3];
	cout << n << endl;
	for (int i = 0; i < n; i += 3)
	{
		date_list[i / 3].day =  dat[i];
		date_list[i / 3].month = dat[i + 1];
		date_list[i / 3].year = dat[i + 2];
		month_fill(date_list[i / 3]);
	}
	for (int i = 0; i < n / 3; i++)
	{
		cout << i + 1 << ". " << endl;
		day_output(date_list[i]);
		day_output(add_day(date_list[i], 1));
		day_output(subtract_day(date_list[i], 1));
		cout << endl;
	}
	//Variant 4
	cout << "Output output date which next date won't get on another year" << endl;
	Date day_plus;
	for (int i = 0; i < n / 3; i++)
	{
		day_plus = add_day(date_list[i], 1);
		if (date_list[i].year == day_plus.year)
		{
			cout << i + 1 << ". " << endl;
			day_output(date_list[i]);
			day_output(day_plus);
			cout << endl;
		}

	}

}

void menu()
{
	cout << "1. Add" << endl << "2. Subtract" << endl << "0. Exit" << endl;
}

void day_output(Date d)
{
	cout << d.day << " day " << d.month << " month " << d.year << " year " << endl;
}

void month_fill(Date day_of_calen)
{
	day_of_calen.MONTH[0] = 31;
	day_of_calen.MONTH[1] = 28;
	day_of_calen.MONTH[2] = 31;
	day_of_calen.MONTH[3] = 30;
	day_of_calen.MONTH[4] = 31;
	day_of_calen.MONTH[5] = 30;
	day_of_calen.MONTH[6] = 31;
	day_of_calen.MONTH[7] = 31;
	day_of_calen.MONTH[8] = 30;
	day_of_calen.MONTH[9] = 31;
	day_of_calen.MONTH[10] = 30;
	day_of_calen.MONTH[11] = 31;
}

Date day_input(Date day_of_calen)
{
	cout << "Enter year" << endl;
	cin >> day_of_calen.year;
	day_of_calen.leap = is_leap(day_of_calen);
	cout << "Enter month" << endl;
	cin >> day_of_calen.month;
	if (day_of_calen.month > 12)
	{
		do
		{
			cout << "There are only 12 months. Enter again" << endl;
			cin >> day_of_calen.month;
		} while (day_of_calen.month > 12);
	}
	cout << "Enter day" << endl;
	cin >> day_of_calen.day;
	if ((day_of_calen.month == 1 || day_of_calen.month == 3 || day_of_calen.month == 5 || day_of_calen.month == 7 || day_of_calen.month == 8 || day_of_calen.month == 10 || day_of_calen.month == 12) && (day_of_calen.day > 31))
	{
		do
		{
			cout << "In this month only 31 days" << endl;
			cin >> day_of_calen.day;
		} while (day_of_calen.day > 31);
	}
	if ((day_of_calen.month == 4 || day_of_calen.month == 6 || day_of_calen.month == 9 || day_of_calen.month == 11) && (day_of_calen.day > 30))
	{
		do
		{
			cout << "In this month only 30 days" << endl;
			cin >> day_of_calen.day;
		} while (day_of_calen.day > 30);
	}
	if (day_of_calen.month == 2 && day_of_calen.leap == 1 && day_of_calen.day > 29)
	{
		do
		{
			cout << "In this month only 29 days" << endl;
			cin >> day_of_calen.day;
		} while (day_of_calen.day > 29);
	}
	if (day_of_calen.month == 2 && day_of_calen.leap == 0 && day_of_calen.day > 28)
	{
		do
		{
			cout << "In this month only 28 days" << endl;
			cin >> day_of_calen.day;
		} while (day_of_calen.day > 28);
	}
	day_of_calen.MONTH[0] = 31;
	day_of_calen.MONTH[1] = 28;
	day_of_calen.MONTH[2] = 31;
	day_of_calen.MONTH[3] = 30;
	day_of_calen.MONTH[4] = 31;
	day_of_calen.MONTH[5] = 30;
	day_of_calen.MONTH[6] = 31;
	day_of_calen.MONTH[7] = 31;
	day_of_calen.MONTH[8] = 30;
	day_of_calen.MONTH[9] = 31;
	day_of_calen.MONTH[10] = 30;
	day_of_calen.MONTH[11] = 31;
	return day_of_calen;
}

bool is_leap(Date d)
{
	if ((d.year % 4 == 0) && (d.year % 100 != 0) || d.year == 2000)
	{
		d.MONTH[1] = 29;
		return 1; //Високосный
	}
	else
	{
		d.MONTH[1] = 28;
		return 0;//Не високосный
	}
}

Date add_day(Date d, int D)
{
	if (D == 0)
	{
		return d;
	}
	for (int i = 0; i < D; i++)
	{
		d.day++;
		if (d.day > d.MONTH[d.month - 1])
		{
			d.month++;
			if (d.month > 12)
			{
				d.year++;
				d.month = 1;
				d.leap = is_leap(d);
			}
			d.day = 1;
		}
	}
	return d;
}

Date add_month(Date d, int M)
{
	int month_rem;
	if (M == 0)
	{
		return d;
	}
	month_rem = d.month;
	d.month = (d.month + M) % 12;
	d.year = d.year + (month_rem + M) / 12;
	d.leap = is_leap(d);
	if (d.day > d.MONTH[d.month - 1])
	{
		d.day = d.MONTH[d.month - 1];
	}
	return d;
}

Date add_year(Date d, int Y)
{
	if (Y == 0)
	{
		return d;
	}
	d.year = d.year + Y;
	d.leap = is_leap(d);
	if (d.day > d.MONTH[d.month - 1])
	{
		d.day = d.MONTH[d.month - 1];
	}
	return d;
}

Date subtract_day(Date d, int D)
{
	if (D == 0)
	{
		return d;
	}
	d.leap = is_leap(d);
	D = abs(D);
	for (int i = D; i > 0; i--)
	{
		d.day--;
		if (d.day < 1)
		{
			d.month--;
			if (d.month < 1)
			{
				d.year--;
				d.month = 12;
				d.leap = is_leap(d);
			}
			d.day = d.MONTH[d.month - 1];
		}
	}

	return d;
}

Date subtract_month(Date d, int M)
{
	if (M == 0)
	{
		return d;
	}
	M = abs(M);
	int month_rem;
	month_rem = d.month - 12;
	d.month = 12 - abs((d.month - M) % 12);
	d.year = d.year - abs((month_rem - M) / 12);
	d.leap = is_leap(d);
	if (d.day > d.MONTH[d.month - 1])
	{
		d.day = d.MONTH[d.month - 1];
	}
	return d;
}

Date subtract_year(Date d, int Y)
{
	if (Y == 0)
	{
		return d;
	}
	Y = abs(Y);
	d.year = d.year - Y;
	d.leap = is_leap(d);
	if (d.day > d.MONTH[d.month - 1])
	{
		d.day = d.MONTH[d.month - 1];
	}
	return d;
}