#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

struct Date
{
	unsigned int day, year, month;
	int* MONTH = new int[12];
	bool leap; //Високосный или нет
};

void menu();
void day_output(Date d);
bool is_leap(Date d);
Date add_day(Date d, int D);
Date add_month(Date d, int M);
Date add_year(Date d, int Y);

int main()
{
	Date day_of_calen;
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
	if ((day_of_calen.month == 1 || day_of_calen.month == 3 || day_of_calen.month == 5 || day_of_calen.month ==  7 || day_of_calen.month == 8 || day_of_calen.month ==  10 || day_of_calen.month == 12) && (day_of_calen.day>31))
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

	menu();
	int num = 1;
	while (num != 0)
	{
		cin >> num;
		switch (num)
		{
		case 1:
		{
			int d, m, y; //День, месяц, год
			cout << "How many days do you want to add?" << endl;
			cin >> d;
			cout << "How many months do you want to add?" << endl;
			cin >> m;
			cout << "How many years do you want to add?" << endl;
			cin >> y;
			day_output(day_of_calen);
			day_of_calen = add_year(day_of_calen, y);
			day_of_calen = add_month(day_of_calen, m);
			day_of_calen = add_day(day_of_calen, d);
			day_output(day_of_calen);
			menu();
			break;
		}
		case 2:
		{
			int d, m, y; //День, месяц, год
			cout << "How many days do you want to subtract?" << endl;
			cin >> d;
			cout << "How many months do you want to subtract?" << endl;
			cin >> m;
			cout << "How many years do you want to subtract?" << endl;
			cin >> y;

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
	cout << "1. Add" << endl << "2. Subtract" << endl << "0. Exit" << endl;
}

void day_output(Date d)
{
	cout << d.day << " day " << d.month << " month " << d.year << " year " << endl;
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
		if (d.day > d.MONTH[d.month-1])
		{
			d.month++;
			d.day = 1;
		}
		if (d.month > 12)
		{
			d.year++;
			d.month = 1;
			d.leap = is_leap(d);
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