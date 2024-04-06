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
#include "User.h"
#include "Screen.h"

using namespace std;
using namespace filesystem;

class AddNewUserScreen : protected Screen
{
private :

	static void _ReadUserInfo(User& UserObject)
	{
		UserObject.FirstName = Input_Validation::ReadStringLine("ENTER FIRST NAME");
		UserObject.LastName = Input_Validation::ReadStringLine("ENTER LAST NAME");
		UserObject.Email = Input_Validation::ReadEmailAddress("ENTER EMAIL ADDRESS");
		UserObject.PhoneNumber = Input_Validation::ReadFullPhoneNumber("ENTER PHONE KEY", "ENTER PHONE NUMBER");
		UserObject.Password = Input_Validation::ReadStringLine("ENTER PASSWORD");
		UserObject.Permissions = _ReadUserPermissions();
	}

	static void _PrintUserInfo(User& UserObject)
	{
		printf("\nUSER INFO : \n");
		printf("_______________________________\n");
		printf("USER NAME     : %s\n", UserObject.UserName.c_str());
		printf("FIRST NAME    : %s\n", UserObject.FirstName.c_str());
		printf("LAST NAME     : %s\n", UserObject.LastName.c_str());
		printf("FULL NAME     : %s\n", UserObject.FullName().c_str());
		printf("EMAIL ADDRESS : %s\n", UserObject.Email.c_str());
		printf("PHONE NUMBER  : %s\n", UserObject.PhoneNumber.c_str());
		printf("PASSWORD      : %s\n", UserObject.Password.c_str());
		printf("PERMISSIONS   : %d\n", UserObject.Permissions);
		printf("_______________________________\n");
	}

	static void _DoYouWantToGiveAccessTo(string Message, User::MainMenuPersmissions MainMenuPersmission, int& Permissions)
	{
		if (Utility::DoYouWantToDoThisWithoutClear("\n" + Message))
		{
			Permissions += MainMenuPersmission;
		}
	}

	static int _ReadUserPermissions()
	{

		printf("\nENTER PERMISSIONS : \n");

		int Permissions = 0;

		if (Utility::DoYouWantToDoThisWithoutClear("DO YOU WANT TO GIVE FULL ACCESS ?"))
		{
			return Permissions = -1;
		}

		printf("\nDO YOU WANT TO GIVE ACCESS TO : \n");
		_DoYouWantToGiveAccessTo("SHOW CLIENT LIST ?" , User::pListClients , Permissions);
		_DoYouWantToGiveAccessTo("ADD NEW CLIENT ?" , User::pAddNewClients , Permissions);
		_DoYouWantToGiveAccessTo("DELETE CLIENT ?" , User::pDeleteClients , Permissions);
		_DoYouWantToGiveAccessTo("UPDATE CLIENT ?" , User::pUpdateClients , Permissions);
		_DoYouWantToGiveAccessTo("FIND CLIENT ?" , User::pFindClients , Permissions);
		_DoYouWantToGiveAccessTo("TRANSACTIONS ?" , User::pTransactions , Permissions);
		_DoYouWantToGiveAccessTo("MANAGE USERS ?" , User::pManageUsers , Permissions);
		_DoYouWantToGiveAccessTo("SHOW LOGIN REGISTER LIST ?" , User::pShowLoginRegisterList, Permissions);
		_DoYouWantToGiveAccessTo("CURRENCY EXCHANGE MAIN SCREEN ?", User::pCurrencyExchangeMainScreen, Permissions);

		return Permissions;

	}


public : 

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t ADD NEW USER SCREEN");

		string UserName = Input_Validation::ReadStringLine("ENTER NEW USER NAME");

		while (User::IsUserExist(UserName))
		{
			UserName = Input_Validation::ReadStringLine("USER NAME EXIST , ENTER ANOTHER USER NAME");
		}

		User NewUserObject = User::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUserObject);

		User::SaveResults SaveResult = NewUserObject.SaveUsersData();

		switch (SaveResult)
		{
		case User::SaveFailedEmptyObject:
			printf("\nERROR ACCOUNT ADDING FAILED , EMPTY OBJECT\n\n");
			break;
		case User::SaveSucceeded:
			printf("\nACCOUNT IS ADDED SUCCESSFULLY :-)\n\n");
			_PrintUserInfo(NewUserObject);
			break;
		case User::SaveFailedAccountExist:
			printf("\nACCOUNT ADDING IS FAILED , ACCOUNT IS ALREADY EXIST\n\n");
			break;
		
		}
	}

};

