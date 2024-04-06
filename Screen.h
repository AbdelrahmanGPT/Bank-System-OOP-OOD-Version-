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
#include "User.h"
#include "GlobalUser.h"


using namespace std;
using namespace filesystem;

class Screen
{
protected : 
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        printf("\n\t\t\t\t\tUSER : %s\n", CurrentUser.UserName.c_str());
        printf("\t\t\t\t\tDATE : %s\n", ::Date::GetSystemDateInStringForm().c_str());
	}

    static bool _CheckAccessRights(User::MainMenuPersmissions MainMenuPersmission)
    {
        if (!CurrentUser.CheckAccessPermission(MainMenuPersmission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";

            return false;
        }

        return true;
    }

};

