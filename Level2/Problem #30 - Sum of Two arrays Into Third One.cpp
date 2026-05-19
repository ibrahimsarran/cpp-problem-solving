// Problem #30/2 - Sum of Two arrays Into Third One
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
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";

}

void sumOfArrays(int arr1[100], int arr2[100], int arr3[100], int arrLength)
{
    
    for (int i = 0; i < arrLength; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
   
}


int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr2[100], arr3[100];
    int arrLength = readPositiveNumber("How many Elements?");

    fillArrayWithRandomNumbers(arr1, arrLength);
    fillArrayWithRandomNumbers(arr2, arrLength);

    sumOfArrays(arr1, arr2, arr3, arrLength);

    cout << "\nArray 1 Elements:\n";
    PrintArray(arr1, arrLength);

    cout << "\nArray 2 Elements:\n";
    PrintArray(arr2, arrLength);

    cout << "\nSum of Array1 and Array2: \n";
    PrintArray(arr3, arrLength);



    return 0;

}