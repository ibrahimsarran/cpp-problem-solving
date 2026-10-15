// #54/4 - Calculate Vacation Days
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


short dayOfWeekOrder(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string getDayName(short dayOrder)

{
	string arrDays[] = { "Sunday","Monday", "Tuesday", "Wednesday", "Thursday","Friday","Saturday" };

	return arrDays[dayOrder];
}
short dayOfWeekOrder(stDate date)
{
	return dayOfWeekOrder(date.day, date.month, date.year);
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
	if (month < 1 || month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
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

short CalculateActualVacationDays(stDate date1, stDate date2)
{
	short daysCounter = 0;
	while (isDate1BeforeDate2(date1, date2))
	{

		if (isBusinessDay(date1))
			daysCounter++;


		date1 = increaseDateByOneDay(date1);

	}
	return daysCounter;
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
	cout << "Vacation starts:\n";
	stDate date1 = readFullDate();

	cout << "Vacation ends:\n";
	stDate date2 = readFullDate();
	
	cout << "Vacation from: " << getDayName(dayOfWeekOrder(date1))<<" , " << date1.day << "/" << date1.month << "/" << date1.year << endl;
	cout << "Vacation to: " << getDayName(dayOfWeekOrder(date2)) << " , " << date2.day << "/" << date2.month << "/" << date2.year << endl;


	cout << "\n\nActual Vacation days is: " << CalculateActualVacationDays(date1, date2);

	system("pause>0");
	return 0;
}