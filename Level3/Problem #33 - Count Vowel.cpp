// #33/3 - Count Vowel
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string ReadString()
{
	string text;
	cout << "Enter a text?\n";
	getline(cin,text);
	return text;
}

bool IsVowel(char character)
{
	character = tolower(character);

	return ((character == 'a') || (character == 'e') || (character == 'i') || (character
		== 'o') || (character == 'u'));
}

short CountVowelInString(const string& text)
{
	short counter = 0;

	for (short i = 0; i < text.length();i++)
	{
		if (IsVowel(text[i]))
		{
			counter++;
		}
	}

	return counter;
}

int main()
{
	string text = ReadString();

	cout << "Number of vowels is: " << CountVowelInString(text) << endl;

	system("pause>0");
}