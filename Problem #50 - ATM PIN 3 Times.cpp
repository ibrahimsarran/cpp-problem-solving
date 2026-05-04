//Problem #50 - ATM PIN 3 Times

#include <iostream>
#include <string>
using namespace std;

const int MAX_TRIES = 3;
const string CORRECT_PIN = "1234";
const int BALANCE = 7500;

string readATMPin()
{
    string pinCode;
    cout << "\nEnter ATM PIN: ";
    cin >> pinCode;
    return pinCode;
}

bool login()
{
    int tries = MAX_TRIES;
    string pinCode;
    do 
    {
        tries--;
        pinCode = readATMPin();

        if (pinCode == CORRECT_PIN)
        {
            return true;
        }
        else
        {
            
            system("color 4F");
            cout << "\nWrong PIN, you have " << tries << " more tries\n";
            
        }
        
    } while (tries > 0 && pinCode != CORRECT_PIN);

    return false;
}

void printResult(bool isSuccessful)
{
    if (isSuccessful)
    {
        system("color 2F"); 
        cout << "\nYour Account Balance is: " << BALANCE << endl;
    }
    else
    {
        system("color 4F");
        cout << "\nYour card is locked" << endl;
    }
}

int main()
{
    printResult(login());

    return 0;
}