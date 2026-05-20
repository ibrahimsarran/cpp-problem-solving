// Problem #34/2 - Return Number Index in Array.
#include <iostream>
#include <cstdlib>
using namespace std;

int readNumber()
{
    int number;
    cout << "Enter a number to search for: ";
    cin >> number;

    return number;
}


int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;


    for (int i = 0; i < arrLength; i++)
        arr[i] = randomNumber(1, 100);

}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";
}

short searchForNumber(int arr[100], int arrLength, int numberToFind)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == numberToFind)
            return i;

    }
    return -1;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    fillArrayWithRandomNumbers(arr, arrLength);

    cout << "Array1 elements:\n";
    PrintArray(arr, arrLength);

    int numberToFind = readNumber();
    cout << "\nNumber you are looking for is: " << numberToFind << endl;

    short numberPosition = searchForNumber(arr, arrLength, numberToFind);

    if (numberPosition == -1)
        cout << "\nThe number is not found :-(\n";
    else
    {
        cout << "\nThe number found at position: " << numberPosition << endl;
        cout << "The number found its order: " << numberPosition + 1 << endl;
    }


    return 0;

}