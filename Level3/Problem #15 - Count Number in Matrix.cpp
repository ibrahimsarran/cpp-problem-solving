// #15/3 - Count Number in Matrix. 
#include<iostream>
using namespace std;

int ReadNumber()
{
	int number = 0;
	cout << "Enter the Number to count in matrix? ";
	cin >> number;
	return number;
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

int CountNumberInMatrix(int matrix1[3][3],int number, short Rows, short Cols)
{
	int counter = 0;

	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (matrix1[i][j] == number)
				counter++;
		}
	}

	return counter;
}

int main()

{
	int Matrix1[3][3] = { {6,3,2},{0,6,1},{6,4,6} };
	int number = ReadNumber();
	int countNumber = CountNumberInMatrix(Matrix1, number, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	
	cout << "Number " << number << " count in matrix is " << countNumber << endl;

	system("pause>0");
	return 0;
}