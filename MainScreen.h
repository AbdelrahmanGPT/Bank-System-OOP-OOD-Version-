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
#include "ClientListScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsScreen.h"
#include "ManageUsersScreen.h"
#include "GlobalUser.h"
#include "User.h"
#include "LoginRegisterScreen.h"
#include "CurrencyExchangeMainScreen.h"


using namespace std;
using namespace filesystem;

class MainScreen : protected Screen  
{
private : 

	enum MainMenuChoices {ShowClientsList = 1 , AddNewClient = 2 , DeleteClient = 3 ,
						  UpdateClientInfo = 4 , FindClient = 5 , Transactions = 6 , 
							ManageUsers = 7 , ShowLoginRegisterList = 8 , 
							CurrencyExchangeScreen = 9 , Logout = 10};
	
	static MainMenuChoices _ReadMainMenuChoice()
	{
		return (MainMenuChoices)(Input_Validation::ValidateNumberInRange(1, 10, "\t\t\t\t\tCHOOSE WHAT DO YOU WANT TO DO [1 TO 10]"));
	}

	static void _ShowAllClientsScreen()
	{
		ClientListScreen::ShowClientsList();
	}
	
	static void _ShowAddNewClientScreen()
	{
		AddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		DeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		UpdateClientScreen::ShowUpdateClientInfoScreen();
	}

	static void _ShowFindClientScreen()
	{
		FindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		TransactionsScreen::ShowTransactionsScreen();
	}

	static void _ShowManageUsersScreen()
	{
		ManageUsersScreen::ShowManageUsersMenuScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		LoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		CurrencyExchangeMainScreen::ShowCurrencyExchangeMainScreen();
	}

	static void _Logout()
	{
		CurrentUser = User::Find("", "");
		//LoginScreen::ShowLoginScreen();
		//ERROR WILL OCCUR , AS WE DID SOMETHING CALLED CIRCULAR REFERENCE
		//CIRCULAR REFERENCE : IT MEANS THAT WE CREATE CIRCULAR PROGRAM FLOW
		//CIRCULAR REFERENCE IS LIKE TOM & JERRY BOTH ARE RUNNIG AFTER EACH OTHERS
		//AND BOTH ARE RUNNING FROM EACH OTHER
		//----------->------------>---------------->-------------------
		//PROGRAM FLOW SHOULD BE LIKE THIS LIKE A LINE NOT LIKE A CIRCLE
	}

	static void _PerformMainMenuChoice(MainMenuChoices MainMenuChoice)
	{
		switch (MainMenuChoice)
		{
		case MainScreen::ShowClientsList:
			Utility::ClearScreen();
			_ShowAllClientsScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::AddNewClient:
			Utility::ClearScreen();
			_ShowAddNewClientScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::DeleteClient:
			Utility::ClearScreen();
			_ShowDeleteClientScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::UpdateClientInfo:
			Utility::ClearScreen();
			_ShowUpdateClientScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::FindClient:
			Utility::ClearScreen();
			_ShowFindClientScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::Transactions:
			Utility::ClearScreen();
			_ShowTransactionsMenu();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::ManageUsers:
			Utility::ClearScreen();
			_ShowManageUsersScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::ShowLoginRegisterList:
			Utility::ClearScreen();
			_ShowLoginRegisterScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
		case MainScreen::CurrencyExchangeScreen:
			Utility::ClearScreen();
			_ShowCurrencyExchangeScreen();
			Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO MAIN MENU...");
			ShowMainScreen();
			break;
		case MainScreen::Logout:
			Utility::ClearScreen();
			_Logout();
			break;
		}
	}

public :

	static void ShowMainScreen()
	{
		Utility::ClearScreen();
		
		_DrawScreenHeader("\t\tMAIN MENU");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register Screen.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange Screen.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
 	
		_PerformMainMenuChoice(_ReadMainMenuChoice());
	}
};

