// #55/4 - Calculate Vacation Return Date
#include <iostream>
using namespace std;

const short Friday = 5;
const short Saturday = 6;

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

short readVacationDays()
{
	short days = 0;
	cout << "\nPlease enter vacation days? ";
	cin >> days;
	return days;
}

bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short numberOfDaysInAYear(short year)
{
	return isLeapYear(year) ? 366 : 365;
}

short numberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month > 12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short dayOfWeekOrder(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

short dayOfWeekOrder(stDate date)
{
	return dayOfWeekOrder(date.day, date.month, date.year);
}

string getDayName(short dayOrder)
{
	string arrDays[] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday" };
	return arrDays[dayOrder];
}

bool isWeekEnd(stDate date)
{
	short dayOrder = dayOfWeekOrder(date);
	return (dayOrder == Friday || dayOrder == Saturday);
}

bool isBusinessDay(stDate date)
{
	return !isWeekEnd(date);
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

stDate calculateVacationReturnDate(stDate date, short actualVacactionDays)
{
	while (actualVacactionDays>0)
	{
		if (isBusinessDay(date))
		{
			actualVacactionDays--;
		}
		date = increaseDateByOneDay(date);
	}
	while(isWeekEnd(date))
		date = increaseDateByOneDay(date);

	return date;
}

int main()
{
	cout << "Vacation starts:\n";
	stDate date = readFullDate();

	short vacationDays = readVacationDays();
	stDate returnDate = calculateVacationReturnDate(date, vacationDays);
	
	cout << "\nReturn Date: " << getDayName(dayOfWeekOrder(returnDate)) << " , " << returnDate.day << "/" << returnDate.month << "/" << returnDate.year;

	system("pause>0");
	return 0;
}