// #9/3 - Print Middle Row and Col of Matrix. 
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

void PrintMiddleRow(int arr[3][3], short Rows, short Cols)
{
	
		short MiddleRow = Rows / 2;

		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 2, arr[MiddleRow][j]);

		}

		cout << "\n";
	}

void PrintMiddleCol(int arr[3][3], short Rows, short Cols)
{
		
	short MiddleCol = Cols / 2;
		for (short i = 0; i < Rows; i++)
		{
			printf("%0*d   ", 2, arr[i][MiddleCol]);

		}

		cout << "\n";
	}

int main()

{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	
	
	cout << "\nMiddle row of Matrix1:\n";
	PrintMiddleRow(Matrix1, 3, 3);

	cout << "\nMiddle column of Matrix1:\n";
	PrintMiddleCol(Matrix1, 3, 3);


	return 0;
}