// Problem #46/2 - MyABS
#include <iostream>
#include <cmath>
using namespace std;

float readNumber()
{
    float number = 0;
    cout << "Please enter a number? ";
    cin >> number;

    return number;
}

float myABS(float number)
{
    if (number > 0)
        return number;
    else
        return number * -1;
}

int main()
{
    float number = readNumber();
    cout << "My abs result: " << myABS(number) << endl;
    cout << "C++ abs result: " << abs(number) << endl;


    return 0;

}