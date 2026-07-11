// #4/3 - Sum Each Column in Matrix 

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

int ColumnSum(int arr[3][3], short Rows, short ColumnNumber)
{
	int sum = 0;
	for (short i = 0; i < Rows ; i++)
	{
		sum += arr[i][ColumnNumber];
	}
	return sum;
}


void PrintEachColumnsSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe following are the sum of each Column in the matrix:\n";
	for (short j = 0;j < Cols;j++)
	{
		cout << "Column " << j + 1 << " Sum = " << ColumnSum(arr,Rows,j) << endl;
	}
}

int main() 

{
	srand((unsigned)time(NULL));

	int arr[3][3];
	GenerateTwoDimArray(arr, 3, 3);
	PrintTwoDimArray(arr, 3, 3);
	PrintEachColumnSum(arr,3,3);
	
	

	return 0;
}