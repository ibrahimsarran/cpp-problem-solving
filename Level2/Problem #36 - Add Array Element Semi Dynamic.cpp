// Problem #36/2 - Add Array Element Simi Dynamic.
#include <iostream>
using namespace std;

int readNumber()
{
    int number = 0;
    cout << "Please enter a number? ";
    cin >> number;
    
    return number;
}

void addArrayElement(int number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = number;

}

void inputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool addMore = true;

    do
    {
        addArrayElement(readNumber(), arr, arrLength);
        cout << "Do you want to add more numbers? [NO]: 0, [1]: Yes ";
        cin >> addMore;
        

    } while (addMore);
}


void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";


    cout << "\n";
}


int main()
{
    int arr[100];
    int arrLength = 0;
   
    inputUserNumbersInArray(arr, arrLength);
    
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);

 
  

    return 0;

}