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
#include "DepositeScreen.h"
#include "WithdrawScreen.h"
#include "TotalBalancesScreen.h"
#include "User.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"

using namespace std;
using namespace filesystem;


class TransactionsScreen : protected Screen
{
private : 

	enum TransactionMenuChoices {Deposite = 1 , Withdraw = 2 , ShowTotalBalances = 3 ,
								 Transfer = 4 , TransferLog = 5 , ShowMainMenu = 6};

	static TransactionMenuChoices _ReadTransactionMenuChoice()
	{
		return (TransactionMenuChoices)(Input_Validation::ValidateNumberInRange(1, 6, "WHAT DO YOU WANT TO DO [1 TO 6] ?"));
	}

	static void _ShowDepositeScreen()
	{
		DepositeScreen::ShowDepositeScreen();
	}

	static void _ShowWithdrawScreen()
	{
		WithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalances()
	{
		TotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		TransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		TransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactionMenuChoice(TransactionMenuChoices TransactionMenuChoice)
	{
		switch (TransactionMenuChoice)
		{
		case TransactionsScreen::Deposite:
			Utility::ClearScreen();
			_ShowDepositeScreen();
			Utility::GoToPauseMessage("PRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU");
			ShowTransactionsScreen();
			break;
		case TransactionsScreen::Withdraw:
			Utility::ClearScreen();
			_ShowWithdrawScreen();
			Utility::GoToPauseMessage("PRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU");
			ShowTransactionsScreen();
			break;
		case TransactionsScreen::ShowTotalBalances:
			Utility::ClearScreen();
			_ShowTotalBalances();
			Utility::GoToPauseMessage("PRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU");
			ShowTransactionsScreen();
			break;
		case TransactionsScreen::Transfer:
			Utility::ClearScreen();
			_ShowTransferScreen();
			Utility::GoToPauseMessage("PRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU");
			ShowTransactionsScreen();
			break;
		case TransactionsScreen::TransferLog:
			Utility::ClearScreen();
			_ShowTransferLogScreen();
			Utility::GoToPauseMessage("PRESS ANY KEY TO GO BACK TO TRANSACTIONS MENU");
			ShowTransactionsScreen();
			break;
		case TransactionsScreen::ShowMainMenu:
			break;
		}
	}

public : 

	static void ShowTransactionsScreen()
	{

		if (!_CheckAccessRights(User::pTransactions))
		{
			return;
		}


		Utility::ClearScreen();

		_DrawScreenHeader("\t TRANSACTIONS SCREEN");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionMenuChoice(_ReadTransactionMenuChoice());
	}

};

