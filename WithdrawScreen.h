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

using namespace std;
using namespace filesystem;

class WithdrawScreen : protected Screen
{
private :

	static string _ReadClientAccountNumber()
	{
		string AccountNumber = Input_Validation::ReadStringLine("ENTER ACCOUNT NUMBER");

		while (!Client::IsClientExist(AccountNumber))
		{
			AccountNumber = Input_Validation::ReadStringLine("INVALID ACCOUNT NUMBER , ENTER ANOTHER ONE");
		}

		return AccountNumber;
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
		printf("BALANCE        : %lf\n", ClientObject.AccountBalance);
		printf("_______________________________\n");
	}

public :

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\tWITHDRAW SCREEN");

		string AccountNumber = _ReadClientAccountNumber();

		Client ClientObject = Client::Find(AccountNumber);

		_PrintClientInfo(ClientObject);

		long double WithdrawAmount = Input_Validation::ReadLongDoubleNumber("ENTER WITHDRAW AMOUNT");

		if (Utility::DoYouWantToDoThisWithoutClear("DO YOU WANT TO PERFORM THIS OPEARATION ? "))
		{
			if (ClientObject.WithdrawMoneyInClient(WithdrawAmount))
			{
				printf("\nAMOUNT WITHDRAW SUCCESSFULLY\n");
				printf("\nNEW BALANCE IS = %lf\n" , ClientObject.AccountBalance);
			}

			else
			{
				printf("\nCAN NOT WITHDRAW , INSUFFICICENT BALANCE\n");
				printf("\nAMOUNT TO WITHDRAW = %lf\n", WithdrawAmount);
				printf("\nYOUR BALANCE = %lf\n", ClientObject.AccountBalance);
			}
		}

		else
		{
			printf("\nOPERATION IS CANCELLED :-(\n");
		}
	}
};

