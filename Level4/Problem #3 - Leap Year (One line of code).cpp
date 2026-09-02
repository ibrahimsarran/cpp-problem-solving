// #3/4 - Leap Year (One line of code)

#include <iostream>
using namespace std;

short  ReadYear()
{
	short year = 0;
	cout << "Please enter a year? ";
	cin >> year;

	return year;
}

bool IsLeapYear(short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}


int main()
{
	short year = ReadYear();

	if (IsLeapYear(year))
	{
		cout << "Yes, year [" << year << "] is a leap year\n";

	}

	else
		cout << "No, year [" << year << "] is not a leap year\n";


	system("pause>0");
	return 0;
}