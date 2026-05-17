// Problem #22/2 - Count Repeated Element in Array
#include <iostream>
using namespace std;


int readPositiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message;
        cin >> number;
        

    } while (number <= 0);

    return number;
}

void readArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements: ";
    cin >> arrLength;
   
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element[" << i+1 << "]:";
        cin >> arr[i];
        
    }
    cout << endl;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  
}

int TimesRepeated(int number, int arr[100], int arrLength)
{
    int count = 0;  
    
    for (int i = 0; i < arrLength; i++)
    {
        if (number == arr[i])  
        {
            count++;  
        }
    }
    return count;  
}
int main()
{
    int arr[100];
    int numberToCheck;
    int arrLength;

    readArray(arr, arrLength);
    numberToCheck = readPositiveNumber("Enter the number you want to check: ");
    
    cout << "\nOriginal array: ";
    PrintArray(arr, arrLength);
    cout << "\nNumber " << numberToCheck<< " is repeated ";
    cout << TimesRepeated(numberToCheck, arr, arrLength) << " time(s)\n";


    return 0;

}