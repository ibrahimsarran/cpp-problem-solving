// Problem #8/2 - Digit Frequency
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
void printFrequency(short userFrequency, int frequency)
{
    cout << "\nDigit " << userFrequency << " Frequency " << frequency << " Time(s)." << endl;
}

int main() 
{
    int number = readPositiveNumber("Enter the number: ");
    short userFrequency = readPositiveNumber("\nchoose number to know its frequency: ");
    printFrequency(userFrequency, countDigitFrequency(userFrequency, number));

    return 0;
}