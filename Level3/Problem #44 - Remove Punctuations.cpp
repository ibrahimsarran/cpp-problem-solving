// #45/3 - Remove Punctuations
#include <string>
#include <iostream>
using namespace std;

string RemovePunc(string s1)
{
	string s2 = "";

	for (short i = 0; i < s1.length();i++)
	{
		if (!ispunct(s1[i]))
		{
			s2 += s1[i];
		}
	}
	return s2;
}



int main()
{
	string s1 = "I'm Ibrahim from Yemen , Yemen is a, nice country.\n";


	cout << "Original String:\n" << s1;
	cout << "\nString after remove:\n" << RemovePunc(s1);


	system("pause>0");

	return 0;
}