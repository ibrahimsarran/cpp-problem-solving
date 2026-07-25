// #30/3 - CountLetter
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

char ReadCharacter()
{
	char charactr;
	cout << "\nEnter your character?\n";
	cin >> charactr;
	return charactr;
}

short CountLetter(const string& text, char WhatToCount)
{
	short counter = 0;
	for (short i = 0;i < text.length();i++)
	{
		if (WhatToCount == text[i])
			counter++;

	}
	return counter;
}

int main()
{
	string text = ReadString();
	char CharacterToCount = ReadCharacter();
	cout << "\nLetter '" << CharacterToCount << "' count = " 
		<< CountLetter(text, CharacterToCount) << endl;


	return 0;
}