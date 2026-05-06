Problem #11 - Average Pass Fail
#include <iostream>
using namespace std;

enum enPassFail {Pass,Fail};

void readMarks(int& mark1, int& mark2, int& mark3)
{
	cout << "Enter Mark 1: ";
	cin >> mark1;
	cout << "Enter Mark 2: ";
	cin >> mark2;
	cout << "Enter Mark 3: ";
	cin >> mark3;
}
int sumOf3Numbers(int mark1, int mark2, int mark3)

{
	return mark1 + mark2 + mark3;
}
float calculateAverage(int mark1, int mark2, int mark3)
{
	return (float)sumOf3Numbers(mark1, mark2, mark3) / 3;
}
enPassFail checkAverage(float average)
{
	if (average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}
void printAverage(float average)
{
	cout << "The Average is: " << average << endl;

	if (checkAverage(average)==enPassFail::Pass)
		cout << "\n You Passed.\n";
	else
		cout << "\n You Failed.\n";


}
int main()
{
	int mark1, mark2, mark3;
	readMarks(mark1, mark2, mark3);
	printAverage(calculateAverage(mark1, mark2, mark3));
	return 0;



}

