// // #2/4 - Is a Leap Year?

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
	if (year % 400 == 0)
	{
		return true;
	}

	else if (year % 100 == 0)
	{
		return false;
	}
	else if (year % 4 == 0)
	{
		return true;
	}

	else
		return false;
	
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