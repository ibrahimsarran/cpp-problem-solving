// Problem #16 - Rectangle area Through Diagonal and Side Area using function
#include <iostream>
#include <cmath>

using namespace std;
void readNumbers(float& side, float& diagonal)
{
	cout << "Enter the side: ";
	cin >> side;
	cout << "Enter the diagonal: ";
	cin >> diagonal;
}

float rectangleAreaBySideAndDigonal(float side, float diagonal)
{
	return side * sqrt((diagonal * diagonal) - (side * side));
}
void printResult(float area)
{
	cout << "The Area is: " << area;
}

int main()
{
	float side, diagonal;
	readNumbers(side, diagonal);
	printResult(rectangleAreaBySideAndDigonal(side,diagonal));
	return 0;
}







