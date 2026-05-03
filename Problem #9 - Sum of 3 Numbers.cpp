//Problems #9 - Sum of 3 Numbers
#include <iostream>
using namespace std;
void readNumbers(int& num1, int& num2, int& num3)
{
	cout << "enter n1" << endl;
	cin >> num1;
	cout << "enter n2" << endl;
	cin >> num2;
	cout << "enter n3" << endl;
	cin >> num3;
}
int sumOf3Numbers(int num1, int num2, int num3)

{
	return num1 + num2 + num3;
}
void printSumOfNumbers(int Total)
{
	cout << "The total is: " << Total;
}
int main()
{
	int num1, num2, num3;
	readNumbers(num1, num2, num3);
	printSumOfNumbers(sumOf3Numbers(num1, num2, num3));
	return 0;



}

