// Problem #5/2 - Print Digits in Reversed Order
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

void numberInReversedOrder(int number)
{
    int remainder = 0;
    while (number > 0)
    {


        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }
}
int main()
{
    numberInReversedOrder(readPositiveNumber("Enter a Positive Number: "));

    return 0;
}