// Problem #41/2 - Is Palindrome Array. 
#include <iostream>
using namespace std;


void fillArray(int arr[100], int& arrLength)
{
    arrLength = 6;
    cout << "Enter array elements:\n\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout<<"Element[" << i+1 << "] : ";
        cin >> arr[i];
    }

}

void printArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";

}

bool isPalindromeArray(int arr[100], int arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - i - 1])
            return false;
    }

    return true;
}

int main()
{

    int arr[100]; 
    int arrLength = 0;

    fillArray(arr, arrLength);
   
    cout << "\nArray Elements:\n";
    printArray(arr, arrLength);
    
    if (isPalindromeArray(arr, arrLength))
        cout << "\nYes, is Palindrome Array\n";
    else
        cout << "\nNo, is not Palindrome Array\n";



    return 0;

}