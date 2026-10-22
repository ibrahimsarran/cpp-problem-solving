// #47-53/4 - Date Problems
#include <iostream>
using namespace std;

const short Friday = 5;
const short Saturday = 6;


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


short dayOfWeekOrder(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string getDayName(short dayOrder)

{
	string arrDays[] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday" };

	return arrDays[dayOrder];
}
short dayOfWeekOrder(stDate date)
{
	return dayOfWeekOrder(date.day, date.month, date.year);
}

bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short numberOfDaysInAYear(short year)
{
	return isLeapYear(year) ? 366 : 365;
}

short numberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short numberOfTotalDaysFromBeginningOfYear(short day, short month, short year)
{
	short totalDays = 0;
	for (short i = 1;i < month; i++)
	{
		totalDays += numberOfDaysInAMonth(i, year);
	}

	totalDays += day;

	return totalDays;
}

bool isEndOfWeek(stDate date)
{
	return dayOfWeekOrder(date) == Saturday;
}

bool isWeekEnd(stDate date)
{
	short dayOrder = dayOfWeekOrder(date);
	return (dayOrder == Friday || dayOrder == Saturday);
}

bool isBusinessDay(stDate date)
{
	return !isWeekEnd(date);
}

short daysUntilEndOfWeek(stDate date)
{
	return Saturday - dayOfWeekOrder(date);
}
short daysUntilEndOfMonth(stDate date)
{
	return numberOfDaysInAMonth(date.month, date.year) - date.day + 1;
}
short daysUntilEndOfYear(stDate date)
{
	return numberOfDaysInAYear(date.year)
		- numberOfTotalDaysFromBeginningOfYear(date) + 1;
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

int main()
{
	stDate date = readFullDate();
	
	system("pause>0");
	return 0;
}