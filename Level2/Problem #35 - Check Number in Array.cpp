// Problem #35/2 - Check Number in Array.
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

bool isNumberInArray(int arr[100], int arrLength, int numberToFind)
{
    return searchForNumber(arr, arrLength, numberToFind) != -1;
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

    if (isNumberInArray(arr, arrLength, numberToFind))
        cout << "Yes, The number is found :-)\n";
    else
        cout << "No, The number is not found :-(\n";

    return 0;

}