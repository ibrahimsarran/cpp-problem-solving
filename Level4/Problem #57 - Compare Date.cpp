// #57/4 - Compare Date
#include <iostream>
using namespace std;

enum enCompareResult { Before = -1, Equal = 0, After = 1 };

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

bool isDate1BeforeDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) ? true : ((date1.year ==
		date2.year) ? (date1.month < date2.month ? true : (date1.month ==
			date2.month ? date1.day < date2.day : false)) : false);
}

bool isDate1EqualDate2(stDate date1, stDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}

enCompareResult compareDate(stDate date1, stDate date2)
{
	return (isDate1BeforeDate2(date1, date2) ? enCompareResult::Before
		: isDate1EqualDate2(date1,date2) ? enCompareResult::Equal
		: enCompareResult::After);
}

int main()
{
	cout << "Enter Date1:\n";
	stDate date1 = readFullDate();

	cout << "Enter Date2:\n";
	stDate date2 = readFullDate();

	cout << "Compare Result = " << compareDate(date1, date2) << endl;


	system("pause>0");
	return 0;
}