// Problem #28/2 - Copy Array
#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Enter number of elements: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)

    {
        arr[i] = randomNumber(1, 100);
    }
    cout << endl;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";

}
void copyArray(int arrSource[100],int arrDestination[100], int arrLength)
{
    
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[i];
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    fillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100];
    copyArray(arr, arr2, arrLength);

    cout << "\nArray 1 Elements:\n";
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Elements After copy:\n";
    PrintArray(arr2, arrLength);
    


    return 0;

}