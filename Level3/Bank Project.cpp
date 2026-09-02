// #Project 3 - Bank
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenu();
void ShowTransactionsMenu();

enum enTransactionsMenu
{
	eDeposit = 1,
	eWithdraw = 2,
	eTotalBalance = 3,
	eMainMenu = 4
};

enum enMainMenuOptions
{
	eShowClientList = 1, eAddNewClient = 2, eDeleteClient = 3,
	eUpdateClient = 4, eFindClient = 5, eTransactionsMenu = 6, eExit = 7
};

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
	bool MarkForDelete = false;
};

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
	vector<string> vClients = SplitString(line, separator);

	client.AccountNumber = vClients[0];
	client.PinCode = vClients[1];
	client.Name = vClients[2];
	client.Phone = vClients[3];
	client.AccountBalance = stod(vClients[4]);

	return client;
}


string ConvertRecordToLine(stClient client, const string& separator = "#//#")
{
	string strClientRecord = "";

	strClientRecord += client.AccountNumber + separator;
	strClientRecord += client.PinCode + separator;
	strClientRecord += client.Name + separator;
	strClientRecord += client.Phone + separator;
	strClientRecord += to_string(client.AccountBalance);

	return strClientRecord;
}

bool ClientExistsByAccountNumber(string accountNumber, string fileName)
{
	vector<stClient> vClients;
	fstream myFile;

	myFile.open(fileName, ios::in);

	if (myFile.is_open())
	{
		string line;
		stClient client;

		while (getline(myFile, line))
		{
			client = ConvertLineToRecord(line);

			if (client.AccountNumber == accountNumber)
			{
				myFile.close();
				return true;
			}

		}

		myFile.close();
	}
	return false;
}

vector<stClient> LoadClientsFromFile(string fileName)
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



stClient ReadNewClient()
{
	stClient client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, client.AccountNumber);

	while (ClientExistsByAccountNumber(client.AccountNumber, ClientsFileName))
	{
		cout << "Client with Account Number ( " << client.AccountNumber << " ) already exists , Enter anoter Account Number? ";
		getline(cin >> ws, client.AccountNumber);
	}

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


void AddDataLineToFile(string fileName, string dataLine)
{
	fstream myFile;

	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{
		myFile << dataLine << endl;

		myFile.close();
	}
}



void AddNewClient()
{

	stClient client;
	client = ReadNewClient();

	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(client));

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

