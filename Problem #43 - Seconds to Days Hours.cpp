//Problem #43 - Seconds to Days Hours Minutes Seconds
#include <iostream>
#include <string>

using namespace std;

struct stTaskDuration
{
    int numberOfDays, numberOfHours, numberOfMinutes, numberOfSeconds;
};

int readPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

stTaskDuration secondsToTaskDuration(int totalSeconds)
{
	stTaskDuration taskDuration;
	const int secondsPerDay = 24 * 60 * 60;
	const int secondsPerHour = 60 * 60;
	const int secondsPerMinute = 60;

	int remainder = 0;
	taskDuration.numberOfDays = floor(totalSeconds / secondsPerDay);
	remainder = totalSeconds % secondsPerDay;
	taskDuration.numberOfHours = floor(remainder / secondsPerHour);
	remainder = remainder % secondsPerHour;
	taskDuration.numberOfMinutes = floor(remainder / secondsPerMinute);
	remainder = remainder % secondsPerMinute;
	taskDuration.numberOfSeconds = remainder;

	return taskDuration;
}
void printTaskDurationDetails(stTaskDuration taskDuration)
{
	cout << "\n"
		<< taskDuration.numberOfDays << " Days, "
		<< taskDuration.numberOfHours << " Hours, "
		<< taskDuration.numberOfMinutes << " Minutes, "
		<< taskDuration.numberOfSeconds << " Seconds\n";
}
int main()
{
	printTaskDurationDetails(secondsToTaskDuration(readPositiveNumber("Please enter Total seconds:")));

	return 0;


}

