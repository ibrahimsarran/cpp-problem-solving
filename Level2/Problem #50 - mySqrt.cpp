// Problem #50/2 - mySqrt
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


int mySqrt(float number)
{
    return pow(number, 0.5);
   
}

int main()
{
    float number = readNumber();
    cout << "My sqrt result: " << mySqrt(number) << endl;
    cout << "C++ sqrt result: " << sqrt(number) << endl;
    

    return 0;

}