#pragma once
#pragma warning (disable : 4996)

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<string>
#include<array>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<limits>
#include<vector>
#include<fstream>
#include<cstdio>
#include<stdexcept>
#include<filesystem>
#include<regex>
#include"Date.h"
#include "String.h" 
#include "Period.h" 
#include "Utility.h"
#include "Input_Validation.h"
#include "Screen.h"
#include "Client.h"

using namespace std;
using namespace filesystem;

class TransferLogScreen : protected Screen
{
private :

    static void PrintTransferLogRecordLine(Client::TransferLogStructure TransferLogStructurev)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogStructurev.DateTimeString;
        cout << "| " << setw(8) << left << TransferLogStructurev.SourceClientAccountNumber;
        cout << "| " << setw(8) << left << TransferLogStructurev.DestinationClientAccountNumber;
        cout << "| " << setw(8) << left << TransferLogStructurev.TransferAmount;
        cout << "| " << setw(10) << left << TransferLogStructurev.SourceClientAccountBalance;
        cout << "| " << setw(10) << left << TransferLogStructurev.DestinationClientAccountBalance;
        cout << "| " << setw(8) << left << TransferLogStructurev.UserName;


    }

public :

	static void ShowTransferLogScreen()
	{
        vector <Client::TransferLogStructure> vTransferLogRecord = Client::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (Client::TransferLogStructure Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}


};

