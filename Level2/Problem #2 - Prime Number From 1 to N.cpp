// Problem #2/2 - Prime Number from 1 to N
#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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
    if (number == 1)
        return enPrimeNotPrime::NotPrime;
    int m = sqrt(number); // القاعدة الرياضية تقول: إذا لم تجد أي قاسم للرقم من 2 وحتى جذره التربيعي، فمن المستحيل رياضياً أن تجد قاسماً بعد الجذر التربيعي!

    for (int counter = 2; counter <= m; counter++)
    {
        if (number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}
void printPrimNumbersFrom1ToN(int number)
{
    cout << "\n";
    cout << "Prime Numbers From 1 " << "To " << number;
    cout << " are: " << endl;

    for (int i = 1; i <= number; i++)
    {
        if (checkPrime(i) == enPrimeNotPrime::Prime)
        {
            cout << i << "\n";
        }
    }
    cout << endl;
}

int main()
{

    printPrimNumbersFrom1ToN(readPositiveNumber("Please Enter a positive number: "));
    return 0;
}