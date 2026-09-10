// #6/4 - Number of Days-Hours-Minutes-Seconds in a Month (Optimized)

#include <iostream>
using namespace std;

short readYear()
{
	short year = 0;
	cout << "Please enter a year to check? ";
	cin >> year;

	return year;
}

short readMonth()
{
	short month = 0;
	cout << "\nPlease enter a month to check? ";
	cin >> month;

	return month;
}

bool IsLeapYear(short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
} 

short numberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short numberOfHoursInAMonth(short month, short year)
{
	return numberOfDaysInAMonth(month, year) * 24;
}

int numberOfMinutesInAMonth(short month, short year)
{
	return numberOfHoursInAMonth(month, year) * 60;
}

int numberOfSecondsInAMonth(short month, short year)
{
	return numberOfMinutesInAMonth(month, year) * 60;
}


int main()
{
	short year = readYear();
	short month = readMonth();

	cout << "\nNumber of Days in Month [" << month << "] is "
		<< numberOfDaysInAMonth(month, year);
	cout << "\nNumber of Hours in Month [" << month << "] is "
		<< numberOfHoursInAMonth(month, year);
	cout << "\nNumber of Minutes in Month [" << month << "] is "
		<< numberOfMinutesInAMonth(month, year);
	cout << "\nNumber of Seconds in Month [" << month << "] is "
		<< numberOfSecondsInAMonth(month, year);

	system("pause>0");
	return 0;
}