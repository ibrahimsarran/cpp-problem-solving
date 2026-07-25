// #8/3 - Multiply Two Matrices. 
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

void MultiplyMatrices(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{

		for (short j = 0; j < Cols; j++)
		{
			MatrixResult[i][j] = Matrix1[i][j] * Matrix2[i][j];

		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{

		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d",2,arr[i][j]);
			cout << "   ";
				
		}

		cout << "\n";
	}

}


int main()

{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];
	int MatrixResult[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	MultiplyMatrices(Matrix1, Matrix2, MatrixResult, 3, 3);
	cout << "\nResult:\n";
	PrintMatrix(MatrixResult, 3, 3);

	return 0;
}