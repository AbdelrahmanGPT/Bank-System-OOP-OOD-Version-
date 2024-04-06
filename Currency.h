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

using namespace std;
using namespace filesystem;

class Currency
{
private :

	enum CurrencyMode {EmptyMode = 0 , UpdateMode = 1};
	CurrencyMode _CurrencyMode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	long double _Rate;

	static Currency _ConvertRecordToCurrencyObject(string Record, string Separator = "#//#")
	{
		vector<string>CurrencyVector = String::SplitStringWordstoVector(Record, Separator);

		return Currency(UpdateMode, CurrencyVector[0], CurrencyVector[1], CurrencyVector[2], stold(CurrencyVector[3]));
	}

	static string _ConvertCurrencyObjectToRecord(Currency CurrencyObject, string Separator = "#//#")
	{
		string CurrencyRecord = "";

		CurrencyRecord += (CurrencyObject.Country + Separator);
		CurrencyRecord += (CurrencyObject.CurrencyCode + Separator);
		CurrencyRecord += (CurrencyObject.CurrencyName + Separator);
		CurrencyRecord += to_string(CurrencyObject.Rate);

		return CurrencyRecord;
	}

	static vector<Currency> _LoadCurrencyObjectDataFromFile()
	{
		vector<Currency>CurrencyObjectVector;

		fstream File;
		File.open("CURRENCIES.txt", ios::in);

		if (File.is_open())
		{
			string CurrencyRecord;

			while (getline(File, CurrencyRecord))
			{
				CurrencyObjectVector.push_back(_ConvertRecordToCurrencyObject(CurrencyRecord));
			}

			File.close();
		}

		return CurrencyObjectVector;
	}

	static void _SaveCurrencyObjectsDataToFile(vector<Currency>&CurrencyVector)
	{
		fstream File;
		File.open("CURRENCIES.txt", ios::out);

		if (File.is_open())
		{
			for (Currency& CurrencyObject : CurrencyVector)
			{
				File << _ConvertCurrencyObjectToRecord(CurrencyObject) << "\n";
			}

			File.close();
		}
	}

	static Currency _GetEmptyCurrencyObject()
	{
		return Currency(EmptyMode, "", "", "" "", 0);
	}

	void _UpdateCurrencyInfoInternally()
	{
		vector<Currency>CurrencyVector = _LoadCurrencyObjectDataFromFile();

		for (Currency& CurrencyObject : CurrencyVector)
		{
			if (CurrencyObject.CurrencyCode == CurrencyCode)
			{
				CurrencyObject = *this;
				break;
			}
		}

		_SaveCurrencyObjectsDataToFile(CurrencyVector);
	}

public :

	Currency(CurrencyMode CurrencyMode, string Country, string CurrencyCode,
		string CurrencyName, long double Rate)
	{
		_CurrencyMode = CurrencyMode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	string GetCountry()
	{
		return _Country;
	}

	__declspec(property(get = GetCountry))string Country;


	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	__declspec(property(get = GetCurrencyCode))string CurrencyCode;

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	__declspec(property(get = GetCurrencyName))string CurrencyName;

	long double GetRate()
	{
		return _Rate;
	}

	__declspec(property(get = GetRate))long double Rate;

	bool IsCurrencyEmpty()
	{
		return (_CurrencyMode == EmptyMode);
	}

	void UpdateCurrencyRate(long double NewRate)
	{
		_Rate = NewRate;
		_UpdateCurrencyInfoInternally();
	}

	static Currency FindCurrencyByCountry(string Country)
	{
		vector<Currency> CurrencyVector = _LoadCurrencyObjectDataFromFile();

		for (Currency& CurrencyObject : CurrencyVector)
		{
			if (String::UpperCaseAllString(Country) == String::UpperCaseAllString(CurrencyObject.Country))
			{
				return CurrencyObject;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static Currency FindCurrencyByCurrencyCode(string CurrencyCode)
	{
		vector <Currency>CurrencyVector = _LoadCurrencyObjectDataFromFile();

		for (Currency& CurrencyObject : CurrencyVector)
		{
			if (String::UpperCaseAllString(CurrencyCode) == String::UpperCaseAllString(CurrencyObject.CurrencyCode))
			{
				return CurrencyObject;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		Currency CurrencyObject = Currency::FindCurrencyByCurrencyCode(CurrencyCode);

		return (!CurrencyObject.IsCurrencyEmpty());
	}

	static vector<Currency> GetCurrenciesList()
	{
		return _LoadCurrencyObjectDataFromFile();
	}

	long double CurrencyExchange(Currency& CurrencyTo, long double ExchangeAmount)
	{

		return (ExchangeAmount / Rate) * CurrencyTo.Rate;
	}
};

