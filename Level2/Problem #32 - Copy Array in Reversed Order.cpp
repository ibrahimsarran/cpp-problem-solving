// Problem #32/2 - Copy Array in Reversed Order.
#include <iostream>
#include <cstdlib>
using namespace std;

int readPositiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0 || number > 100);

    return number;
}


int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void fillArrayWithRandomNumbers(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)

    {
        arr[i] = randomNumber(1, 100);
    }
    cout << endl;
}
void reversedArray(int arrSoure[100], int arrDestination[100], int arrLength)

{
    for (int i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSoure[arrLength-1-i];
    }
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";

}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arr2[100];
    int arrLength = readPositiveNumber("How many Elements?");

    fillArrayWithRandomNumbers(arr, arrLength);


    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    reversedArray(arr, arr2, arrLength);

    cout << "\nArray 2 elements after copy in reversed order:\n";
    PrintArray(arr2, arrLength);




    return 0;

}