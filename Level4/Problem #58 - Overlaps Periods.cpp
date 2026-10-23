// #58/4 - Overlaps Periods
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

bool isOverLapsPeriods(stPeriod period1, stPeriod period2)
{
	if
		(
			compareDate(period2.endDate, period1.startDate) == enCompareResult::Before
			||
			compareDate(period2.startDate, period1.endDate) == enCompareResult::After
		)
		return false;
	else
		return true;
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriod period1 = readPeriod();

	cout << "Enter Period2:\n";
	stPeriod period2 = readPeriod();

	if (isOverLapsPeriods(period1, period2))
		cout << "\nYes, Periods Overlap\n";
	else
		cout << "\nNo, Periods is not Overlap\n";

	system("pause>0");
	return 0;
}
