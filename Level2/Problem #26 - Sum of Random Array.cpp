// Problem #26/2 - Sum of Random Array
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

int sumNumbersInArray(int arr[100], int arrlength)
{
    int sum = 0;
    
    for (int i = 0; i < arrlength; i++)
    {
        sum += arr[i];

    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    fillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    cout << "\nSum numbers are : ";
    cout << sumNumbersInArray(arr, arrLength) << endl;


    return 0;

}