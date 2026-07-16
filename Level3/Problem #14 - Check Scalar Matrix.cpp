// #14/3 - Check Scalar Matrix. 
#include<iostream>
using namespace std;

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

bool IsScalarMatrix(int matrix1[3][3], short Rows, short Cols)
{
	int FirstDiagElement = matrix1[0][0];
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && matrix1[i][j] != FirstDiagElement)
			{
				return false;
			}
			else if (i != j && matrix1[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()

{

	int Matrix1[3][3] = { {6,0,0},{0,6,0},{0,0,6} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsScalarMatrix(Matrix1, 3, 3))
		cout << "\nYes, matrix is scalar.\n";
	else
		cout << "\nNo, matrix is not scalar.\n";


	system("pause>0");
	return 0;
}