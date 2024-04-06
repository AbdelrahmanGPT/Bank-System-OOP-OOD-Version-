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
#include "CurrenciesListScreen.h"
#include "FindCurrencyScreen.h"
#include "UpdateCurrencyRateScreen.h"
#include "CurrencyCalculatorScreen.h"

using namespace std;
using namespace filesystem;

class CurrencyExchangeMainScreen : protected Screen
{
private :

	enum CurrencyExchangeMainScreenChoices {ListCurrencies = 1 , FindCurrency = 2 
										    , UpdateRate = 3 , CurrencyCalculator = 4 , 
											MainScreen = 5};

	static CurrencyExchangeMainScreenChoices _ReadCurrencyExchangeMainScreenChoice()
	{
		return (CurrencyExchangeMainScreenChoices)Input_Validation::ValidateNumberInRange(1, 5, "CHOOSE WHAT DO YOU WANT TO DO [1 TO 5] ?");
	}

	static void _ShowListCurrenciesScreen()
	{
		CurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{ 
		FindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		UpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		CurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMainScreen()
	{
		Utility::GoToPauseMessage("\nPRESS ANY KEY TO GO BACK TO CURRENCY EXCHANGE MAIN SCREEN");
		ShowCurrencyExchangeMainScreen();
	}

	static void _PerformCurrencyExchangeMainScreenChoice(CurrencyExchangeMainScreenChoices CurrencyExchangeMainScreenChoice)
	{
		switch (CurrencyExchangeMainScreenChoice)
		{
		case CurrencyExchangeMainScreen::ListCurrencies:
			Utility::ClearScreen();
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case CurrencyExchangeMainScreen::FindCurrency:
			Utility::ClearScreen();
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case CurrencyExchangeMainScreen::UpdateRate:
			Utility::ClearScreen();
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case CurrencyExchangeMainScreen::CurrencyCalculator:
			Utility::ClearScreen();
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		case CurrencyExchangeMainScreen::MainScreen:
			break;
		}
	}

public :

	static void ShowCurrencyExchangeMainScreen()
	{
		if (!_CheckAccessRights(User::pCurrencyExchangeMainScreen))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader(" \tCurrancy Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchangeMainScreenChoice(_ReadCurrencyExchangeMainScreenChoice());
	}
};

