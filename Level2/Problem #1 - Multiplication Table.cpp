//Problem #1/2 - Multiplication Table

#include <iostream>
#include <string>
using namespace std;


void printTableHeader()
{
    cout << "\n\t\t\tMultiplication Table From 1 to 12\n\n\n\t";

    for (int i = 1; i <= 12; i++)
    {
        cout << i << "\t";
    }
    cout << "\n-----------------------------------------------------------------------------------------------------\n";
}
string columnSeparator(int i)
{
    if (i < 10)
        return "  |";
    else
        return " |";
}

void multiplicationTable()
{
    printTableHeader();
    for (int i = 1; i <= 12; i++)
    {
        cout << " " << i << columnSeparator(i) << "\t";
        for (int j = 1; j <= 12; j++)
        {
            cout << i * j << "\t";

        }
        cout << endl;
    }

}
int main()
{
    multiplicationTable();

    return 0;
}
