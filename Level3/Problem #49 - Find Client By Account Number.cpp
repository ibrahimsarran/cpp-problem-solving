// #49/3 - Find Client By Account Number
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
const string ClientsFileName = "Clients.txt";

string ReadAccountNumber()
{
	string s1;
	cout << "Please enter AccountNumber? ";
	cin >> s1;
	return s1;
}

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

void PrintClientRecord(const stClient& client)
{
	cout << "\nThe following are the client details:\n\n";
	cout << "Account Number   : " << client.AccountNumber << endl;
	cout << "Pin Code         : " << client.PinCode << endl;
	cout << "Name             : " << client.Name << endl;
	cout << "Phone            : " << client.Phone << endl;
	cout << "Account Balance  : " << client.AccountBalance << endl;
}

bool FindClientByAccountNumber(string AccountNumber,  stClient& client1)
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);

	for (stClient client : vClients)
	{
		if (client.AccountNumber == AccountNumber)
		{
			client1 = client;
			return true;
		}
	}
	return false;
}

int main()
{
	stClient client;
	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, client))
	{
		PrintClientRecord(client);
	}
	else
	{
		cout << "\nClient with AccountNumber (" << AccountNumber << ") Not Found.";
	}

	system("pause>0");
	return 0;
}