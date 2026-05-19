// Problem #31/2 - Shuffle Ordered Array
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

void Swap(int& A, int& B) 
{
    int temp;
    temp = A;
    A = B;
    B = temp;
}
int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void fillArrayWithNumbers(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)

    {
        arr[i] = i + 1;
    }
    cout << endl;
}
void shuffleArray(int arr[100], int arrLength)

{
    for (int i = 0; i < arrLength; i++)
    {
        Swap(arr[randomNumber(1, arrLength) - 1], arr[randomNumber(1, arrLength) - 1]);
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

    fillArrayWithNumbers(arr, arrLength);


    cout << "\nArray elements without shuffle:\n";
    PrintArray(arr, arrLength);

    shuffleArray(arr, arrLength);

    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr, arrLength);




    return 0;

}