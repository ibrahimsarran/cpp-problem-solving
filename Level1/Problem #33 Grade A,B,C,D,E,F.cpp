Problem #33 Grade A,B,C,D,E,F
#include <iostream>
using namespace std;

int readNumberInRange(int From, int To)
{
    int grade;

    do
    {
        cout << "Please enter a Grade between " << From << " and " << To << "? " << endl;
        cin >> grade;
    } while (grade < From || grade > To);

    return grade;
}

char getGradeLetter(int grade)
{
    if (grade >= 90)
        return 'A';
    else if (grade >= 80)
        return 'B';
    else if (grade >= 70)
        return 'C';
    else if (grade >= 60)
        return 'D';
    else if (grade >= 50)
        return 'E';
    else
        return 'F';
}

int main()
{
    cout << endl << "Result = " << getGradeLetter(readNumberInRange(0, 100)) << endl;

    return 0;
}