// #10/3 - Sum of Matrix
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols;j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{

		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d   ",2,arr[i][j]);
			
		}

		cout << "\n";
	}

}

int SumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			sum += arr[i][j];

		}
	}

	return sum;
}

int main()

{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of martix1 is = " << SumOfMatrix(Matrix1, 3, 3) << endl;
	
	


	return 0;
}