// #14/4 - Date1 Equal to Date2
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


bool IsDate1EqualDate2(stDate date1, stDate date2)
{
	return (date1.year == date2.year) ? ((date1.month ==date2.month) ? ((date1.day == date2.day) ? true : false): false) : false;
}


int main()
{
	
	stDate date1 = readFullDate();
	stDate date2 = readFullDate();

	if (IsDate1EqualDate2(date1, date2))
		cout << "\nYes, Date1 is equal to Date2.";
	else
		cout << "\nNo, Date1 is not equal to Date2.";

	system("pause>0");
	return 0;
}