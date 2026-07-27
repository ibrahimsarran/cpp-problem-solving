// #35/3 - Print Each Word in String
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
void PrintEachWordInString(string text)
{
	string delim = " ";
	short pos = 0;
	string sWord;
	cout << "\nYour string words are:\n\n";
	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			cout << sWord << endl;
		}

		text.erase(0, pos + delim.length());
	}
	if (text != "")
	{
		cout << text << endl;
	}
}

int main()
{
	PrintEachWordInString(ReadString());
	system("pause>0");
}