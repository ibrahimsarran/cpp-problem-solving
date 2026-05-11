// Problem #7/2 - Reversed Number
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
void printReversedNumber(int number)
{
    cout << "\nReversed Number : " << number << endl;

}
int main()
{
    
    printReversedNumber(reversedNumber(readPositiveNumber("Enter a Positive Number: ")));
        

    return 0;
}