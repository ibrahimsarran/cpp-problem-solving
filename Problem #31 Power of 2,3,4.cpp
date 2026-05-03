//Problem #31 Power of 2,3,4
#include <iostream>

using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please enter a number? " << endl;
    cin >> Number;

    return Number;
}

void PowerOf2_3_4(int Number)
{
    int a, b, c;

    a = Number * Number;
    b = Number * Number * Number;
    c = Number * Number * Number * Number;

    cout << a << " " << b << " " << c << endl;
}

int main()
{
    PowerOf2_3_4(ReadNumber());

    return 0;
}