//Problem #42 - Task Duration In Seconds
#include <iostream>
#include <string>

using namespace std;


struct stTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int readPositiveNumber(string message)
{
	int number = 0;

	do
	{
		cout << message << endl;
		cin >> number;
	} while (number < 0);

	return number;
}

stTaskDuration readTaskDuration()
{
	stTaskDuration taskDuration;

	taskDuration.NumberOfDays = readPositiveNumber("Please Enter Number Of Days?");
	taskDuration.NumberOfHours = readPositiveNumber("Please Enter Number Of Hours?");
	taskDuration.NumberOfMinutes = readPositiveNumber("Please Enter Number Of Minutes?");
	taskDuration.NumberOfSeconds = readPositiveNumber("Please Enter Number Of Seconds?");

	return taskDuration;
}

int taskDurationInSeconds(stTaskDuration taskDuration)
{
	int durationInSeconds = 0;

	durationInSeconds = taskDuration.NumberOfDays * 24 * 60 * 60;
	durationInSeconds += taskDuration.NumberOfHours * 60 * 60;
	durationInSeconds += taskDuration.NumberOfMinutes * 60;
	durationInSeconds += taskDuration.NumberOfSeconds;

	return durationInSeconds;
}
void printTotalSeconds(int totalSeconds)
{
	cout << "\nTask Duration In Seconds: " << totalSeconds << endl;
}

int main()
{
	printTotalSeconds(taskDurationInSeconds(readTaskDuration()));

	return 0;
}
