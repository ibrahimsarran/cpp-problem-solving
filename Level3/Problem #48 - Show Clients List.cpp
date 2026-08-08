// #48/3 - Show Clients List
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

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

vector <string> SplitString(string s1, const string& delim)
{
	short pos = 0;
	vector <string> vString;
	string sWord;

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

vector <stClient> LoadClientsDataFromFile(string fileName)
{
	vector <stClient> vClients;

	fstream myFile;

	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{
		string line;
		stClient client;
		while (getline(myFile, line))
		{
			client = ConvertLineToRecord(line);
			vClients.push_back(client);
		}
		myFile.close();
	}
	return vClients;
}

void PrintClientRecord(stClient client)
{
	cout << "| " << setw(15) << left << client.AccountNumber;
	cout << "| " << setw(10) << left << client.PinCode;
	cout << "| " << setw(40) << left << client.Name;
	cout << "| " << setw(12) << left << client.Phone;
	cout << "| " << setw(12) << left << client.AccountBalance;
}

void PrintClientsData(vector <stClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
	cout <<"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (stClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

int main()
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	PrintClientsData(vClients);


	system("pause>0");
	return 0;
}