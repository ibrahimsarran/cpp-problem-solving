// #20/3 - Palindrome Matrix
#include<iostream>
using namespace std;

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

bool IsPalindromeMatrix(int matrix[3][3], short Rows, short Cols)
{
	
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (matrix[i][j] != matrix[i][Cols - 1 - j])
				return false;

		}
	}
	return true;
}

int main()

{
	//int Matrix1[3][3] = { {1,2,1},{7,7,7},{9,8,9} };
	int Matrix1[3][3] = { {1,2,1},{1,1,7},{9,8,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	
	if (IsPalindromeMatrix(Matrix1, 3, 3))
		cout << "\nYes: Matrix is Palindrome\n";
	else
		cout << "\nNo: Matrix is not Palindrome\n";


	system("pause>0");
	return 0;
}