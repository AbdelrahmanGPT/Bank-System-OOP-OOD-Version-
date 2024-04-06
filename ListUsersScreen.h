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
#include "User.h"

using namespace std;
using namespace filesystem;

class ListUsersScreen : protected Screen
{
private:
    static void _PrintUserRecordLine(User UserObject)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << UserObject.UserName;
        cout << "| " << setw(25) << left << UserObject.FullName();
        cout << "| " << setw(12) << left << UserObject.PhoneNumber;
        cout << "| " << setw(20) << left << UserObject.Email;
        cout << "| " << setw(10) << left << UserObject.Password;
        cout << "| " << setw(12) << left << UserObject.Permissions;

    }

public:

    static void ShowUsersList()
    {
        vector <User> vUsers = User::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (User &UserObject : vUsers)
            {

                _PrintUserRecordLine(UserObject);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

