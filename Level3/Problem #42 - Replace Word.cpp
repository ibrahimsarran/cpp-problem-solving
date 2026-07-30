// #42/3 - Replace Word
#include <string>
#include <iostream>
using namespace std;

string ReadStrng()
{
	string text;
	cout << "Please enter a string?\n";
	getline(cin,text);
	return text;

}

string ReplaceWordInString(string s1, string StringToReplace, string ReplaceTo)
{
	short pos = s1.find(StringToReplace);
	
	while (pos != std::string::npos)
	{
		s1 = s1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = s1.find(StringToReplace);
	}
	return s1;
}


int main()
{
	string text = ReadStrng();
	string StringToReplace = "Ibrahim";
	string ReplaceTo = "Omar";
	
	cout << "\nOriginal String:\n" << text;

	cout << "\n\nString after replace:\n";
	cout << ReplaceWordInString(text, StringToReplace, ReplaceTo);

	
	system("pause>0");
}