// #13/3 - Check Identity Matrix. 
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

bool IsIdentityMatrix(int matrix1[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && matrix1[i][j] != 1)
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

	//int Matrix1[3][3] = { {1,3,4},{1,3,3},{3,0,0} };
	int Matrix1[3][3] = { {1,0,0},{0,1,0},{0,0,1} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsIdentityMatrix(Matrix1, 3, 3))
		cout << "\nYes, it is identity matrix.\n";
	else
		cout << "\nNo, it is not identity matrix.\n";


	system("pause>0");
	return 0;
}