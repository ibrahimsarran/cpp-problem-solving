//#26 Print Numbers from 1 to N

#include <iostream>
using namespace std;
int readNumber()
{
    int N;
    cout << "Enter value of N: ";
    cin >> N;
    return N;
}
void printResult(int N)
{
    for (int i = 1; i <= N; i++)
    {
        cout << i << "\n";

    }
}
int main()
{
    printResult(readNumber());
    return 0;
}
