// Problem #21 - Circle Area Along the Circumference

#include <iostream>
using namespace std;

float readL() 
{
	float L;
	cout << "enter the value of L ?" << endl;
	cin >> L;
	return L;
}
float calculatecircleArea(float L) {
	float const PI = 3.14;
	return (L * L) / (PI * 4);
}
void printArea(float area) {
	cout << "the area: " << floor(area);
}

int main()
{
	
	printArea(calculatecircleArea(readL()));

	return 0;


}

