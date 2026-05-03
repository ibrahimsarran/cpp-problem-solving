//Problem #12 - Max of 2 Numbers
#include <iostream>
using namespace std;

void readNumbers(int& number1, int& number2)
{
	cout << "Enter number 1: ";
	cin >> number1;
	cout << "Enter number 2: ";
	cin >> number2;
	
}
int max(int number1, int number2)
{
	if (number1 > number2)
		return number1;
	else
		return number2;
}
void printResult(int max)
{
	cout << "Max number is:" << max << endl;
}
int main()
{
	int num1, num2;
	readNumbers(num1, num2);
	printResult(max(num1, num2));

	return 0;
}

