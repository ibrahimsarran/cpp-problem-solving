// #47/3 - Add Clients To File
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
};

stClient ReadNewClient()
{
	stClient client;


	cout << "Enter Account Number? ";
	getline(cin >> ws, client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, client.PinCode);

	cout << "Enter Client Name? ";
	getline(cin, client.Name);

	cout << "Enter Phone Number? ";
	getline(cin, client.Phone);

	cout << "Enter Account Balance? ";
	cin >> client.AccountBalance;
	cin.ignore();

	return client;
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

void AddClientToFile(string fileName, string stDataLine)
{
	fstream myFile;
	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{
		myFile << stDataLine << endl;

		myFile.close();
	}
}

void AddNewClient()
{
	stClient client = ReadNewClient();
	AddClientToFile(ClientsFileName, ConvertRecordToLine(client));

}

void AddClients()
{
	char AddMore = 'Y';

	while (toupper(AddMore) == 'Y')
	{
		system("cls");
		cout << "Add new Clients:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients (Y/N) ? ";
		cin >> AddMore;
	}
}

int main()
{

	AddClients();

	system("pause>0");
}