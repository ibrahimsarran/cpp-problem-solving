// #5/4 - Number of Days-Hours-Minutes-Seconds in a Month

#include <iostream>
using namespace std;

short ReadYear()
{
	short year = 0;
	cout << "Please enter a year to check? ";
	cin >> year;

	return year;
}

short ReadMonth()
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

short NumberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;

	if (month == 2)
		return IsLeapYear(year) ? 29 : 28;

	short arr31Days[] = { 1,3,5,7,8,10,12 };

	for (short i = 1; i <= 7;i++)
	{
		if (arr31Days[i - 1] == month)
			return 31;
	}

	return 30;
}

short NumberOfHoursInAMonth(short month, short year)
{
	return NumberOfDaysInAMonth(month, year) * 24;
}

int NumberOfMinutesInAMonth(short month, short year)
{
	return NumberOfHoursInAMonth(month, year) * 60;
}

int NumberOfSecondsInAMonth(short month, short year)
{
	return NumberOfMinutesInAMonth(month, year) * 60;
}


int main()
{
	short year = ReadYear();
	short month = ReadMonth();

	cout << "\nNumber of Days in Month [" << month << "] is "
		<< NumberOfDaysInAMonth(month, year);
	cout << "\nNumber of Hours in Month [" << month << "] is "
		<< NumberOfHoursInAMonth(month, year);
	cout << "\nNumber of Minutes in Month [" << month << "] is "
		<< NumberOfMinutesInAMonth(month, year);
	cout << "\nNumber of Seconds in Month [" << month << "] is "
		<< NumberOfSecondsInAMonth(month, year);

	system("pause>0");
	return 0;
}