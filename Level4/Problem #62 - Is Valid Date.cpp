// #62/4 - Is Valid Date
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

stDate readFullDate()
{
	stDate date;
	date.day = readDay();
	date.month = readMonth();
	date.year = readYear();
	cout << endl;
	return date;
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


bool isValidDate(stDate date)
{
	if (date.day < 1 || date.day > numberOfDaysInAMonth(date.month, date.year))
		return false;

	if (date.month < 1 || date.month > 12)
		return false;

	else
		return true;
	
}
int main()
{
	stDate date = readFullDate();

	if (isValidDate(date))
		cout << "\nYes, Date is valid";
	else
		cout << "\nNo, Date is not valid";

	system("pause>0");
	return 0;
}