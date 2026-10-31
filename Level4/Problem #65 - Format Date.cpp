// #65/4 - Format Date  
#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct stDate
{
	short day;
	short month;
	short year;
};



string readDateString()
{
	string date;
	cout << "\nPlease Enter Date dd/mm/yyyy? ";
	getline(cin>>ws,date);
	return date;
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

stDate stringToDate(string date)
{
	stDate dateStruct;

	vector<string> vDate = SplitString(date, "/");
	dateStruct.day = stoi (vDate[0]);
	dateStruct.month = stoi(vDate[1]);
	dateStruct.year = stoi(vDate[2]);
	
	return dateStruct;
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

string formatDate(stDate date, string dateFormat = "dd/mm/yyyy")
{
	string formattedDateString = "";

	formattedDateString = ReplaceWordInString(dateFormat, "dd", to_string(date.day));
	formattedDateString = ReplaceWordInString(formattedDateString, "mm", to_string(date.month));
	formattedDateString = ReplaceWordInString(formattedDateString, "yyyy", to_string(date.year));

	return formattedDateString;

}

int main()
{
	string dateString = readDateString();
	stDate date = stringToDate(dateString);


	cout << "\n" << formatDate(date) << endl;
	cout << "\n" << formatDate(date, "yyyy/dd/mm") << endl;
	cout << "\n" << formatDate(date, "mm/dd/yyyy") << endl;
	cout << "\n" << formatDate(date, "mm-dd-yyyy") << endl;
	cout << "\n" << formatDate(date, "dd-mm-yyyy") << endl;
	cout << "\n" << formatDate(date, "Day:dd, Month:mm, Year:yyyy") << endl;

	system("pause>0");
	return 0;
}