// #34/3 - Print Vowels in String
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

void PrintVowelsInString(const string& text)
{
	cout << "\nVowels in string are: ";
	for (short i = 0; i < text.length();i++)
	{
		if (IsVowel(text[i]))
		{
			cout << text[i] << "  ";
		}
	}

	
}

int main()
{
	string text = ReadString();

	PrintVowelsInString(text);
	

	system("pause>0");
}