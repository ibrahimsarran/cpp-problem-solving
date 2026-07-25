// #31/3 - Count Letters (Match Case)
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

enum enLetterCase { CaseSensitive = 0, CaseInsensitive = 1 };

string ReadString()
{
	string text;
	cout << "Enter your text?\n";
	getline(cin, text);
	return text;
}

char InvertCharacterCase(char character)
{
	return isupper(character) ? tolower(character) : toupper(character);
}

char ReadCharacter()
{
	char charactr;
	cout << "\nEnter your character?\n";
	cin >> charactr;
	return charactr;
}

short CountLetter(const string& text, char character, enLetterCase LetterCase)
{
	short counter = 0;
	char UpperCharacter = toupper(character);
	for (short i = 0;i < text.length();i++)
	{
		if (LetterCase == enLetterCase::CaseSensitive && character == text[i])
			counter++;

		else if (LetterCase == enLetterCase::CaseInsensitive && UpperCharacter == toupper(text[i]))
			counter++;

	}
	return counter;
}

int main()
{
	string text = ReadString();
	char Character = ReadCharacter();
	short CaseSensitiveCount = CountLetter(text, Character, enLetterCase::CaseSensitive);
	short CaseInsensitiveCount = CountLetter(text, Character, enLetterCase::CaseInsensitive);
	cout << "\nLetter '" << Character << "' count = " << CaseSensitiveCount << endl;
	cout << "\nLetter '" << Character << "' or '" << InvertCharacterCase(Character) << "' count = " << CaseInsensitiveCount << "" << endl;

	system("pause>0");
}