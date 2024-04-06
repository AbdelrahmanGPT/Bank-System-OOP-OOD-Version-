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
#include "User.h"

using namespace std;
using namespace filesystem;

class AddNewClientScreen : protected Screen
{
private : 
	static void _ReadClientInfo(Client& ClientObject)
	{
		ClientObject.FirstName = Input_Validation::ReadStringLine("ENTER FIRST NAME");
		ClientObject.LastName = Input_Validation::ReadStringLine("ENTER LAST NAME");
		ClientObject.Email = Input_Validation::ReadEmailAddress("ENTER EMAIL ADDRESS");
		ClientObject.PhoneNumber = Input_Validation::ReadFullPhoneNumber("ENTER PHONE KEY", "ENTER PHONE NUMBER");
		ClientObject.Pincode = Input_Validation::ReadStringLine("ENTER PINCODE");
		ClientObject.AccountBalance = Input_Validation::ReadLongDoubleNumber("ENTER ACCOUNT BALANCE");
	}

	static void _PrintClientInfo(Client& ClientObject)
	{
		printf("\nCLIENT INFO : \n");
		printf("_______________________________\n");
		printf("ACCOUNT NUMBER : %s\n", ClientObject.AccountNumber.c_str());
		printf("FIRST NAME     : %s\n", ClientObject.FirstName.c_str());
		printf("LAST NAME      : %s\n", ClientObject.LastName.c_str());
		printf("FULL NAME      : %s\n", ClientObject.FullName().c_str());
		printf("EMAIL ADDRESS  : %s\n", ClientObject.Email.c_str());
		printf("PHONE NUMBER   : %s\n", ClientObject.PhoneNumber.c_str());
		printf("PASSWORD       : %s\n", ClientObject.Pincode.c_str());
		printf("BALANCE        : %lf\n",ClientObject.AccountBalance);
		printf("_______________________________\n");
	}

public : 


	static void ShowAddNewClientScreen()
	{
		if (!_CheckAccessRights(User::pAddNewClients))
		{
			return;
		}


		_DrawScreenHeader("\t ADD NEW CLIENT SCREEN");
		
		string AccountNumber = Input_Validation::ReadStringLine("ENTER ACCOUNT NUMBER");
		
		while (Client::IsClientExist(AccountNumber))
		{
			AccountNumber = Input_Validation::ReadStringLine("ACCOUNT EXIST , ENTER ANOTHER ACCOUNT NUMBER");
		}

		Client NewClientObject = Client::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClientObject);

		_PrintClientInfo(NewClientObject);

		Client::SaveResults SaveResult =  NewClientObject.SaveClientsData();

		switch (SaveResult)
		{
		case Client::SaveFailedEmptyObject:
			printf("\nACCOUNT IS NOT ADDED , AS IT'S EMPTY OBJECT\n\n");
			break;
		case Client::SaveSucceeded:
			printf("\nACCOUNT IS ADDED SUCCESSFULLY :-)\n\n");
			_PrintClientInfo(NewClientObject);
			break;
		case Client::SaveFailedAccountExist:
			printf("\nACCOUNT IS NOT ADDED , AS ACCOUNT EXIST\n\n");
			break;
		}
	}

};

