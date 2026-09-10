// #9/4 - Year Calender
#include <iostream>
using namespace std;

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
	do
	{
		cout << "\nPlease enter a month? ";
		cin >> month;

	} while (month < 1 || month>12);

	return month;

}


bool isLeapYear(short year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

short numberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short dayOrder(short day, short month, short year)
{
	short a = (14 - month) / 12;
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}


string getMonthName(short month)

{
	string arrMonths[] = { "Jan","Feb", "Mar", "Apr", "May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	return arrMonths[month - 1];
}

void printMonthCalender(short month, short year)
{
	short numberOfDays;

	short current = dayOrder(1, month, year);
	numberOfDays = numberOfDaysInAMonth(month, year);

	printf("\n  ---------------%s-------------\n\n",
	getMonthName(month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short i;
	for (i = 0; i < current; i++)
		printf("     ");
	

	for (short j = 1; j <= numberOfDays; j++)
	{
		printf("%5d", j);


		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	
	printf("\n  _________________________________\n");
}

void printYearCalender(short year)
{
	printf("\n  ---------------------------------\n\n");
	printf("           Calender - %d\n", year);
	printf("\n  ---------------------------------\n\n");

	for (short i = 1; i <= 12;i++)
	{
		printMonthCalender(i, year);
	}
}

int main()
{
	short year = readYear();
	
	printYearCalender(year);

	system("pause>0");
	return 0;
}