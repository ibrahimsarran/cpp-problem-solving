//Problem #38 Is Prime Number
#include <iostream>
using namespace std;

enum enPrimeNotPrime{Prime, NotPrime};

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
enPrimeNotPrime checkPrime(int number)
{
    int m = round(number / 2.0);
    for (int counter = 2; counter <= m; counter++)
    {
        if (number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}
void printNumberType(enPrimeNotPrime type)

{
    switch (type)
    {
    case enPrimeNotPrime::Prime:
        cout << "The number is prime\n";
        break;

    case enPrimeNotPrime::NotPrime:
            cout << "The number is not prime\n";
            break;
    }
}
int main()
{
  
    printNumberType((checkPrime(readPositiveNumber("Please Enter a positive number: "))));
    return 0;
}
