// #21/3 - Fibonacci
#include<iostream>
using namespace std;

void FibonacciSeq(short n)
{
	int FibonacciNumber = 0;
	int prev2 = 0;
	int prev1 = 1;
	cout << "1  ";

	for (short i = 2; i <= n;++i)
	{
		FibonacciNumber = prev2 + prev1;
		cout << FibonacciNumber << "  ";
		prev2 = prev1;
		prev1 = FibonacciNumber;
	}
	cout << "\n";
}

int main()
{
	
	FibonacciSeq(10);


	return 0;
}