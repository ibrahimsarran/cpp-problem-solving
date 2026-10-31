// #63-64/4 - Read/Print Date String
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

string dateToString(stDate date, const string& separator = "/")
{
	string stDateLine = "";

	stDateLine += to_string(date.day) + separator;
	stDateLine += to_string(date.month) + separator;
	stDateLine += to_string(date.year);

	return stDateLine;
}

int main()
{
	string dateString = readDateString();
	stDate dateSt = stringToDate(dateString);

	cout << "\nDay:" << dateSt.day << endl;
	cout << "Month:" << dateSt.month << endl;
	cout << "Year:" << dateSt.year << endl;

	cout << "\nYou Entered: " << dateString << endl;
	


	system("pause>0");
	return 0;
}