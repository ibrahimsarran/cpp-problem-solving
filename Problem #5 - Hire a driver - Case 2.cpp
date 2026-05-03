
#include <iostream>
#include <string>
using namespace std;

struct stInfo
{
    int age;
    bool hasDriverLicense;
    bool hasRecomendation;
};

stInfo readInfo()
{
    stInfo info;
    cout << "Enter your age?" << endl;
    cin >> info.age;
    cout << "Do you have a driver license?" << endl;
    cin >> info.hasDriverLicense;
    cout << "Do you have a recomendation?" << endl;
    cin >> info.hasRecomendation;
    
    return info;

}
bool isEligible(stInfo info)
{
    if (info.hasRecomendation)
        return true;
    
    else
        return (info.age > 21 && info.hasDriverLicense);
}
void printResult(bool eligible)
{
    if (eligible)
        cout << "\nYou are hired.";
    else
        cout << "\nYou are rejected.";
}

int main()
{
    printResult(isEligible(readInfo()));

    return 0;
}

