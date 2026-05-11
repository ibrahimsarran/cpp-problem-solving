// Problem #9/2 - Digit Frequency
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

int countDigitFrequency(short userFrequency, int number)
{

    int freqCount = 0;
    int remainder = 0;

    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;

        if (remainder == userFrequency)
        {
            freqCount++;
        }
    }
    return freqCount;
}
void printDigitsFrequency(int number)
{
    for (int i = 0; i < 10; i++)
    {
        short freq = 0;
        short freq = countDigitFrequency(i, number);

        if (freq > 0) 
        {
            cout << "\nDigit " << i << " Frequency " << freq << " Time(s)." << endl;
        }
        
    }
    cout << endl;
}

int main()
{
    int number = readPositiveNumber("Enter the number: ");
    printDigitsFrequency(number);

    return 0;
}