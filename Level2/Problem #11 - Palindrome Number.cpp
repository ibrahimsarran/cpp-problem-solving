// Problem #11/2 - Palindrome Number.
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

int reversedNumber(int number)
{
    int remainder = 0, number2 = 0;

    while (number > 0)
    {

        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}
bool isPalindrome(int number)
{
    return number == reversedNumber(number);
      
} 
void printPalindrome(bool palindromeNumber)
{
    if (palindromeNumber)
        cout << "\nYes, It's a Palindrome Number" << endl;
    else
        cout << "\nNo, It's not a Palindrome Number" << endl;
}
int main()
{
    printPalindrome(isPalindrome(readPositiveNumber("Enter a positive Number: ")));

    return 0;
}