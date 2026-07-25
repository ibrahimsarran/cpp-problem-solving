// #29/3 - Count Small/Capital Letters
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

short CountSmallLetters(string text)
{
	short counter = 0;
	for (short i = 0;i < text.length();i++)
	{
		if (islower(text[i]))
			counter++;
	}
	return counter;
}

short CountCapitalLetters(string text)
{
	short counter = 0;
	for (short i = 0;i < text.length();i++)
	{
		if (isupper(text[i]))
			counter++;
	}
	return counter;
}

int main()
{

	string text = ReadString();
	
	cout << "String Length: " << text.length() << endl;
	cout << "Capital Letters Count: " << CountCapitalLetters(text) << endl;
	cout << "Small Letters Count: " << CountSmallLetters(text) << endl;

	system("pause>0");
	return 0;
}