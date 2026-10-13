// #33-46/4 - Decrease Date Problems
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



bool isFirstDayInAMonth(stDate date)
{
	return date.day == 1;
}

bool isFirstMonthInAYear(short month)
{
	return month == 1;
}

stDate decreaseDateByOneDay(stDate date)
{
	if (isFirstDayInAMonth(date))
	{
		if (isFirstMonthInAYear(date.month))
		{
			date.day = numberOfDaysInAMonth(date.month, date.year);
			date.month = 12;
			date.year--;
		}
		else
		{
			
			date.month--;
			date.day = numberOfDaysInAMonth(date.month, date.year);
		}
	}
	else
	{
		date.day--;
	}

	return date;
}

stDate decreaseDateByXDays(short days, stDate date)
{

	for (short i = 1; i <= days;i++)
	{
		date = decreaseDateByOneDay(date);
	}
	return date;
}

stDate decreaseDateByOneWeek(stDate date)
{
	for (short i = 1; i <= 7; i++)
	{
		date = decreaseDateByOneDay(date);
	}

	return date;
}


stDate decreaseDateByXWeeks(short weeks, stDate date)
{
	for (short i = 1; i <= weeks; i++)
	{
		date = decreaseDateByOneWeek(date);
	}
	return date;
}

stDate decreaseDateByOneMonth(stDate date)
{
	if (isFirstMonthInAYear(date.month))
	{
		date.month = 12;
		date.year--;
	}
	else
	{
		date.month--;
	}

	short numberOfDaysInCureentMonth = numberOfDaysInAMonth(date.month, date.year);
	if (date.day > numberOfDaysInCureentMonth)
	{
		date.day = numberOfDaysInCureentMonth;

	}

	return date;
}

stDate decreaseDateByXMonths(short months, stDate date)
{
	for (short i = 1; i <= months; i++)
	{
		date = decreaseDateByOneMonth(date);
	}
	return date;
}

stDate decreaseDateByOneYear(stDate date)
{
	date.year--;
	short numberOfDaysInCureentMonth = numberOfDaysInAMonth(date.month, date.year);

	if (date.day > numberOfDaysInCureentMonth)
	{
		date.day = numberOfDaysInCureentMonth;
	}
	return date;
}

stDate decreaseDateByXYears(short years, stDate date)
{
	for (short i = 1; i <= years; i++)
	{
		date = decreaseDateByOneYear(date);

	}
	return date;
}

stDate decreaseDateByXYearsFaster(short years, stDate date)
{

	date.year -= years;
	return date;
}

stDate decreaseDateByOneDecade(stDate date)
{
	date.year -= 10;
	return date;
}

stDate decreaseDateByXDecades(short decade, stDate date)
{
	for (short i = 1; i <= decade * 10;i++)
	{
		date = decreaseDateByOneYear(date);
		
	}
	return date;
}

stDate decreaseDateByXDecadesFaster(short decade, stDate date)
{
	date.year -= decade * 10;
	return date;
}

stDate decreaseDateByOneCentury(stDate date)
{
	date.year -= 100;
	return date;
}

stDate decreaseDateByOneMillennium(stDate date)
{
	date.year -= 1000;
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

	date = decreaseDateByOneDay(date);
	cout << "01-Subtracting one Day is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXDays(10, date);
	cout << "\n02-Subtracting 10 Days is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByOneWeek(date);
	cout << "\n03-Subtracting one Week is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXWeeks(10, date);
	cout << "\n04-Subtracting 10 Weeks is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByOneMonth(date);
	cout << "\n05-Subtracting one Month is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXMonths(5, date);
	cout << "\n06-Subtracting 5 Months is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByOneYear(date);
	cout << "\n07-Subtracting one Year is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXYears(10, date);
	cout << "\n08-Subtracting 10 Years is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXYearsFaster(10, date);
	cout << "\n09-Subtracting 10 Years (Faster) is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByOneDecade(date);
	cout << "\n10-Subtracting one Decade is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXDecades(10, date);
	cout << "\n11-Subtracting 10 Decades is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByXDecadesFaster(10, date);
	cout << "\n12-Subtracting 10 Decades (Faster) is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByOneCentury(date);
	cout << "\n13-Subtracting one Century is: "
		<< date.day << "/" << date.month << "/" << date.year;

	date = decreaseDateByOneMillennium(date);
	cout << "\n14-Subtracting one Millennium is: "
		<< date.day << "/" << date.month << "/" << date.year;



	system("pause>0");
	return 0;
}