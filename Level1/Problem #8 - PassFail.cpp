// Problem #8 - Pass/Fail
#include <iostream>
using namespace std;

int readMark()
{
    int mark;
    cout << "Enter Your Mark ?" << endl;
    cin >> mark;
    return mark;

}

bool isPass(int mark)
{

    return (mark >= 50);
}
void printResult(bool passed)
{
    if (passed)
    {
        system("color 2F");
        cout << "\nPass\n";
    }
    else
    {
        system("color 4F");
        cout << "\nFail\n";
    }
}
int main()
{
    printResult(isPass(readMark()));
    return 0;
}
