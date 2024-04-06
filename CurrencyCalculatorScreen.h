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
#include "Currency.h"

using namespace std;
using namespace filesystem;

class CurrencyCalculatorScreen : protected Screen
{
private :

    static  void _PrintCurrencyCard(Currency CurrencyObject)
    {

        cout << "\n" << "Currency Card : " << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << CurrencyObject.Country;
        cout << "\nCode          : " << CurrencyObject.CurrencyCode;
        cout << "\nName          : " << CurrencyObject.CurrencyName;
        cout << "\nRate(1$) =    : " << CurrencyObject.Rate;
        cout << "\n_____________________________\n\n";

    }

    static Currency _ReadCurrencyCodeAndReturnCurrency(string Message)
    {
        string CurrencyCode = Input_Validation::ReadStringLine(Message);

        while (!Currency::IsCurrencyExist(CurrencyCode))
        {
            CurrencyCode = Input_Validation::ReadStringLine("INVALID CURRENCY CODE , " + Message);
        }

        return Currency::FindCurrencyByCurrencyCode(CurrencyCode);
    }

public :

	static void ShowCurrencyCalculatorScreen()
	{
		do
		{
            Utility::ClearScreen();
            _DrawScreenHeader("\t CURRENCY CALCULATOR SCREEN");
            
            Currency Currency1 = _ReadCurrencyCodeAndReturnCurrency("ENTER CURRENCY 1 (FROM)");
            _PrintCurrencyCard(Currency1);

            Currency Currency2 = _ReadCurrencyCodeAndReturnCurrency("ENTER CURRENCY 2 (TO)");
            _PrintCurrencyCard(Currency2);

            long double ExchangeAmount = Input_Validation::ReadLongDoubleNumber("ENTER EXCHANGE AMOUNT");
            long double AmountAfterExchange = Currency1.CurrencyExchange(Currency2, ExchangeAmount);

            printf("\n%.1lf %s = %.2lf %s\n", ExchangeAmount, Currency1.CurrencyCode.c_str(), AmountAfterExchange, Currency2.CurrencyCode.c_str());

        } while (Utility::DoYouWantToDoThisWithClear("DO YOU WANT TO PERFORM ANOTHER CALCULATION ?"));
	}

};

