// #18/3 - Intersected Numbers
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
			arr[i][j] = RandomNumber(1, 15);
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

bool IsNumberInMatrix(int matrix[3][3], int number, short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix[i][j] == number)
			{
				return true;
			}
		}
	}

	return false;
}

void IntersectedNumbers(int matrix1[3][3],int matrix2[3][3], short Rows, short Cols)
{
	cout << endl;
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (IsNumberInMatrix(matrix2, matrix1[i][j], Rows, Cols))
			{
				cout << matrix1[i][j] << "  ";
				
			}
		}
	}

}

int main()

{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected numbers are:\n";
	IntersectedNumbers(Matrix1, Matrix2, 3, 3);

	system("pause>0");
	return 0;
}