// #26/3 - Upper/Lower All Letters of String
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

string UpperAllLetters(string text)
{

	for (short i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	return text;
}

string LowerAllLetters(string text)
{

	for (short i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}
	return text;
}

int main()
{
	string text = ReadString();

	text = LowerAllLetters(text);
	cout << "\nText after lower:\n";
	cout << text << endl;

	text = UpperAllLetters(text);
	cout << "\nText after upper:\n";
	cout << text << endl;

	return 0;
}