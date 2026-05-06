//Problem #35 - Piggy Bank Calculator
#include <iostream>
using namespace std;

struct stPiggyBankContent
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPiggyBankContent readPiggyBankContent()
{
    stPiggyBankContent piggyBankContent;

    cout << "Please enter the total number of Pennies: " << endl;
    cin >> piggyBankContent.Pennies;
    cout << "Please enter the total number of Nickels: " << endl;
    cin >> piggyBankContent.Nickels;
    cout << "Please enter the total number of Dimes: " << endl;
    cin >> piggyBankContent.Dimes;
    cout << "Please enter the total number of Quarters: " << endl;
    cin >> piggyBankContent.Quarters;
    cout << "Please enter the total number of Dollar bills: " << endl;
    cin >> piggyBankContent.Dollars;

    return piggyBankContent;
}

int calculateTotalPennies(stPiggyBankContent piggyBankContent)
{
    int totalPennies = piggyBankContent.Pennies * 1
        + piggyBankContent.Nickels * 5
        + piggyBankContent.Dimes * 10
        + piggyBankContent.Quarters * 25
        + piggyBankContent.Dollars * 100;

    return totalPennies;
}

int main()
{
    int totalPennies = calculateTotalPennies(readPiggyBankContent());

    cout << endl << "Total Pennies = " << totalPennies << endl;
    cout << endl << "Total Dollars = $" << (float)totalPennies / 100 << endl;

    return 0;
}