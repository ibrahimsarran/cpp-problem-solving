// #39/3 - Join String
#include <string>
#include <iostream>
#include <vector>
using namespace std;


string JoinString(vector <string>& vString, const string& delim)
{
	string text = "";

	for (const string& word : vString)
	{
		text += word + delim;
	}

	return text.substr(0, text.length() - delim.length());
}

int main()
{
	vector <string> vString = { "Mohammed","Ibrahim","Omar","Abdulaziz" };
	cout << "\nVector after join: " << endl;
	cout << JoinString(vString, "--") << endl;


	system("pause>0");
}