string ReadAccountNumber()
{
	string AccountNumber = " ";

	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

void AddNewClients()
{
	char AddMore = 'Y';
	do
	{
		cout << "\nAdding new clients:\n\n";
		AddNewClient();

		cout << "\nClient Added Successfully, do you want to add more clients (Y/N) ? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');



}


enTransactionsMenu ReadTransactionsMenuOption()
{
	short option = 0;
	do
	{
		cout << "Choose what do you want to do? [1 to 4]?  ";
		cin >> option;

	} while (option < 1 || option>4);

	return (enTransactionsMenu)option;
}

enMainMenuOptions ReadMainMenuOption()
{
	short choice = 0;
	do
	{
		cout << "Choose what do you want to do? [1 to 7]?  ";
		cin >> choice;

	} while (choice < 1 || choice>7);

	return (enMainMenuOptions)choice;
}

void PrintClientInfo(const stClient& client)
{
	cout << "\nThe following are the client details:\n\n";
	cout << "===================================================\n";
	cout << "Account Number   : " << client.AccountNumber << endl;
	cout << "Pin Code         : " << client.PinCode << endl;
	cout << "Name             : " << client.Name << endl;
	cout << "Phone            : " << client.Phone << endl;
	cout << "Account Balance  : " << client.AccountBalance << endl;
	cout << "===================================================\n";
}

bool MarkClientForDelete(string accountNumber, vector<stClient>& vClients)
{

	for (stClient& c : vClients)
	{
		if (c.AccountNumber == accountNumber)
		{
			c.MarkForDelete = true;
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
		for (stClient& client : vClients)
		{
			if (client.MarkForDelete == false)
			{
				dataLine = ConvertRecordToLine(client);
				myFile << dataLine << endl;

			}
		}
		myFile.close();
	}
}

void PrintClientBalance(const stClient& client)
{
	cout << "| " << setw(15) << left << client.AccountNumber;
	cout << "| " << setw(40) << left << client.Name;
	cout << "| " << setw(12) << left << client.AccountBalance;

}

void PrintClientRecordLine(const stClient& client)
{
	cout << "| " << setw(15) << left << client.AccountNumber;
	cout << "| " << setw(10) << left << client.PinCode;
	cout << "| " << setw(40) << left << client.Name;
	cout << "| " << setw(12) << left << client.Phone;
	cout << "| " << setw(12) << left << client.AccountBalance;

}

bool DeleteClientByAccountNumber(string accountNumber, vector<stClient>& vClients)
{
	stClient client;


	char answer = 'n';
	if (FindClientByAccountNumber(accountNumber, vClients, client))
	{
		PrintClientInfo(client);
		cout << "\nAre sure you want to delete this client (Y/N)? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			MarkClientForDelete(accountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			vClients = LoadClientsFromFile(ClientsFileName);
			cout << "\nClient Deleted Successfully.\n";
			return true;

		}
	}

	else
	{
		cout << "\nClient with AccountNumber (" << accountNumber << ") Not Found\n";
		return false;
	}

	return false;
}

bool UpdateClientByAccountNumber(string accountNumber, vector<stClient>& vClients)
{
	stClient client;
	char answer = 'n';

	if (FindClientByAccountNumber(accountNumber, vClients, client))
	{
		PrintClientInfo(client);
		cout << "\nAre sure you want to update this client? (Y/N)? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			for (stClient& client : vClients)
			{
				if (client.AccountNumber == accountNumber)

				{
					client = UpdateClientData(accountNumber);
					break;
				}

			}
			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\nClient Updated Successfully.\n";
			return true;
		}
	}

	else
	{
		cout << "\nClient with AccountNumber (" << accountNumber << ") Not Found\n";
		return false;
	}


	return false;
}

void GoBackToTransactionsMenu()
{
	cout << "\n\nPrees any key to go back to Transactions menu. . .";
	system("pause>0");
	ShowTransactionsMenu();
}

void GoBackToMainMenu()
{

	cout << "\n\nPrees any key to go back to main menu. . .";
	system("pause>0");
	ShowMainMenu();
}

void FindClient(string accountNumber, vector<stClient>& vClients)
{
	stClient client;

	if (FindClientByAccountNumber(accountNumber, vClients, client))
		PrintClientInfo(client);
	else
		cout << "\nClient with AccountNumber (" << accountNumber << ") Not Found\n";
}

void ShowFindClientScreen()
{
	cout << "===================================================\n";
	cout << "\t\tFind Clients Screen\n";
	cout << "===================================================\n";
	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);
	string accountNumber = ReadAccountNumber();

	FindClient(accountNumber, vClients);
}

void ShowAddCNewClientsScreen()
{
	cout << "===================================================\n";
	cout << "\t\tAdd New Clients Screen\n";
	cout << "===================================================\n";
	AddNewClients();
}

void ShowEndScreen()
{
	cout << "===================================================\n";
	cout << "\t\tProgram Ends :) \n";
	cout << "===================================================\n";
}

void ShowDeleteClientScreen()
{

	cout << "===================================================\n";
	cout << "\t\Delete Clients Screen\n";
	cout << "===================================================\n";

	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);
	string accountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(accountNumber, vClients);
}

void ShowUpdateClientScreen()
{

	cout << "===================================================\n";
	cout << "\t\tUpdate Clients Screen\n";
	cout << "===================================================\n";

	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);
	string accountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(accountNumber, vClients);
}

