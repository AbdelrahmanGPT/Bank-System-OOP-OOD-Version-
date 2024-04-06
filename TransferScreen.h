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
#include "GlobalUser.h"

using namespace std;
using namespace filesystem;

class TransferScreen : protected Screen
{
private : 

	static void _PrintClient(Client ClientObject)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << ClientObject.FullName();
		cout << "\nAcc. Number : " << ClientObject.AccountNumber;
		cout << "\nBalance     : " << ClientObject.AccountBalance;
		cout << "\n___________________\n\n";

	}

	static long double _ReadTransferAmount(Client &SourceClient)
	{
		long double TransferAmount = Input_Validation::ReadLongDoubleNumber("ENTER TRANSFER AMOUNT");

		while (SourceClient.AccountBalance < TransferAmount)
		{
			TransferAmount = Input_Validation::ReadLongDoubleNumber("AMOUNT EXCEEDS YOUR BALANCE , PLEASE ENTER ANOTHER AMOUNT");
		}

		return TransferAmount;

	}

	public :

		static void ShowTransferScreen()
		{
			_DrawScreenHeader("\t TRANSFER SCREEN");

			string SourceAccountNumber = Input_Validation::ReadStringLine("ENTER ACCOUNT NUMBER YOU WANT TO TRANSFER FROM");

			while (!Client::IsClientExist(SourceAccountNumber))
			{
				SourceAccountNumber = Input_Validation::ReadStringLine("INVALID ACCOUNT NUMBER , PLEASE ENTER ANOTHER ACCOUNT NUMBER");
			}

			Client SourceClient = Client::Find(SourceAccountNumber);
			
			_PrintClient(SourceClient);

			string DestinationAccountNumber = Input_Validation::ReadStringLine("ENTER ACCOUNT NUMBER YOU WANT TO TRANSFER TO");
		
			while (!Client::IsClientExist(DestinationAccountNumber) || DestinationAccountNumber == SourceAccountNumber)
			{
				DestinationAccountNumber = Input_Validation::ReadStringLine("INVALID ACCOUNT NUMBER , ENTER ANOTHER ACCOUNT NUMBER");
			}

			Client DestinationClient = Client::Find(DestinationAccountNumber);

			_PrintClient(DestinationClient);

			long double TransferAmount = _ReadTransferAmount(SourceClient);

			if (Utility::DoYouWantToDoThisWithoutClear("ARE YOU SURE YOU WANT TO DO THIS OPERATION ?"))
			{
				if (SourceClient.TransferMoneyFromClientToClient(TransferAmount, DestinationClient , CurrentUser.UserName))
				{
					printf("\nMONEY IS TRANSFERED SUCCESSFULLY\n");
					_PrintClient(SourceClient);
					_PrintClient(DestinationClient);
				}

				else
				{
					printf("\nERROR OCCURED , TRANSFER IS FAILED :-(\n");
				}
			}
		
		}

};

