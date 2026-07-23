// #23/3 - First Letter of Each Word
#include<iostream>
#include<string>

using namespace std;

string ReadString()
{
	string text;
	cout << "Enter your text?\n";
	getline(cin, text);
	return text;
}

void PrintFirstLetters(string text)
{
	bool isFirstLetter = true;

	cout << "\nFirst Letters of this text: \n";

	for (short i = 0; i < text.length(); i++)
	{
		if (text[i] != ' ' && isFirstLetter)
		{
			cout << text[i] << endl;
		}

		isFirstLetter = (text[i] == ' ' ? true : false);
	}
}

int main()
{

	PrintFirstLetters(ReadString());
	

	return 0;
}