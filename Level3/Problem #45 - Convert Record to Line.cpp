// #45/3 - Convert Record to Line
#include <string>
#include <iostream>
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

string ConvertRecordToLine(stClient client, string seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += client.AccountNumber + seperator;
	stClientRecord += client.PinCode + seperator;
	stClientRecord += client.Name + seperator;
	stClientRecord += client.Phone + seperator;
	stClientRecord += to_string(client.AccountBalance);

	return stClientRecord;

}

int main()
{
	stClient client;

	cout << "\nPlease Enter Client Data:\n\n";
	client = ReadNewClient();

	cout << "\nClient Record for saving is:\n\n";
	cout<<ConvertRecordToLine(client);


	system("pause>0");

	return 0;
}