//Problem #48 - Monthly Loan Installment
#include <iostream>
#include <string>

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

float calculateMonthlyInstallment(float loanAmount, float months)
{
    return (loanAmount / months);
}
void printMonthlyInstallment(float monthlyInstallment)
{
    cout <<"You have to pay: " << monthlyInstallment << " Riyal" << endl;
}
int main()
{
    float loanAmount = readPositiveNumber("Enter your loan amount: ");
    float months = readPositiveNumber("How many months you need to settle the loan: ");

    printMonthlyInstallment(calculateMonthlyInstallment(loanAmount, months));
    return 0;
}
