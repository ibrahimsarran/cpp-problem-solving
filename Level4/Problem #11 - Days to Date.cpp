// #11/4 - Days to Date

#include <iostream>
using namespace std;

struct stDate
{
	short day;
	short month;
	short year;
};

bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short readYear()
{
	short year = 0;
	cout << "\nPlease enter a year? ";
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
	cout << "Please enter a day? ";
	cin >> day;

	return day;
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

stDate getDateFromDayOrderInYear(short dateOrderInYear, short year)
{
	stDate date;
	short monthDays = 0;
	short remainingDays = dateOrderInYear;

	date.year = year;
	date.month = 1;


	while (true)
	{
		monthDays = numberOfDaysInAMonth(date.month, year);

		if (remainingDays > monthDays)
		{
			remainingDays -= monthDays;
			date.month++;
		}
		else
		{
			date.day = remainingDays;
			break;
		}
	}
	return date;
}


int main()
{
	short day = readDay();
	short month = readMonth();
	short year = readYear();
	short daysOrderInYear = numberOfTotalDaysFromBeginningOfYear(day, month, year);

	cout << "\nNumber of days from the beginning of the year is "
		<< daysOrderInYear << "\n\n";

	stDate date;
	date = getDateFromDayOrderInYear(daysOrderInYear, year);

	cout << "Date for [ " << daysOrderInYear << " ] is: ";
	cout << date.day << "/" << date.month << "/" << date.year;

	system("pause>0");
	return 0;
}