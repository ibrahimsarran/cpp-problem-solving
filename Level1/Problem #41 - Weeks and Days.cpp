//Problem #41 - Weeks and Days

#include <iostream>
#include <string>

using namespace std;

const int HOURS_IN_DAY = 24;
const int DAYS_IN_WEEK = 7;

float readPositiveNumber(string message)
{
	float number = 0;
	do
	{
		cout << message;
		cin >> number;

	} while (number <= 0);
	
	return number;

}

float hoursToDays(float hours)
{
	return hours / HOURS_IN_DAY;

}
float hoursToWeeks(float hours)

{
	return hours / (HOURS_IN_DAY * DAYS_IN_WEEK);

}
void printTotal(float hours, float days, float weeks)
{
	cout << "Hours = " << hours << endl;
	cout << "Days = " << days << endl;
	cout << "Weeks = " << weeks << endl;
}
int main()
{
	
	float numberOfHours = readPositiveNumber("Enter the number of hours: ");
	float numberOfDays = hoursToDays(numberOfHours);
	float numberOfWeeks = hoursToWeeks(numberOfHours);
	printTotal(numberOfHours, numberOfDays, numberOfWeeks);

	return 0;

}

