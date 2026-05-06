//Problem #37 - Sum Until - 99
#include <iostream>
#include <string>
using namespace std;


int readNumber(string message)
{
    int N;
    cout << message;
    cin >> N;
    return N;
}

int sumNumbers()
{
    int sum = 0, number = 0, counter = 1;
    do
    {
        number = readNumber("Enter number" + to_string(counter)+": ");
        if (number == -99)
        {
            break;
        }
        sum += number;
        counter++;
    } while (number != -99);

    return sum;
}

int main()
{
    int num = sumNumbers();
    cout << endl << "The sum is: " << num << endl;

    return 0;
}
