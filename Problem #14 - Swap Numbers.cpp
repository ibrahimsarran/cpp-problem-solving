//Problem #14 - Swap Numbers
#include <iostream>
using namespace std;
void readNumbers(int& A, int& B){
	cout << "Enter first number:" << endl;
	cin >> A;
	cout << "Enter Second number:" << endl;
	cin >> B;


}
void printNumbers(int A, int B) {
	cout << "number1: " << A << endl;
	cout << "number2: " << B << endl;

}
void Swap(int& A, int& B) {
	int temp;
	temp = A;
	A = B;
	B = temp;
}
int main()
{
	int num1, num2;
	readNumbers(num1, num2);
	printNumbers(num1, num2);
	Swap(num1, num2);
	printNumbers(num1, num2);
		
	
	return 0;

}

