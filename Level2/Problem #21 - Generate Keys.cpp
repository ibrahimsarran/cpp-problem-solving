// Problem #21/2 - Generate Keys
#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialChar, Digit };


int readPositiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message<<endl;
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
void generateKeys(short numberOfKeys)
{
    for (int i = 1; i <= numberOfKeys; i++)
    {
        cout << " Key [ " << i << " ]: ";
        cout << generateKey() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    
   
    generateKeys(readPositiveNumber("How many keys to generate?"));
    

    return 0;

}