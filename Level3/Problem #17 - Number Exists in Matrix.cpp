// #17/3 - Number Exists in Matrix. 
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
			arr[i][j] = RandomNumber(1, 20);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 2, arr[i][j]);

		}

		cout << "\n";
	}

}

bool IsNumberInMatrix(int matrix1[3][3],int number, short Rows, short Cols)
{

	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix1[i][j] == number)
			{
				return true;
			}
		}
	}

	return false;
}

int main()

{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int number = 0;
	cout << "\nPlease Enter the number to look for in matrix? ";
	cin >> number;

	if (IsNumberInMatrix(Matrix1, number, 3, 3))
		cout << "\nYes, it is there.\n";
	else
		cout << "\nNo, it is not there.\n";


	system("pause>0");
	return 0;
}