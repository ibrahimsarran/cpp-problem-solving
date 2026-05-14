// Problem #20/2 - Random SmallLetter, CapitalLetter, SpecialChar, Digit
#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialChar, Digit };
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

int main()
{
    srand((unsigned)time(NULL));
    
    
    cout << getRandomCharacter(enCharType::SmallLetter) << endl;
    cout << getRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << getRandomCharacter(enCharType::SpecialChar) << endl;
    cout << getRandomCharacter(enCharType::Digit) << endl;

    

    return 0;

}