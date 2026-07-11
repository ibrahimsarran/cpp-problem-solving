// #1/3 - 3*3 Random Matrix 

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int RandomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void GenerateTwoDimArray(int x[3][3],short Rows, short Cols)
{
	
	for (short i = 0; i < Rows;i++)
	{
		for (short j = 0; j < Cols;j++)
		{
			x[i][j] = RandomNumber(1,100);
		}
	}
}

void PrintTwoDimArray(int x[3][3], short Rows, short Cols)
{
	cout << "\nThe Two Dim Array:\n";
	for (short i = 0; i < Rows;i++)

	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << x[i][j] << "   ";
		}
		
		cout << "\n";
	}

	cout << endl;
}
int main() 

{
	srand((unsigned)time(NULL));

	int x[3][3];
	GenerateTwoDimArray(x,3,3);
	PrintTwoDimArray(x,3,3);


	return 0;
}