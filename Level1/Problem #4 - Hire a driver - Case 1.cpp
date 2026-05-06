
#include <iostream>
#include <string>
using namespace std;

struct stInfo
{
    int age;
    bool hasDriverLicense;
};

stInfo readInfo()
{
    stInfo info;
    cout << "Enter your age?" << endl;
    cin >> info.age;
    cout << "Has a driver license?" << endl;
    cin >> info.hasDriverLicense;
    return info;

}
bool isEligible(stInfo info) 
{
    return (info.age > 21 && info.hasDriverLicense);
}
void printResult(bool eligible)
{
    if(eligible)
        cout << "\nYou are hired.";
    else
        cout << "\nYou are rejected.";
}

int main()
{
  printResult(isEligible(readInfo()));

    return 0;
}

