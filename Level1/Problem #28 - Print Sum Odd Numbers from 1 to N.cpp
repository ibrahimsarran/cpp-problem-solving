//Problem #28 - Print Sum Odd Numbers from 1 to N

#include <iostream>
using namespace std;

enum enEvenOdd{Even, Odd};
int readNumber()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
    
}
enEvenOdd checkEvenOdd(int number)
{
    if (number % 2 == 0)
        return enEvenOdd::Even;
    else
        return enEvenOdd::Odd;
}
int sumOddNumber_UsingWhile(int number)
{
    int counter = 0;
    int sum = 0;
    cout << "\nSum odd number using While" << endl;
    while (counter < number)
    {
        counter++;
        if (checkEvenOdd(counter) == enEvenOdd::Odd)
        {
            sum += counter;
        }
        


    }
    return sum;
}
int sumOddNumber_UsingDoWhile(int number)
{
    int counter = 0;
    int sum = 0;
    cout << "\nSum odd number using do-While" << endl;
    do
    {
        counter++;
        if (checkEvenOdd(counter) == enEvenOdd::Odd)
        {
            sum += counter;
        }
    } while (counter < number);

    return sum;
}
int sumOddNumber_UsingFor(int number)
{
    int sum = 0;
    cout << "\nSum odd number using for loop " << endl;
    for (int counter = 1; counter <= number; counter++) 
    {
        if (checkEvenOdd(counter) == enEvenOdd::Odd)
        {
            sum += counter;
        }
    }
    return sum;
}
    
    




int main()
{
    int N = readNumber();
    cout << sumOddNumber_UsingWhile(N) << endl;
    cout << sumOddNumber_UsingDoWhile(N) << endl;
    cout << sumOddNumber_UsingFor(N) << endl;
    
    

    return 0;
}

