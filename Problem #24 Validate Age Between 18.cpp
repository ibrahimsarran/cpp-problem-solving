//Problem #24 Validate Age Between 18 and 45
#include <iostream>
using namespace std;

int readAge()
{
    int age;
    cout << "Enter Your Age:" << endl;
    cin >> age;
    return age;
}
bool checkAge(int age)
{
    return (age >= 18 && age <= 45);
}
void printResult(bool result)
{
    if (result)
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
}
int main()
{
    
    printResult(checkAge(readAge()));
    

    return 0;
}
