//Problem #32 - Power of M
#include <iostream>
using namespace std;
 
int readNumber()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    return number;
}
int readPower()
{
    int power;
    cout << "Enter the power: ";
    cin >> power;

    return power;
}
int powerOfM(int num, int power)
{
    if (power == 0)
        return 1;

    int p = 1;
    for(int i =1 ; i <= power; i++)
    {
        p *= num;
    }
    return p;
}

int main()
{
    int n = readNumber();
    int p = readPower();
        cout <<"\nResult = " << powerOfM(n, p) << endl;
    
    return 0;
}
