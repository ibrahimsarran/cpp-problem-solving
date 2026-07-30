// #41/3 - Reverse Words
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadStrng()
{
	string text;
	cout << "Please enter a string?\n";
	getline(cin,text);
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

string ReverseWordsInString(string text)
{
	vector <string> vString;
	string s2;

	vString = SplitString(text, " ");
	vector<string>::iterator iter = vString.end();
	
	while (iter != vString.begin())
	{
		--iter;
		s2 += *iter + " ";
	}

	return s2.substr(0, s2.length() - 1); //remove last space
}


int main()
{
	string text = ReadStrng();
	

	cout << "\nString after reversing words:\n";
	cout << ReverseWordsInString(text);


	system("pause>0");
}