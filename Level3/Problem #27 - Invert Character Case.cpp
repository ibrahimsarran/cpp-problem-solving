// #27/3 - Invert Character Case 
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

char ReadChar()
{
	char character;
	cout << "Please enter a char?\n";
	cin >> character;
	return character;
}

char InvertCharacterCase(char character)
{
	return isupper(character) ? tolower(character) : toupper(character);
}


int main()
{
	char character = ReadChar();
	cout << "\Char after inverting case:\n";
	character = InvertCharacterCase(character);
	cout << character << endl;

	
	return 0;
}