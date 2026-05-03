//Problem #3 Even or Odd. 
#include <iostream>
#include <string>
using namespace std;

enum enNumberType{Even = 1, Odd = 2};

int readNumber()
{
    int num;
    cout << "Enter a number ?" << endl;
    cin >> num;
    return num;
}
enNumberType checkNumberType(int num)
{
    int result = num % 2;
    if (result == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;
}

void printNumberType(enNumberType numberType)
{
    if (numberType == enNumberType::Even)
        cout << "\nNumber is Even.\n";
    else
        cout << "\nNumber is Odd.\n";
}

int main()
{
    printNumberType(checkNumberType(readNumber()));
    return 0;
}
