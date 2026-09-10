// #16/4 - Increase Date by One Day
#include <iostream>
using namespace std;

struct stDate
{
	short day;
	short month;
	short year;
};

short readYear()
{
	short year = 0;
	cout << "Please enter a year? ";
	cin >> year;
	return year;
}

short readMonth()
{
	short month = 0;
	cout << "Please enter a month? ";
	cin >> month;
	return month;
}

short readDay()
{
	short day = 0;
	cout << "Please enter a day? ";
	cin >> day;
	return day;
}

bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short numberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

stDate readFullDate()
{
	stDate date;

	date.day = readDay();
	date.month = readMonth();
	date.year = readYear();
	cout << endl;
	return date;
}

bool isLastDayInAMonth(stDate date)
{
	return (date.day == numberOfDaysInAMonth(date.month, date.year));
}

bool isLastMonthInAYear(short month)
{
	return month == 12;
}


stDate increaseDateByOneDay(stDate date)
{
	if (isLastDayInAMonth(date))
	{
		if (isLastMonthInAYear(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else
		{
			date.day = 1;
			date.month++;
		}
	}
	else
	{
		date.day++;
	}

	return date;
}

int main()
{

	stDate date = readFullDate();
	date = increaseDateByOneDay(date);

	cout << "date after adding one day is: " << date.day << "/" << date.month << "/" << date.year;

	system("pause>0");
	return 0;
}