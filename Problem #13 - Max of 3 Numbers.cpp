//Problem #13 - Max of 3 Numbers
#include <iostream>
using namespace std;

void readNumbers(int& number1, int& number2, int& number3)
{
	cout << "Enter number 1: ";
	cin >> number1;
	cout << "Enter number 2: ";
	cin >> number2;
	cout << "Enter number 3: ";
	cin >> number3;

}
int maxOfTwo(int number1, int number2)
{
	if (number1 > number2)
		return number1;
	else
		return number2;
}
int maxOfThree(int number1, int number2, int number3)
{
	return maxOfTwo(maxOfTwo(number1, number2), number3);
}
void printResult(int max)
{
	cout << "Max number is:" << max << endl;
}
int main()
{
	int num1, num2, num3;
	readNumbers(num1, num2, num3);
	printResult(maxOfThree(num1, num2,num3));

	return 0;
}

