// 2/3 - Sum Each Row in Matrix 

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
	
	for (int i = 0; i < Rows;i++)
	{
		for (int j = 0; j < Cols;j++)
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
	int Sum = 0;
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe the following are the sum of each row in the matrix:\n";

	for (short i = 0; i < Rows;i++)
	{
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i,Cols) << endl;
	}
}

int main() 

{
	srand((unsigned)time(NULL));

	int arr[3][3];
	GenerateTwoDimArray(arr, 3, 3);
	PrintTwoDimArray(arr, 3, 3);
	PrintEachRowSum(arr, 3, 3);
	

	return 0;
}