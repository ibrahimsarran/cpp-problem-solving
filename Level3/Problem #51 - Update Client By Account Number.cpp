// #51/3 - Update Client By Account Number
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

stClient UpdateClientData(string accountNumber)
{
	stClient client;
	client.AccountNumber = accountNumber;

	cout << "Enter PinCode? ";
	getline(cin >> ws, client.PinCode);

	cout << "Enter Client Name? ";
	getline(cin, client.Name);

	cout << "Enter Phone Number? ";
	getline(cin, client.Phone);

	cout << "Enter Account Balance? ";
	cin >> client.AccountBalance;

	return client;
}

string ReadAccountNumber()
{
	string s1;
	cout << "Please enter AccountNumber? ";
	cin >> s1;
	return s1;
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

vector<string> SplitString(string s1, const string& delim)
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

stClient ConvertLineToRecord(const string& line, const string& separator = "#//#")
{
	stClient client;
	vector<string> vClientsData = SplitString(line, separator);

	client.AccountNumber = vClientsData[0];
	client.PinCode = vClientsData[1];
	client.Name = vClientsData[2];
	client.Phone = vClientsData[3];
	client.AccountBalance = stod(vClientsData[4]);

	return client;
}

string ConvertRecordToLine(const stClient& client, string separator = "#//#")
{
	string stDataRecord = "";

	stDataRecord += client.AccountNumber + separator;
	stDataRecord += client.PinCode + separator;
	stDataRecord += client.Name + separator;
	stDataRecord += client.Phone + separator;
	stDataRecord += to_string(client.AccountBalance);

	return stDataRecord;
}

vector<stClient> LoadClientsDataFromFile(string fileName)
{
	fstream myFile;
	vector<stClient> vClients;

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

bool FindClientByAccountNumber(string accountNumber, vector<stClient>& vClients, stClient& client)
{
	for (stClient& c : vClients)
	{
		if (c.AccountNumber == accountNumber)
		{
			client = c;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(string fileName, vector<stClient>& vClients)
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

bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClientsData)
{
	stClient client;
	char answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClientsData, client))
	{
		PrintClientRecord(client);
		cout << "\nAre you sure you want update this client (Y/N) ?  ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			for (stClient& c : vClientsData)
			{
				if (c.AccountNumber == AccountNumber)
				{
					c = UpdateClientData(AccountNumber);
					break;
				}
			}

			SaveClientsDataToFile(ClientsFileName, vClientsData);
			cout << "\nClient Updated Successfully. ";

			return true;
		}

	}
	else
	{
		cout << "\nClient with this AccountNumber (" << AccountNumber << ") is not found.";
		return false;
	}

	return false;
}

int main()
{
	vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClients);


	system("pause>0");
	return 0;
}