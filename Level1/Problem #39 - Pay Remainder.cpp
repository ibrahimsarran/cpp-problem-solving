//Problem #39 - Pay Remainder
#include <iostream>
#include <string>
using namespace std;

float readPositiveNumber(string message)
{
    float number = 0;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);


    return number;
}
float calculateRemainder(float totalBill, float totalCashPaid)
{
    return  totalCashPaid - totalBill;
}
void printBill(float totalBill, float totalCashPaid, float remainder)
{
    cout << "Total Bill = " << totalBill << endl;
    cout << "Total Cash Paid = " << totalCashPaid << endl;
    cout << "********************" << endl;
    cout << "Remainder = " << remainder << endl;
}

int main()
{
    float totalBill = readPositiveNumber("Please Enter total bill: ");
    float totalCashPaid = readPositiveNumber("Please Enter total cash paid: ");
    float remainder = calculateRemainder(totalBill, totalCashPaid);
    printBill(totalBill, totalCashPaid, remainder);


    return 0;
}

