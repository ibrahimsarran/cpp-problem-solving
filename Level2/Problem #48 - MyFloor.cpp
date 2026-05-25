// Problem #48/2 - MyFloor
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



int myFloor(float number)
{
    if (number > 0)
        return (int)number;
    else
        return (int)number - 1;
}
int main()
{
    float number = readNumber();
    cout << "My floor result: " << myFloor(number) << endl;
    cout << "C++ floor result: " << floor(number) << endl;
    

    return 0;

}