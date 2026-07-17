// #16/3 - Check Sparce Matrix. 
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
			arr[i][j] = RandomNumber(0, 10);
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

int CountNumberInMatrix(int matrix1[3][3], int number, short Rows, short Cols)
{
	int counter = 0;

	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix1[i][j] == number)
				counter++;
		}
	}

	return counter;
}

bool IsSparceMatrix(int matrix1[3][3], short Rows, short Cols)

{
	short MatrixSize = Rows * Cols;
	return (CountNumberInMatrix(matrix1, 0, 3, 3) >= (MatrixSize / 2));
}

int main()

{
	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << (IsSparceMatrix(Matrix1, 3, 3) ? "\nYes, matrix is sparce.\n" : "\nNo, matrix is not sparce.\n");

	system("pause>0");
	return 0;
}