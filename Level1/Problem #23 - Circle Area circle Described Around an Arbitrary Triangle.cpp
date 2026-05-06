
//Problem #23 - Circle Area circle Described Around an Arbitrary Triangle
#include <iostream>
using namespace std;

void readInfo(float& a, float& b, float& c) {

	cout << "enter a:";
	cin >> a;
	cout << "enter b:";
	cin >> b;
	cout << "enter c:";
	cin >> c;

}
float calculatecircleArea(float a, float b, float c) {
	const float PI = 3.14;
	float p = (a + b + c) / 2;
	float d = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	d = d * d;
	return PI * d;
}
void printInfo(float area) {
	cout << "the area is:" << area << "\n";
}
int main()
{
	float a, b, c;
	readInfo(a, b, c);
	printInfo(calculatecircleArea(a, b, c));
	return 0;


}






