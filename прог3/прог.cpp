#include<iostream>
#include<iomanip>

using namespace std;

int Year()
{
	int year;
	cout << "Year: ";
	cin >> year;
	return year;
}
int Month()
{
	int month;
	cout << "Month: ";
	cin >> month;
	return month;
}

int February(int year)
{
	int days = 28;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		days = 29;
	return days;
}
int DaysInMonth(int month, int year)
{
	int days;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	else 
		if (month == 2)
			days = February(year);
		else days = 30;
		return days;
}
int DaysInYear(int year)
{
	int days = 365;
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		days = 366;
	return days;
}

int WeekJanuary(int year)
{
	int weekDay = 1;      //понедельник
	int days = 0;
	for (int i = 1753; i < year; i++)
		days += DaysInYear(i);
	weekDay = days % 7 + 1;
	if (weekDay > 6)
		weekDay -= 7;
	return weekDay;
}
int WeekMonth(int month, int year)
{
	int weekDay = WeekJanuary(year);
	int days = 0;
	for (int i = 1; i < month; i++)
		days += DaysInMonth(i, year);
	weekDay = days % 7 + WeekJanuary(year);
	if (weekDay > 6)
		weekDay -= 7;
	return weekDay;
}

int display(int year, int month)
{
	int weekDay = WeekMonth(month, year);
	int day = 1;
	cout << setw(4) << "Su" << setw(4) << "Mo" << setw(4) << "Tu" << setw(4) << "We" << setw(4) << "Th" << setw(4) << "Fr" << setw(4) << "Sa\n";
	if (weekDay != 0)
	{
		for (int i = 0; i < weekDay; i++)
			cout << "    ";
		for (int i = weekDay; i < 7; i++)
		{
			cout << setw(4) << day;
			day++;
		}
		cout << endl;
	}
	while (day <= DaysInMonth(month, year))
	{
		for (int i = 0; i < 7; i++)
		{
			if (day <= DaysInMonth(month, year))
			{
				cout << setw(4) << day;
				day++;
			}
			else cout << setw(4);
		}
		cout << endl;
	}
	return 0;
}

void main()
{
	int year = Year();
	int month = Month();
	display(year, month);
}