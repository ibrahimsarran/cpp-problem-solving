#29 Print sum of even Numbers from 1 to N


#include <iostream>
using namespace std;

enum enEvenOdd { Even, Odd };
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
int sumEvenNumber_UsingWhile(int number)
{
    int counter = 0;
    int sum = 0;
    cout << "\nSum Even number using While" << endl;
    while (counter < number)
    {
        counter++;
        if (checkEvenOdd(counter) == enEvenOdd::Even)
        {
            sum += counter;
        }



    }
    return sum;
}
int sumEvenNumber_UsingDoWhile(int number)
{
    int counter = 0;
    int sum = 0;
    cout << "\nSum Even number using do-While" << endl;
    do
    {
        counter++;
        if (checkEvenOdd(counter) == enEvenOdd::Even)
        {
            sum += counter;
        }
    } while (counter < number);

    return sum;
}
int sumEvenNumber_UsingFor(int number)
{
    int sum = 0;
    cout << "\nSum Even number using for loop " << endl;
    for (int counter = 1; counter <= number; counter++)
    {
        if (checkEvenOdd(counter) == enEvenOdd::Even)
        {
            sum += counter;
        }
    }
    return sum;
}



int main()
{
    int N = readNumber();
    cout << sumEvenNumber_UsingWhile(N) << endl;
    cout << sumEvenNumber_UsingDoWhile(N) << endl;
    cout << sumEvenNumber_UsingFor(N) << endl;



    return 0;
}

