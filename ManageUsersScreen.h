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
#include "ListUsersScreen.h"
#include "AddNewUserScreen.h"
#include "DeleteUserScreen.h"
#include "UpdateUserScreen.h"
#include "FindUserScreen.h"
#include "User.h"

using namespace std;
using namespace filesystem;


class ManageUsersScreen : protected Screen
{
private : 

	enum ManageUsersMenuChoices{ListUsers = 1 , AddNewUser = 2 , DeleteUsers = 3 , 
							    UpdateUsers = 4 , FindUsers = 5 , MainMenu = 6};

	static ManageUsersMenuChoices _ReadManageUsersMenuChoice()
	{
		return (ManageUsersMenuChoices)(Input_Validation::ValidateNumberInRange(1, 6, "ENTER NUMBER BETWEEN 1 & 6"));
	}

	static void _ShowListUsersScreen()
	{
		ListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		AddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUsersScreen()
	{
		DeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsersScreen()
	{
		UpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsersScreen()
	{
		FindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenuScreen()
	{
		Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MANAGE USERS MENU...");
		ShowManageUsersMenuScreen();
	}

	static void _PerformManageUsersMenuChoice(ManageUsersMenuChoices ManageUsersMenuChoice)
	{
		switch (ManageUsersMenuChoice)
		{
		case ManageUsersScreen::ListUsers:
			Utility::ClearScreen();
			_ShowListUsersScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case ManageUsersScreen::AddNewUser:
			Utility::ClearScreen();
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case ManageUsersScreen::DeleteUsers:
			Utility::ClearScreen();
			_ShowDeleteUsersScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case ManageUsersScreen::UpdateUsers:
			Utility::ClearScreen();
			_ShowUpdateUsersScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case ManageUsersScreen::FindUsers:
			Utility::ClearScreen();
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenuScreen();
			break;
		case ManageUsersScreen::MainMenu:
			
			break;
		}
	}

public :

	static void ShowManageUsersMenuScreen()
	{
		if (!_CheckAccessRights(User::pManageUsers))
		{
			return;
		}



		Utility::ClearScreen();
		_DrawScreenHeader("\t MANAGE USERS SCREEN");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerformManageUsersMenuChoice(_ReadManageUsersMenuChoice());
	}

};

