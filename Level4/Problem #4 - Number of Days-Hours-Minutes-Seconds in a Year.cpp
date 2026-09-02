// #4/4 - Number of Days-Hours-Minutes-Seconds in a Year

#include <iostream>
using namespace std;

short ReadYear()
{
	short year = 0;
	cout << "Please enter a year to check? ";
	cin >> year;

	return year;
}

bool IsLeapYear(short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

short NumberOfDaysInYear(short year)
{
	return IsLeapYear(year) ? 366 : 365;
}

short NumberOfHoursInYear(short year)
{
	return NumberOfDaysInYear(year) * 24;
}

int NumberOfMinutesInYear(short year)
{

	return NumberOfHoursInYear(year) * 60;
}

int NumberOfSecondsInYear(short year)
{
	return NumberOfMinutesInYear(year) * 60;
}

int main()
{
	short Year = ReadYear();
	cout << "\nNumber of Days in Year [" << Year << "] is " << NumberOfDaysInYear(Year);

	cout << "\nNumber of Hours in Year [" << Year << "] is " << NumberOfHoursInYear(Year);

	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);

	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfSecondsInYear(Year);





	system("pause>0");
	return 0;
}