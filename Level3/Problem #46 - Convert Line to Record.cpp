// #46/3 - Convert Line to Record 
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClient ReadNewClient()
{
	stClient client;

	cout << "Enter Account Number? ";
	getline(cin, client.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, client.PinCode);

	cout << "Enter Client Name? ";
	getline(cin, client.Name);

	cout << "Enter Phone Number? ";
	getline(cin, client.Phone);

	cout << "Enter Account Balance? ";
	cin >> client.AccountBalance;

	return client;
}

vector <string> SplitString(string s1, const string& delim)
{
	short pos = 0;
	string sWord;
	vector<string> vString;

	while ((pos = s1.find(delim)) != std::string::npos)
	{
		sWord = s1.substr(0, pos);

		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		s1.erase(0, pos + delim.length());
	}
	if (s1 != "")
	{
		vString.push_back(s1);
	}

	return vString;
}

string ConvertRecordToLine(const stClient& client, const string& separator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += client.AccountNumber + separator;
	stClientRecord += client.PinCode + separator;
	stClientRecord += client.Name + separator;
	stClientRecord += client.Phone + separator;
	stClientRecord += to_string(client.AccountBalance);

	return stClientRecord;

}

stClient ConvertLineToRecord(const string& line, const string& separator = "#//#")
{
	stClient client;
	vector <string> vClientData = SplitString(line, separator);

	client.AccountNumber = vClientData[0];
	client.PinCode = vClientData[1];
	client.Name = vClientData[2];
	client.Phone = vClientData[3];
	client.AccountBalance = stod(vClientData[4]);

	return client;
}

void PrintClientRecord(const stClient& client)
{
	cout << "\n\nThe following is the extracted client record:\n\n";
	cout << "Account Number   : " << client.AccountNumber << endl;
	cout << "Pin Code         : " << client.PinCode << endl;
	cout << "Name             : " << client.Name << endl;
	cout << "Phone            : " << client.Phone << endl;
	cout << "Account Balance  : " << client.AccountBalance << endl;
}

int main()
{
	
	stClient client =  ReadNewClient();
	string line = ConvertRecordToLine(client);
	cout << "\nLine record is:\n" << line;

	stClient record =  ConvertLineToRecord(line);
	PrintClientRecord(record);


	system("pause>0");

	return 0;
}