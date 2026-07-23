// #28/3 - Invert All Letters Case 
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

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

string InvertStringLettersCase(string text)
{
	for (short i = 0; i < text.length(); i++)
	{
		text[i] = InvertCharacterCase(text[i]);
	}
	return text;
}


int main()
{
	string text = ReadString();
	cout << "\nText after inverting all letters case:\n";
	text = InvertStringLettersCase(text);
	cout << text << endl;
	return 0;
}