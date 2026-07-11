// #6/3 - 3x3 Ordered Matrix 
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
	cout << "\nThe following is the ordered 3x3 matrix:\n";
	for (short i = 0; i < Rows;i++)
	{

		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "   ";
		}

		cout << "\n";
	}

}


int main()

{


	int arr[3][3];
	FillMatrixWithOrderedNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);


	return 0;
}