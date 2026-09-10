// #10/4 - Days From the Beginning of Year

#include <iostream>
using namespace std;

bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short readYear()
{
	short year = 0;
	cout << "\nPlease enter a year? ";
	cin >> year;

	return year;
}

short readMonth()
{
	short month = 0;
	cout << "\nPlease enter a month? ";
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


int main()
{
	short day = readDay();
	short month = readMonth();
	short year = readYear();
	
	
	cout << "\nNumber of days from the beginning of the year is " 
		<< numberOfTotalDaysFromBeginningOfYear(day, month, year);

	system("pause>0");
	return 0;
}