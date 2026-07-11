// #3/3 - Sum Each Row in Matrix in Array

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void GenerateTwoDimArray(int arr[3][3],short Rows, short Cols)
{
	
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols;j++)
		{
			arr[i][j] = RandomNumber(1,100);
		}
	}
}

void PrintTwoDimArray(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe following is a 3x3 random matrix:\n"; 
	for (short i = 0; i < Rows;i++)

	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";
		}
		
		cout << "\n";
	}

	cout << endl;
}

int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int sum = 0;
	for (short j = 0; j < Cols ; j++)
	{
		sum += arr[RowNumber][j];
	}
	return sum;
}

void SumMatrixRowsInArray(int arrSum [3],int arr[3][3], short Rows, short Cols)
{
	

	for (short i = 0; i < Rows;i++)
	{
		arrSum[i] = RowSum(arr, i, Cols);
	}
}

void PrintSumResult(int arr1[3], short Rows)
{
	cout << "\nThe following are the sum of each row in the matrix:\n";
	for (short i = 0;i < Rows;i++)
	{
		cout << "Row " << i + 1 << " Sum = " << arr1[i] << endl;
	}
}

int main() 

{
	srand((unsigned)time(NULL));

	int arr[3][3];int arrSum[3];
	GenerateTwoDimArray(arr, 3, 3);
	PrintTwoDimArray(arr, 3, 3);
	SumMatrixRowsInArray(arrSum,arr, 3, 3);
	PrintSumResult(arrSum,3);
	
	

	return 0;
}