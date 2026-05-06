// Problem #17 - Triangle Area

#include <iostream>
#include <cmath>

using namespace std;
void readNumbers(float& a, float& h)
{
	cout << "Enter triangle base a : ";
	cin >> a;
	cout << "Enter triangle height h : ";
	cin >> h;
}

float rectangleAreaBySideAndDigonal(float a, float h)
{
	return (a / 2) * h;
}
void printResult(float area)
{
	cout << "\nThe Triangle Area is: " << area;
}

int main()
{
	float a, h;
	readNumbers(a, h);
	printResult(rectangleAreaBySideAndDigonal(a,h));
	return 0;
}







