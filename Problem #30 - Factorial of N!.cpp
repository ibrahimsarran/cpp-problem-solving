Problem #30 - Factorial Of N

#include <iostream>
using namespace std;

int readPositiveNumber(string message)
{
    int number;
    do 
    {
        cout << message << "\n";
        cin >> number;
       
    } while (number < 0);

    return number;
}
int factorialOfN(int N)
{
    int factorial = 1;
    for (int i = N; i >= 1; i--)
    {
        factorial *= i;
    }
    return factorial;
}
int main()
{
    cout << factorialOfN(readPositiveNumber("Enter positive number: ")) << endl;

    return 0;
}