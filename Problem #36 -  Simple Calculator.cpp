//Problem #36 -  Simple Calculator
#include <iostream>
using namespace std;

enum enOperationType{Add=1,Sub=2,Mul=3,Div=4};
float readNumbers(string message)
{
    float number = 0;
    cout << message ;
    cin >> number;
    return number;
}
enOperationType readOperationType()
{
    int type;
    cout << "\nChoose operation Type:\n";
    cout << "\n1:Addition";
    cout << "\n2:Subtraction";
    cout << "\n3:Multiplication";
    cout << "\n4:Division\n\n";
    cout << "choose: ";
    cin >> type;
    return (enOperationType)type;
}

float calculate(int num1,int num2,enOperationType type)

{
    switch (type)
    {

        case enOperationType::Add:
            return num1 + num2;

        case enOperationType::Sub:
            return num1 - num2;

       case enOperationType::Mul:
            return num1 * num2;

       case enOperationType::Div:
           return (float)num1 / num2;
           
       default:
           return 0;
    }
}

void printResult(float result)
{
    cout << "Result = " << result << endl;
}

int main()
{
    float num1 = readNumbers("Enter First number:");
    float num2 = readNumbers("Enter Second number:");
    printResult(calculate(num1, num2, readOperationType()));


    return 0;
}