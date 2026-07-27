// #37/3 - Split String
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ReadString()
{
	string text;
	cout << "Please Enter Your String?\n";
	getline(cin, text);
	return text;
}

vector <string> SplitString(string text, const string& delim)
{
	vector <string> vWords;
	short pos = 0;
	string sWord;

	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);

		if (sWord != "")
		{
			vWords.push_back(sWord);
		}

		text.erase(0, pos + delim.length());
	}

	if (text != "")
	{
		vWords.push_back(text);
	}
	return vWords;
}

int main()
{
	string text = ReadString();
	vector <string> vWords = SplitString(text, " ");
	cout << "\nTokens = " << vWords.size() << endl;
	for (const string& word : vWords)
	{
		cout << word << endl;
	}

	system("pause>0");
}