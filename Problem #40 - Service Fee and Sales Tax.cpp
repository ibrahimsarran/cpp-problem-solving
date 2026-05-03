//Problem #40 - Service Fee and Sales Tax

#include <iostream>
#include <string>

using namespace std;

const float SERVICE_FEE = 1.16;
const float SALE_TAX = 1.1;
float readPositiveNumber(string message)
{
	float number = 0;
	do
	{
		cout << message;
		cin >> number;

	} while (number <= 0);
	
	return number;

}
float totalBillAfterServiceAndTax(float totalBill)
{
	return totalBill * SERVICE_FEE * SALE_TAX;
}


void printTotalBill(float totalBill,float finalBill)
{
	cout << "Total Bill = " << totalBill << endl;
	cout << "Total Bill after Tax and Service fee = " << finalBill << endl;
	
}

int main()
{
	float totalBill = readPositiveNumber("Please Enter a bill value: ");
	printTotalBill(totalBill,totalBillAfterServiceAndTax(totalBill));



	return 0;


}

