// #12/3 - Check Typical Matrices. 
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
			printf("%0*d   ", 2, arr[i][j]);

		}

		cout << "\n";
	}

}

bool AreMatricesTypical(int matrix1[3][3], int matrix2[3][3], short Rows, short Cols)
{

	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
				return false;
		}
	}

	return true;
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

	if (AreMatricesTypical(Matrix1, Matrix2, 3, 3))
		cout << "\nYes, both Matrices are typical.\n";
	else
		cout << "\nNo, both Matrices are not typical.\n";


	system("pause>0");
	return 0;
}