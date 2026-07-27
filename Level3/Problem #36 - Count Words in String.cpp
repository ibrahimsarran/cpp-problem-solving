// #36/3 - Count Words in String
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

int CountEachWordInString(string text)
{
	const string delim = " ";
	short pos = 0;
	string sWord;
	short counter = 0;

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			counter++;
		}

		text.erase(0, pos + delim.length());
	}
	if (text != "")
	{
		counter++;
	}

	return counter;
}

int main()
{
	string text = ReadString();

	cout << "\nThe number of words in your string: ";
	cout << CountEachWordInString(text) << endl;

	system("pause>0");
}