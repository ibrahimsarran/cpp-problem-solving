//Problem #49 - ATM PIN

#include <iostream>
#include <string>

using namespace std;

const int BALANCE = 7500;

string readATMPin()
{
    string pinCode;
    cout << "Enter ATM PIN: ";
    cin >> pinCode;
    return pinCode;
}

bool login()
{
    string pinCode;
    do
    {
        pinCode = readATMPin();

        if (pinCode == "1234")
        {
            return 1;
        }
        else
        {
            cout << "\nWrong PIN\n";
            system("color 4F"); 
        }

    } while (pinCode != "1234");

}

void printResult(bool isSuccessful)
{
    if (isSuccessful)
    {
        system("color 2F"); 
        cout << "\nYour Account Balance is: " << BALANCE << endl;
    }
}

int main()
{
    printResult(login());

    return 0;
}