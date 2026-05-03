//Problem #6 - FullName

#include <iostream>
#include <string>
using namespace std;

struct stInfo
{
    string firstName;
    string middleName;
    string lastName;
};

stInfo readInfo()
{
    stInfo info;
    cout << "Enter your First Name?" << endl;
    cin >> info.firstName;
    cout << "Enter your middle Name?" << endl;
    cin >> info.middleName;
    cout << "Enter your Last Name?" << endl;
    cin >> info.lastName;


    return info;
}
string getFullName(stInfo info)
{
    string fullName;
    fullName = info.firstName + " " + info.middleName + " " + info.lastName;
    return fullName;
}
void printFullName(string fullName)
{
    cout << "Your Full Name is: " << fullName;
}
int main()
{
    printFullName(getFullName(readInfo()));
    return 0;
}

