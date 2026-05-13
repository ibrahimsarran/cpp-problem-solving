// Problem #14/2 - Inverted Letter Pattern.
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

void printInvertedLetterPattern(int number)
{
    for (int i = 65 + number - 1; i >= 65; i--)
    {
        for (int j = 1; j <= number - (65 + number - 1 - i); j++)

        {
            cout << char(i) << " "; 

        }

        cout << "\n";

    }
}

 
int main()
{
    printInvertedLetterPattern(readPositiveNumber("Enter a number: "));

    return 0;
}