
//Problem #22 Circle Area Inscribed in an Isosceles Triangle
#include <iostream>
using namespace std;

void readTriangleData(float& a, float& b) {

	cout << "enter the value of a ?" << endl;
	cin >> a;
	cout << "enter the value of b ?" << endl;
	cin >> b;

}
float calculatecircleArea(float a, float b) {
	const float PI = 3.141592653589793238;
	float area = (((PI * b * b)) / 4) * ((2 * a - b) / (2 * a + b));
	return area;
}
void printArea(float area) {
	cout << "the area: " << floor(area);
}

int main()
{
	float a, b;
	readTriangleData(a, b);
	printArea(calculatecircleArea(a, b));

	return 0;


}






