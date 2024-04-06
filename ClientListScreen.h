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
#include "Client.h"
#include "Screen.h"
#include "User.h"


using namespace std;
using namespace filesystem;

class ClientListScreen : protected Screen
{
private :

    static void PrintClientRecordLine(Client ClientObject)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << ClientObject.AccountNumber;
        cout << "| " << setw(20) << left << ClientObject.FullName();
        cout << "| " << setw(12) << left << ClientObject.PhoneNumber;
        cout << "| " << setw(20) << left << ClientObject.Email;
        cout << "| " << setw(10) << left << ClientObject.Pincode;
        cout << "| " << setw(12) << left << ClientObject.AccountBalance;

    }

public : 

    static void ShowClientsList()
    {

        if (!_CheckAccessRights(User::pListClients))
        {
            return;
        }

        Utility::ClearScreen();
        vector <Client> vClients = Client::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (Client Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

