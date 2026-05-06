// Problem #7 Half Number
#include <iostream>
#include <string>
using namespace std;

int readNumber()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    return num;
}
float calculateHalfNumber(int num)
{
    return (float)num / 2;
}
void printResult(int num)
{
    string result = "Half of " + to_string(num) + " is " + to_string(calculateHalfNumber(num));
    cout << endl << result << endl;
}
int main()
{
    printResult(readNumber());
    
    return 0;
}

