// #40/3 - Join String (Overloading)
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

string JoinString(string arr[], short arrLen, const string& delim)
{
	string text = "";
	for (short i = 0; i < arrLen;i++)
	{
		text += arr[i] + delim;
		
	}
	return text.substr(0, text.length() - delim.length());
}


int main()
{
	
	vector <string> vString = { "Mohammed","Ibrahim","Omar","Abdulaziz" };
	string arrString[] = {"Mohammed","Ibrahim","Omar","Abdulaziz"};

	cout << "\nVector after join: \n";
	cout << JoinString(vString, " ");

	cout << "\n\nArray after join: " << endl;
	cout << JoinString(arrString, 4, " ");


	system("pause>0");
}