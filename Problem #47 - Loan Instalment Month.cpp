//Problem #47 - Loan Instalment Months
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


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

int calculateHowManyMonths(float loanAmount, float monthlyPayment)
{
    return (ceil(loanAmount / monthlyPayment));
}
void printTotalMonths(int months)
{
    cout << months << " Months" << endl;
}
int main()
{
    float loanAmount = readPositiveNumber("Enter your loan amount: ");
    float monthlyPayment = readPositiveNumber("Enter your monthly payment: ");

    printTotalMonths(calculateHowManyMonths(loanAmount, monthlyPayment));
    return 0;
}
