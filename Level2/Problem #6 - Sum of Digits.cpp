// Problem #6/2 - Sum of Digits
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

int sumOfDigits(int number)
{
    int remainder = 0;
    int sum = 0;
    while (number > 0)
    {


        remainder = number % 10;
        number = number / 10;
        sum += remainder;
    }
    
    return sum;
}
void printSumOfDigits(int sum)
{
    cout << "\nSum of Digits = " << sum << endl;
}
int main()
{
     printSumOfDigits(sumOfDigits(readPositiveNumber("Enter a Positive Number: ")));

    return 0;
}