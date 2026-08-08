// #50/3 - Delete Client By Account Number
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool MarkForDelete = false;
};

string ReadAccountNumber()
{
	string s1;
	cout << "Please enter AccountNumber? ";
	cin >> s1;
	return s1;
}

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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
	vector <stClient> vClients;

	fstream myFile;

	myFile.open(FileName, ios::in);

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

bool FindClientByAccountNumber(string AccountNumber, vector <stClient>& vClients, stClient& client1)
{
	for (stClient& client : vClients)
	{
		if (client.AccountNumber == AccountNumber)
		{
			client1 = client;
			return true;
		}
	}
	return false;
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

void SaveClientDataToFile(string fileName, vector<stClient>& vClients)
{
	fstream myFile;

	myFile.open(fileName, ios::out);

	string dataLine;

	if (myFile.is_open())
	{
		for (stClient& c : vClients)
		{
			if (c.MarkForDelete == false)
			{
				dataLine = ConvertRecordToLine(c);
				myFile << dataLine << endl;
			}
		}
		myFile.close();
	}
}
bool MarkClientForDelete(string accountNumber, vector<stClient>& vClients)
{
	for (stClient& client : vClients)
	{
		if (client.AccountNumber == accountNumber)
		{
			client.MarkForDelete = true;
			return true;
		}
	}
	return false;
}


bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClientsData)
{
	stClient client;
	char answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClientsData, client))
	{
		PrintClientRecord(client);
		cout << "\n\nAre you sure you want to delete this client (Y/N) ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			MarkClientForDelete(AccountNumber, vClientsData);
			SaveClientDataToFile(ClientsFileName, vClientsData);

			vClientsData = LoadClientsDataFromFile(ClientsFileName);
			cout << "\nClient Deleted Successfully. ";

			return true;
		}
	}
	else
	{
		cout << "\nClient with AccountNumber (" << AccountNumber << ") Not Found.";
		return false;
	}
	return false;
}

int main()
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);


	system("pause>0");
	return 0;
}