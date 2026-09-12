// #18/4 - Your Age in Days
#pragma warning(disable : 4996)
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

short numberOfTotalDaysFromBeginningOfYear(short day, short month, short year)
{
	short totalDays = 0;
	for (short i = 1;i < month; i++)
	{
		totalDays += numberOfDaysInAMonth(i, year);
	}

	totalDays += day;

	return totalDays;
}

bool isDate1BeforeDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) ? true : ((date1.year ==
		date2.year) ? (date1.month < date2.month ? true : (date1.month ==
			date2.month ? date1.day < date2.day : false)) : false);
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
	while (isDate1BeforeDate2(date1, date2))
	{
		days++;
		date1 = increaseDateByOneDay(date1);
	}

	return includeEndDay ? ++days : days;

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

stDate getSystemDate()
{
	stDate date;

	time_t t = time(0);
	tm* now = localtime(&t);
	date.day = now->tm_mday;
	date.month = now->tm_mon + 1;
	date.year = now->tm_year + 1900;

	return date;

}

int main()
{
	cout << "Please Enter Your Date of Brith:\n\n";
	stDate date = readFullDate();
	stDate systemDate = getSystemDate();
	
	cout << "\nYour age is: " << differenceInDays(date, systemDate) <<" Day(s)";

	system("pause>0");
	return 0;
}