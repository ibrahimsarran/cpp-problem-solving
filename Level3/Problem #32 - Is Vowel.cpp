// #32/3 - Is Vowel?
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

char ReadCharacter()
{
	char charactr;
	cout << "Enter a character?\n";
	cin >> charactr;
	return charactr;
}

bool IsVowel(char character)
{
	character = tolower(character);

	return ((character == 'a') || (character == 'e') || (character == 'i') || (character
		== 'o') || (character == 'u'));
}

int main()
{
	char character = ReadCharacter();
	

	if (IsVowel(character))
		cout << "\nYes Letter '" << character << "' is vowel\n";
	else 
		cout << "\nNo Letter '" << character << "' is not vowel\n";




	system("pause>0");
}