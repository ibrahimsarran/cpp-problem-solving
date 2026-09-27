// #20-32/4 - Increase Date Problems
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

stDate increaseDateByXDays(short days, stDate date)
{

	for (short i = 1; i <= days;i++)
	{
		date = increaseDateByOneDay(date);
	}
	return date;
}

stDate increaseDateByOneWeek(stDate date)
{
	for (short i = 1; i <= 7; i++)
	{
		date = increaseDateByOneDay(date);
	}

	return date;
}


stDate increaseDateByXWeeks(short weeks, stDate date)
{
	for (short i = 1; i <= weeks; i++)
	{
		date = increaseDateByOneWeek(date);
	}
	return date;
}

stDate increaseDateByOneMonth(stDate date)
{
	if (isLastMonthInAYear(date.month))
	{
		date.month = 1;
		date.year++;
	}
	else
	{
		date.month++;
	}

	short numberOfDaysInCureentMonth = numberOfDaysInAMonth(date.month, date.year);
	if (date.day > numberOfDaysInCureentMonth)
	{
		date.day = numberOfDaysInCureentMonth;

	}

	return date;
}

stDate increaseDateByXMonths(short months, stDate date)
{
	for (short i = 1; i <= months; i++)
	{
		date = increaseDateByOneMonth(date);
	}
	return date;
}

stDate increaseDateByOneYear(stDate date)
{
	date.year++;
	return date;
}

stDate increaseDateByXYears(short years, stDate date)
{
	for (short i = 1; i <= years; i++)
	{
		date = increaseDateByOneYear(date);

	}
	return date;
}

stDate increaseDateByXYearsFaster(short years, stDate date)
{

	date.year += years;
	return date;
}

stDate increaseDateByOneDecade(stDate date)
{
	date.year += 10;
	return date;
}

stDate increaseDateByXDecades(short decade, stDate date)
{
	for (short i = 1; i <= decade * 10;i++)
	{
		date = increaseDateByOneYear(date);
		
	}
	return date;
}

stDate increaseDateByXDecadesFaster(short decade, stDate date)
{
	date.year += decade * 10;
	return date;
}

stDate increaseDateByOneCentury(stDate date)
{
	date.year += 100;
	return date;
}

stDate increaseDateByOneMillennium(stDate date)
{
	date.year += 1000;
	return date;
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

int main()
{
	stDate date = readFullDate();
	cout << "Date After:\n\n";
	date = increaseDateByOneDay(date);
	cout << "01-Adding one Day is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXDays(10, date);
	cout << "\n02-Adding 10 Days is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByOneWeek(date);
	cout << "\n03-Adding one Week is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXWeeks(10, date);
	cout << "\n04-Adding 10 Weeks is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByOneMonth(date);
	cout << "\n05-Adding one Month is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXMonths(5, date);
	cout << "\n06-Adding 10 Months is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByOneYear(date);
	cout << "\n07-Adding one Year is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXYears(10, date);
	cout << "\n08-Adding 10 Years is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXYearsFaster(10, date);
	cout << "\n09-Adding 10 Years (Faster) is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByOneDecade(date);
	cout << "\n010-Adding one Decade is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXDecades(10, date);
	cout << "\n11-Adding 10 Decades is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByXDecadesFaster(10, date);
	cout << "\n12-Adding 10 Decades (Faster) is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByOneCentury(date);
	cout << "\n13-Adding one Century is: "
		<< date.day << "/" << date.month << "/" << date.year;
	date = increaseDateByOneMillennium(date);
	cout << "\n14-Adding one Millennium is: "
		<< date.day << "/" << date.month << "/" << date.year;




	system("pause>0");
	return 0;
}