// #25/3 - Lower First Letter of Each Word
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

string LowerFirstLetterOfEachWorld(string text)
{
	bool isFirstLetter = true;

	for (short i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ' && isFirstLetter)
		{
			text[i] = tolower(text[i]);
		}

		isFirstLetter = (text[i] == ' ' ? true : false);
	}
	return text;
}

int main()
{
	string text = ReadString();
	text = LowerFirstLetterOfEachWorld(text);

	cout << "\nText after conversion:\n";
	cout << text << endl;
	return 0;
}