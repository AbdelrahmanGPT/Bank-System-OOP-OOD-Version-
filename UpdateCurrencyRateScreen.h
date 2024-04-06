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

class UpdateCurrencyRateScreen : protected Screen
{
private :

    static void _PrintCurrency(Currency CurrencyObject)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << CurrencyObject.Country;
        cout << "\nCode       : " << CurrencyObject.CurrencyCode;
        cout << "\nName       : " << CurrencyObject.CurrencyName;
        cout << "\nRate(1$) = : " << CurrencyObject.Rate;

        cout << "\n_____________________________\n";

    }


public : 

    static void ShowUpdateCurrencyRateScreen()
    { 
        Utility::ClearScreen();
        _DrawScreenHeader("\t UPDATE CURRENCY RATE SCREEN");

        string CurrencyCode = Input_Validation::ReadStringLine("ENTER CURRENCY CODE ?");

        while (!Currency::IsCurrencyExist(CurrencyCode))
        {
            CurrencyCode = Input_Validation::ReadStringLine("INVALID CURRENCY CODE , ENTER ANOTHER CURRENCY CODE ?");
        }

        Currency CurrencyObject = Currency::FindCurrencyByCurrencyCode(CurrencyCode);
        _PrintCurrency(CurrencyObject);

        if (Utility::DoYouWantToDoThisWithoutClear("ARE YOU SURE YOU WANT TO UPDATE THE RATE OF THIS CURRENCY ?"))
        {
            printf("\n\nUPDATE CURRENCY RATE : \n");
            printf("_____________________________\n");

            long double NewRate = Input_Validation::ReadDoublePositiveNumber("ENTER NEW RATE FOR THE CURRENCY");
            CurrencyObject.UpdateCurrencyRate(NewRate);
            printf("\nCURRENCY RATE IS UPDATED SUCCESSFULLY :-)\n");

            _PrintCurrency(CurrencyObject);
        }

    }


};

