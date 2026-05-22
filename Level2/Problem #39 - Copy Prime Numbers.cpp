// Problem #39/2 - Copy Prime Numbers to a New Array. 
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
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
void addArrayElement(int number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = number;

}
  
void copyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (checkPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        addArrayElement(arrSource[i], arrDestination, arr2Length);
    }
}
void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Enter number of elements: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = randomNumber(1, 100);
    

    cout << endl;
}
void printArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
     

    cout << "\n";

}


int main()
{
    srand((unsigned)time(NULL));

    int arr[100];
    int arr2[100];
    int arrLength = 0, arr2Length = 0;

    fillArrayWithRandomNumbers(arr, arrLength);
    copyPrimeNumbers(arr, arr2, arrLength, arr2Length);


    cout << "\nArray 1 elements:\n";
    printArray(arr, arrLength);
    

    cout << "\nArray 2 Odd Numbers:\n";
    printArray(arr2, arr2Length);

 
  

    return 0;

}