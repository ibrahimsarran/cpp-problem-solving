// #38/3 - TrimLeft, TrimRight, Trim.
#include <string>
#include <iostream>


using namespace std;

string ReadString()
{
	string text;
	cout << "Please Enter Your String?\n";
	getline(cin, text);
	return text;
}

string TrimLeft(string text)
{
	for (short i = 0; i < text.length();i++)
	{
		if (text[i] != ' ')
		{
			return text.substr(i, text.length() - i);
		}
	}

	return "";
}

string TrimRight(string text)
{
	for (short i = text.length() - 1; i >= 0;i--)
	{
		if (text[i] != ' ')
		{
			return text.substr(0, i + 1);
		}
	}

	return "";
}

string Trim(string text)
{
	return TrimLeft(TrimRight(text));
}

int main()
{
	string text = ReadString();

	cout << "\nTrim Left = " << TrimLeft(text) << endl;
	cout << "\nTrim Right = " << TrimRight(text) << endl;
	cout << "\nTrim = " << Trim(text) << endl;


	system("pause>0");
}

