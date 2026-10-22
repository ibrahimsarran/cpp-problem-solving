// #56/4 - Is Date1 After Date2
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

stDate readFullDate()
{
	stDate date;
	date.day = readDay();
	date.month = readMonth();
	date.year = readYear();
	cout << endl;
	return date;
}

bool isDate1BeforeDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) ? true : ((date1.year ==
		date2.year) ? (date1.month < date2.month ? true : (date1.month ==
			date2.month ? date1.day < date2.day : false)) : false);
}

bool isDate1EqualDate2(stDate date1, stDate date2)
{
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}

bool isDate1AfterDate2(stDate date1, stDate date2)
{
	return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualDate2(date1, date2));
}

int main()
{
	cout << "Enter Date1:\n";
	stDate date1 = readFullDate();

	cout << "Enter Date2:\n";
	stDate date2 = readFullDate();


	if (isDate1AfterDate2(date1, date2))
		cout << "\nYes, Date1 is after Date2\n";
	else
		cout << "\nNo, Date1 is not after Date2\n";



	system("pause>0");
	return 0;
}