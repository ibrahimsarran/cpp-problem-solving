// #60/4 - Is Date in Period 
#include <iostream>
using namespace std;

enum enCompareResult { Before = -1, Equal = 0, After = 1 };

struct stDate
{
	short day;
	short month;
	short year;
};

struct stPeriod
{
	stDate startDate;
	stDate endDate;
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

stPeriod readPeriod()
{
	stPeriod period;
	cout << "Enter Start Date:\n";
	period.startDate = readFullDate();
	cout << "Enter End Date:\n";
	period.endDate = readFullDate();

	return period;
}

bool isDate1BeforeDate2(stDate startDate, stDate endDate)
{
	return (startDate.year < endDate.year) ? true : ((startDate.year ==
		endDate.year) ? (startDate.month < endDate.month ? true : (startDate.month ==
			endDate.month ? startDate.day < endDate.day : false)) : false);
}

bool isDate1EqualDate2(stDate startDate, stDate endDate)
{
	return (startDate.year == endDate.year) ? ((startDate.month == endDate.month) ? ((startDate.day == endDate.day) ? true : false) : false) : false;
}

enCompareResult compareDate(stDate date1, stDate date2)
{
	return (isDate1BeforeDate2(date1, date2) ? enCompareResult::Before
		: isDate1EqualDate2(date1, date2) ? enCompareResult::Equal
		: enCompareResult::After);
}

bool isDateInPeriod(stDate date, stPeriod period)

{
	return !(compareDate(date, period.startDate) == enCompareResult::Before
		||
		compareDate(date, period.endDate) == enCompareResult::After);
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriod period1 = readPeriod();

	cout << "\nEnter date to check:\n";
	stDate date = readFullDate();

	if (isDateInPeriod(date, period1))
		cout << "\nYes";
	else
		cout << "\nNo";



	system("pause>0");
	return 0;
}