void ShowBalanceListScreen()
{
	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\Balances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double balances = 0;

	for (const stClient& client : vClients)
	{
		PrintClientBalance(client);
		balances += client.AccountBalance;

		cout << endl;
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "\t\t\t\tTotal Balances = " << balances;
}


void DepositBalanceToClientByAccountNumber(string accountNumber, double amount, vector<stClient>& vClients)
{

	char answer = 'n';
	cout << "\nAre you sure you want to perform this transaction (Y/N) ?  ";
	cin >> answer;

	if (toupper(answer) == 'Y')
	{
		for (stClient& client : vClients)
		{
			if (client.AccountNumber == accountNumber)
			{
				client.AccountBalance += amount;
				cout << "\nDone successfully. new balance = " << client.AccountBalance;
			}
		}
		SaveClientsDataToFile(ClientsFileName, vClients);
	}

}

void ShowWithdrawScreen()
{

	cout << "===================================================\n";
	cout << "\t\Withdraw Screen\n";
	cout << "===================================================\n";

	stClient client;
	string accountNumber = ReadAccountNumber();
	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);

	while (!FindClientByAccountNumber(accountNumber, vClients, client))
	{

		cout << "\nClient with Account Number ( " << accountNumber << " ) does not exist.\n";
		accountNumber = ReadAccountNumber();
	}

	PrintClientInfo(client);

	double amount = 0;
	cout << "\nPlease enter withdraw amount? ";
	cin >> amount;

	while (amount > client.AccountBalance)
	{
		cout << "\nAmount exceeds the balance, you can withdraw up to: " << client.AccountBalance;
		cout << "\nPlease enter withdraw amount? ";
		cin >> amount;
	}

	DepositBalanceToClientByAccountNumber(accountNumber, amount * -1, vClients);

}


void ShowDepositScreen()
{

	cout << "===================================================\n";
	cout << "\t\tDeposit Screen\n";
	cout << "===================================================\n";

	stClient client;
	string accountNumber = ReadAccountNumber();
	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);

	while (!FindClientByAccountNumber(accountNumber, vClients, client))
	{
		cout << "\nClient with Account Number ( " << accountNumber << " ) does not exist.\n";
		accountNumber = ReadAccountNumber();
	}

	PrintClientInfo(client);

	double amount = 0;
	cout << "\nPlease enter deposit amount? ";
	cin >> amount;

	DepositBalanceToClientByAccountNumber(accountNumber, amount, vClients);
}

void ShowClientsListScreen()
{
	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (const stClient& Client : vClients)
	{
		PrintClientRecordLine(Client);
		cout << endl;
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PerformMainMenuOptions(enMainMenuOptions choice)
{

	switch (choice)
	{

	case enMainMenuOptions::eShowClientList:
		system("cls");
		ShowClientsListScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eAddNewClient:
		system("cls");
		ShowAddCNewClientsScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();

		break;

	case enMainMenuOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eTransactionsMenu:
		system("cls");
		ShowTransactionsMenu();
		break;

	case enMainMenuOptions::eExit:
		system("cls");
		ShowEndScreen();
		break;

	}
}

void PerformTransactionsMenuOptions(enTransactionsMenu option)
{

	switch (option)
	{

	case enTransactionsMenu::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenu();
		break;

	case enTransactionsMenu::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu();
		break;

	case enTransactionsMenu::eTotalBalance:
		system("cls");
		ShowBalanceListScreen();
		GoBackToTransactionsMenu();
		break;

	case enTransactionsMenu::eMainMenu:

		ShowMainMenu();
		break;
	}
}

void ShowTransactionsMenu()
{
	system("cls");
	cout << "===================================================\n";
	cout << "\t\tTransactions Menu Screen\n";
	cout << "===================================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "===================================================\n";

	PerformTransactionsMenuOptions(ReadTransactionsMenuOption());
}

void ShowMainMenu()
{
	system("cls");
	cout << "===================================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "===================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";
	cout << "===================================================\n";
	PerformMainMenuOptions(ReadMainMenuOption());
}

int main()
{
	ShowMainMenu();

	system("pause>0");
	return 0;
}