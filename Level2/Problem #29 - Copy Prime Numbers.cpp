// Problem #29/2 - Copy Prime Numbers in Array
#include <iostream>
#include <cstdlib>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime checkPrime(int number)
{
    if (number == 1)
        return enPrimeNotPrime::NotPrime;
    int m = sqrt(number);

    for (int counter = 2; counter <= m; counter++)
    {
        if (number % counter == 0)
            return enPrimeNotPrime::NotPrime;
    }

    return enPrimeNotPrime::Prime;
}
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
void copyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (checkPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            arrDestination[counter] = arrSource[i];
            counter++;
        }
    }

    arr2Length = --counter;
}


int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    fillArrayWithRandomNumbers(arr, arrLength);
    int arr2[100], arr2Length = 0;
    copyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 Elements:\n";
    PrintArray(arr, arrLength);

    cout << "\Prime Numbers in Array 2 :\n";
    PrintArray(arr2, arr2Length);



    return 0;

}