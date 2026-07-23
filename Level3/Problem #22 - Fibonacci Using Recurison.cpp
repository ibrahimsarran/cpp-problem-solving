// #22/3 - Fibonacci Using Recurison
#include<iostream>
using namespace std;

void PrintFibonacciUsingRecursion(short number, int prev1, int prev2)
{
	int FibonacciNum = 0;
	if (number > 0)
	{
		FibonacciNum = prev2 + prev1;
		prev2 = prev1;
		prev1 = FibonacciNum;
		cout << FibonacciNum << "  ";
		PrintFibonacciUsingRecursion(number - 1, prev1, prev2);

	}
	
}

int main()
{

	PrintFibonacciUsingRecursion(10, 0, 1);

	return 0;
}