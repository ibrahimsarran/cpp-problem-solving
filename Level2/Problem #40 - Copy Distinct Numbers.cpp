// Problem #40/2 - Copy Distinct Numbers to Array. 
#include <iostream>
using namespace std;


void fillArray(int arr[100], int& arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 30;
    arr[4] = 30;
    arr[5] = 50;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 90;
    arr[9] = 90;
}

void printArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";

}

void addArrayElement(int number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = number;

}
short FindNumberPositionInArray(int number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
            return i; 
    }
   
    return -1;
}

bool isNumberInArray(int number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(number, arr, arrLength) != -1;
}

void copyDistinctNumbers(int arr[100], int arr2[100], int arrLength, int& arr2Length)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (!isNumberInArray(arr[i], arr2, arr2Length))
            addArrayElement(arr[i], arr2, arr2Length);
    }
}


int main()
{

    int arr[100]; 
    int arr2[100];
    int arrLength = 0, arr2Length = 0;  

    fillArray(arr, arrLength);
    cout << "\nArray 1 elements:\n";
    printArray(arr, arrLength);

    copyDistinctNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 2 Distinct Numbers:\n";
    printArray(arr2, arr2Length);




    return 0;

}