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

class FindCurrencyScreen : protected Screen
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

    static void _ShowFindResults(Currency CurrencyObject)
    {
        if (!CurrencyObject.IsCurrencyEmpty())
        {
            printf("\nCURRENCY IS FOUND SUCCESSFULY\n");
            _PrintCurrency(CurrencyObject);
        }

        else
        {
            printf("\nCURRENCY IS NOT FOUND :-(\n");
        }
    }

    enum FindByChoices { FindByCurrencyCode = 1, FindByCountry = 2 };

    static FindByChoices _ReadFindByChoice()
    {
        return (FindByChoices)(Input_Validation::ValidateNumberInRange(1 , 2 , "FIND BY : [1] CODE OR [2] COUNTRY ?"));
    }


public :

    static void ShowFindCurrencyScreen()
    {
        Utility::ClearScreen();
        _DrawScreenHeader("\t FIND CURRENCY SCREEN");

        FindByChoices FindByChoice = _ReadFindByChoice();

        if (FindByChoice == FindByCurrencyCode)
        {

            string CurrencyCode = Input_Validation::ReadStringLine("ENTER CURRENCY CODE ?");
            Currency CurrencyObject = Currency::FindCurrencyByCurrencyCode(CurrencyCode);
            _ShowFindResults(CurrencyObject);
        }
        else 
        {
            string Country = Input_Validation::ReadStringLine("ENTER COUNTRY ?");
            Currency CurrencyObject = Currency::FindCurrencyByCountry(Country);
            _ShowFindResults(CurrencyObject);
        }

        
    }

};

