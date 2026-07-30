// #43/3 - Replace Word(custom)
#include <string>
#include <iostream>
#include <vector>
using namespace std;

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

string JoinString(vector <string> vString, const string& delim)
{
	string text = "";

	for (const string& word : vString)
	{
		text += word + delim;
	}

	return text.substr(0, text.length() - delim.length());
}

string LowerAllString(string s1)
{
	for (short i = 0; i < s1.length(); i++)
	{
		s1[i] = tolower(s1[i]);
	}
	return s1;
}

string ReplaceWordInStringUsingSplit(string s1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
{
	vector <string> vString = SplitString(s1, " ");

	for (string& word : vString)
	{
		if (MatchCase)
		{
			if (word == StringToReplace)
			{
				word = ReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(word) == LowerAllString(StringToReplace))
			{
				word = ReplaceTo;
			}
		}
	}
	return JoinString(vString, " ");
}


int main()
{
	string s1 = "I'm Ibrahim from Yemen , Yemen is a nice country.";
	string StringToReplace = "yemen";
	string ReplaceTo = "Saudi Arabia";
	
	cout << "\nOriginal String:\n" << s1;

	cout << "\n\nReplace with match case: \n";
	cout << ReplaceWordInStringUsingSplit(s1, StringToReplace, ReplaceTo);

	cout << "\n\nReplace without match case: \n";
	cout << ReplaceWordInStringUsingSplit(s1, StringToReplace, ReplaceTo, false);

	
	system("pause>0");
}