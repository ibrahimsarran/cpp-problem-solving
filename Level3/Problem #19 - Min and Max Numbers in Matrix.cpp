
// #19/3 - Min and Max Numbers in Matrix
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumbers(int matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols;j++)
		{
			matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 2, matrix[i][j]);

		}

		cout << "\n";
	}

}

int MinNumberInMatrix(int matrix[3][3], short Rows, short Cols)
{
	int min = matrix[0][0];
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix[i][j] < min)
				min = matrix[i][j];

		}
	}
	return min;
}

int MaxNumberInMatrix(int matrix[3][3], short Rows, short Cols)
{
	int max = matrix[0][0];
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix[i][j] > max)
				max = matrix[i][j];

		}
	}
	return max;
}

int main()

{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMin number is: " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
	cout << "\nMax number is: " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;


	system("pause>0");
	return 0;
}