//Problem #2 Read name and Print it
#include <iostream>
#include <string>
using namespace std;
string readName()
{
    string name;
    cout << "Enter Your Name ?" << endl;
    getline(cin, name);
    return name;
}
void  printName(string name)
{
    cout << "\nYour name is: " << name << endl;
}

int main()
{
    printName(readName());
    return 0;
}
