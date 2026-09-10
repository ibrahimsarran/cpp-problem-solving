// #7/4 - Day Name

#include <iostream>
using namespace std;

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
	cout << "\nPlease enter a month? ";
	cin >> month;

	return month;
}

short readDay()
{
	short day = 0;
	cout << "\nPlease enter a day? ";
	cin >> day;

	return day;
}

short numberOfDay(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string getDayName(short dayOrder)

{
	string arrDays[] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday"};

	return arrDays[dayOrder];
}

int main()
{
	short year = readYear();
	short month = readMonth();
	short day = readDay();
	short dayOrder = numberOfDay(day, month, year);

	cout << "\nDate        : " << day << "/" << month << "/" << year;
	cout << "\nDay Order   : " << dayOrder;
	cout << "\nDay Name    : " << getDayName(dayOrder) << endl;

	system("pause>0");
	return 0;
}