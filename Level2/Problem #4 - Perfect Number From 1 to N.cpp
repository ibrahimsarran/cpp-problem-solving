// Problem #4/2 - Perfect Number From 1 to N
#include <iostream>
#include <string>
using namespace std;


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
bool isPerfectNumber(int number)
{
    int sum = 0;
    for (int i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
            sum += i;
    }

    return number == sum;
}
void printPerfectNumbersFrom1ToN(int number)
{
    cout << "\nPerfect Numbers From 1 To " << number << " are:\n";
    for (int i = 1; i <= number; i++)
    {
        if (isPerfectNumber(i))
            cout << i << "  ";
    }
    cout << endl;
}

int main()
{
   
    printPerfectNumbersFrom1ToN(readPositiveNumber("Please Enter a positive number: "));
   
    return 0;
}