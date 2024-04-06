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

class CurrenciesListScreen : protected Screen
{
private :
    static void PrintCurrencyRecordLine(Currency CurrencyObject)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << CurrencyObject.Country;
        cout << "| " << setw(8) << left << CurrencyObject.CurrencyCode;
        cout << "| " << setw(45) << left << CurrencyObject.CurrencyName;
        cout << "| " << setw(10) << left << CurrencyObject.Rate;

    }

public :
    static void ShowCurrenciesListScreen()
    {


        vector <Currency> vCurrencys = Currency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (Currency& CurrencyObject : vCurrencys)
            {

                PrintCurrencyRecordLine(CurrencyObject);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }
};

