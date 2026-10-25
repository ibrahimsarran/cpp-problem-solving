// #61/4 - Count Overlaps Days
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
	if (compareDate(period2.endDate, period1.startDate) == enCompareResult::Before ||
		compareDate(period2.startDate, period1.endDate) == enCompareResult::After)
		return false;
	else
		return true;
}

bool isDateInPeriod(stDate date, stPeriod period)
{
	return !(compareDate(date, period.startDate) == enCompareResult::Before || compareDate(date, period.endDate) == enCompareResult::After);
}

void swapDates(stDate& date1, stDate& date2)
{
	stDate temp;
	temp.day = date1.day;
	temp.month = date1.month;
	temp.year = date1.year;

	date1.day = date2.day;
	date1.month = date2.month;
	date1.year = date2.year;

	date2.day = temp.day;
	date2.month = temp.month;
	date2.year = temp.year;
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

bool isLastDayInAMonth(stDate date)
{
	return (date.day == numberOfDaysInAMonth(date.month, date.year));
}

bool isLastMonthInAYear(short month)
{
	return month == 12;
}

stDate increaseDateByOneDay(stDate date)
{
	if (isLastDayInAMonth(date))
	{
		if (isLastMonthInAYear(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else
		{
			date.day = 1;
			date.month++;
		}
	}
	else
	{
		date.day++;
	}
	return date;
}

short differenceInDays(stDate date1, stDate date2, bool includeEndDay = false)
{
	short days = 0;
	short swapFlagValue = 1;

	if (!isDate1BeforeDate2(date1, date2))
	{
		swapDates(date1, date2);
		swapFlagValue = -1;
	}
	while (isDate1BeforeDate2(date1, date2))
	{
		days++;
		date1 = increaseDateByOneDay(date1);
	}
	return includeEndDay ? ++days * swapFlagValue : days * swapFlagValue;
}

short periodLengthInDays(stPeriod period, bool includeEndDay = false)
{
	return differenceInDays(period.startDate, period.endDate, includeEndDay);
}

int countOverlapsDays(stPeriod period1, stPeriod period2)
{
	int period1Length = periodLengthInDays(period1, true);
	int period2Length = periodLengthInDays(period2, true);
	int overlapsDays = 0;

	if (!isOverLapsPeriods(period1, period2))
		return 0;

	if (period1Length < period2Length)
	{
		while (isDate1BeforeDate2(period1.startDate, period1.endDate))
		{
			if (isDateInPeriod(period1.startDate, period2))
				overlapsDays++;
			period1.startDate = increaseDateByOneDay(period1.startDate);
		}
		
		if (isDateInPeriod(period1.startDate, period2))
			overlapsDays++;
	}
	else
	{
		while (isDate1BeforeDate2(period2.startDate, period2.endDate))
		{
			if (isDateInPeriod(period2.startDate, period1))
				overlapsDays++;
			period2.startDate = increaseDateByOneDay(period2.startDate);
		}

		if (isDateInPeriod(period2.startDate, period1))
			overlapsDays++;
	}

	return overlapsDays;
}

int main()
{
	cout << "Enter Period1:\n";
	stPeriod period1 = readPeriod();

	cout << "Enter Period2:\n";
	stPeriod period2 = readPeriod();

	cout << "Overlaps days count is: " << countOverlapsDays(period1, period2) << endl;

	system("pause>0");
	return 0;
}