// #7/3 - 3x3 Transposed Matrix 
#include<iostream>
#include<iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	short counter = 0;
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols;j++)
		{
			counter++;
			arr[i][j] = counter;
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{

		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";
		}

		cout << "\n";
	}

}

void TransposedMatrix(int arr[3][3],int arrTransposed[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}

		cout << "\n";
	}

}

int main()

{
	int arr[3][3];
	int arrTransposed[3][3];
	FillMatrixWithOrderedNumbers(arr, 3, 3);
	cout << "\nThe following is the ordered 3x3 matrix:\n";
	PrintMatrix(arr, 3, 3);

	TransposedMatrix(arr,arrTransposed,3,3);

	cout << "\nThe following is the Transpos matrix:\n";
	PrintMatrix(arrTransposed, 3, 3);

	return 0;
}