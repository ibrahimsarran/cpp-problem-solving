// Problem #33/2 - Fill Array With Keys
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialChar, Digit };


int readPositiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}
int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
char getRandomCharacter(enCharType type)
{
    switch (type)
    {
    case enCharType::SmallLetter:
        return (char)randomNumber(97, 122);
        break;

    case enCharType::CapitalLetter:
        return (char)randomNumber(65, 90);
        break;

    case enCharType::SpecialChar:
        return (char)randomNumber(33, 47);
        break;

    case enCharType::Digit:
        return (char)randomNumber(48, 57);
        break;

        default:
            return 0;
    }
}
string generateWord(enCharType charType, short length)

{
    string word;

    for (int i = 1; i <= length; i++)
    {
        word = word + getRandomCharacter(charType);
    }
    return word;
}
string generateKey()
{
    string key = "";
    key = generateWord(enCharType::CapitalLetter, 4) + "-";
    key += generateWord(enCharType::CapitalLetter, 4) + "-";
    key += generateWord(enCharType::CapitalLetter, 4) + "-";
    key += generateWord(enCharType::CapitalLetter, 4);

    return key;
}
void fillArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = generateKey();

    
}
void printArrayWithKeys(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << " Array [ " << i+1 << " ]: ";
        cout << arr[i] << "\n";

    }
    cout << "\n";
}
int main()
{
    srand((unsigned)time(NULL));

    string arr[100];
    int arrLength = readPositiveNumber("How many keys do you want to generate?");
    fillArrayWithKeys(arr, arrLength);
    printArrayWithKeys(arr, arrLength);


    return 0;

}