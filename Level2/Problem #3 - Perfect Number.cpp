// Problem #3/2 - Perfect Number
#include <iostream>
#include <string>
using namespace std;

enum enPerfectNotPerfect { Perfect, NotPerfect };

int readPositiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;

    } while (number <= 0);

    return number;
}
enPerfectNotPerfect isPerfect(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
            sum += i;
    }

    if (number == sum)
        return enPerfectNotPerfect::Perfect;
    else
        return enPerfectNotPerfect::NotPerfect;
}
void printResult(enPerfectNotPerfect type, int number)
{
    switch(type)
    {
    case enPerfectNotPerfect::Perfect:
        cout <<"\n" << number << " is Perfect Number\n";
        break;
    case enPerfectNotPerfect::NotPerfect:
        cout <<"\n" << number << " is Not Perfect Number\n";

    }
}

int main()
{
    int number = readPositiveNumber("Please Enter a positive number: ");
    printResult(isPerfect(number), number);
    return 0;
}