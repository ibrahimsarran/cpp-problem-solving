// Problem #25/2 - Min of Random Array
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

int minNumberInArray(int arr[100], int arrlength)
{
    int min = 0;
    min = arr[0];
    for (int i = 0; i < arrlength; i++)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
        }
            

    }
    return min;
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[100];
    int arrLength;
    fillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    cout << "\nMin number is : ";
    cout << minNumberInArray(arr, arrLength) << endl;


    return 0;

}