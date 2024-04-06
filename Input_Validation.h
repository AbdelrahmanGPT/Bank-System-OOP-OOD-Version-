#pragma once

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
#include"Utility.h";
#include"String.h";
#include "Date.h"


using namespace std;
using namespace filesystem;

class Input_Validation
{
public : 


	static float ReadFloatNumber(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		float Number;

		printf("\n%s\n", Message.c_str());
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER , %s\n", Message.c_str());
			cin >> Number;
		}

		return Number;
	}

	static double ReadDoubleNumber(string Message)
	{
		double Number;

		

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		printf("\n%s\n", Message.c_str());
		cin >> Number; 

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER , %s\n", Message.c_str());
			cin >> Number;
		}

		return Number;
	}

	static long double ReadLongDoubleNumber(string Message)
	{
		long double Number;

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		printf("\n%s\n", Message.c_str());
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER , %s\n", Message.c_str());
			cin >> Number;
		}

		return Number;
	}

	static short ReadShortNumber(string Message)
	{
		short Number;

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		printf("\n%s\n", Message.c_str());
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER , %s\n", Message.c_str());
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntegerNumber(string Message)
	{
		int Number;

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		printf("\n%s\n", Message.c_str());

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER , %s\n", Message.c_str());
			cin >> Number;
		}

		return Number;
	}

	static long long ReadLongLongNumber(string Message)
	{
		long long Number;

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		printf("\n%s\n", Message.c_str());
		cin >> Number; 
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER , %s\n", Message.c_str());
			cin >> Number;
		}

		return Number;
	}

	static long long ReadPositiveNumber(string Message)
	{
		long long Number;

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		do
		{

			Number = ReadLongLongNumber(Message);

		} while (Number <= 0);

		return Number;
	}

	static long long ReadNumberMultipleOf(string Message, long long FactorNumber)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		do
		{
			Number = ReadLongLongNumber(Message);

		} while (Number % FactorNumber != 0);

		return Number;
	}

	static long double ReadDoublePositiveNumber(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long double Number;

		do
		{
			
			Number = ReadLongDoubleNumber(Message);

		} while (Number <= 0);

		return Number;
	}

	static long long ValidateNumberInRange(long long From, long long To)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		string Message = "ENTER A NUMBER BETWEEN " + to_string(From) + " & " + to_string(To);

		do
		{

			Number = ReadLongLongNumber(Message);

		} while (Number > To || Number < From);

		return Number;
	}

	static long long ValidateNumberInRange(long long From, long long To, string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		do
		{

			Number = ReadLongLongNumber(Message);

		} while (Number > To || Number < From);

		return Number;
	}

	static long double ValidateDoubleNumberInRange(long double From, long double To)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long double Number;

		string Message = "ENTER A NUMBER BETWEEN " + to_string(From) + " & " + to_string(To);

		do
		{

			Number = ReadLongDoubleNumber(Message);

		} while (Number > To || Number < From);

		return Number;
	}

	static long double ValidateDoubleNumberInRange(long double From, long double To, string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long double Number;

		do
		{

			Number = ReadLongDoubleNumber(Message);

		} while (Number > To || Number < From);

		return Number;
	}

	static short ReadShortNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		short Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER\n");
			cin >> Number;
		}

		return Number;
	}
	
	static int ReadIntegerNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER\n");
			cin >> Number;
		}

		return Number ;
	}

	static long long ReadLongLongNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER\n");
			cin >> Number;
			
		}

		return Number;
	}

	static float ReadFloatNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		float Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER\n");
			cin >> Number;
		}

		return Number;
	}

	static double ReadDoubleNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		double Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER\n");
			cin >> Number;
		}

		return Number;
	}

	static long double ReadLongDoubleNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long double Number;

		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID NUMBER\n");
			cin >> Number;
		}

		return Number;

	}

	static long long ReadNumberMultipleOf(long long FactorNumber)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		do
		{

			Number = ReadLongLongNumber();

		} while (Number % FactorNumber != 0);

		return Number;
	}

	static long long ReadPositiveNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		do
		{

			Number = ReadLongLongNumber();

		} while (Number <= 0);

		return Number;
	}

	static long double ReadDoublePositiveNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long double Number;

		do
		{

			Number = ReadLongDoubleNumber();

		} while (Number <= 0);

		return Number;
	}

	static long long ValidateNumberInRangeWithoutMessage(long long From, long long To)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long long Number;

		do
		{

			Number = ReadLongLongNumber();

		} while (Number > To || Number < From);

		return Number;
	}

	static long double ValidateDoubleNumberInRangeWithoutMessage(long double From, long double To)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		long double Number;

		do
		{

			Number = ReadLongDoubleNumber();

		} while (Number > To || Number < From);

		return Number;
	}

	static string ReadString(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string String;

		printf("\n%s\n", Message.c_str());
		
		cin >> String;

		return String;
	}

	static string ReadString()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string String;

		cin >> String;

		return String;
	}

	static string ReadStringLine(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string StringLine;

		printf("\n%s\n", Message.c_str());
		

		getline(cin >> ws, StringLine);

		return StringLine;

	}

	static string ReadStringLine()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string StringLine;

		
		getline(cin >> ws, StringLine);

		return StringLine;
	}

	static char ReadCharacter(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		char Character;

		printf("\n%s\n", Message.c_str());
		cin >> Character;


		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize> ::max(), '\n');

			printf("INVALID CHARACTER , %s\n", Message.c_str());
			cin >> Character; 
		}

		return Character;
 	}

	static char ReadCharacter()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		char Character;

		cin >> Character;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			printf("INVALID CHARACTER\n");
			cin >> Character;
		}

		return Character;
	}

	static char ReadArithmeticOperator(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		char ArithmeticOperator = ' ';
		
		do
		{

			ArithmeticOperator = ReadCharacter(Message);

		} while (ArithmeticOperator != '+' && ArithmeticOperator != '-' && 
				 ArithmeticOperator != '*' && ArithmeticOperator != '/' &&
				 ArithmeticOperator != '%');

		return ArithmeticOperator;

	}

	static char ReadArithmeticOperator()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		char ArithmeticOperator = ' ';

		do
		{

			ArithmeticOperator = ReadCharacter();

		} while (ArithmeticOperator != '+' && ArithmeticOperator != '-' 
				 && ArithmeticOperator != '/' && ArithmeticOperator != '*' 
				 && ArithmeticOperator != '%');

		return ArithmeticOperator;
	}

	static string ReadPhoneNumber(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string PhoneNumber;

		do
		{

			PhoneNumber = ReadStringLine(Message);

		} while (!Utility::IsPhoneNumber(PhoneNumber));

		return PhoneNumber;
	}

	static string ReadPhoneNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string PhoneNumber;

		do
		{

			PhoneNumber = ReadStringLine();

		} while (!Utility::IsPhoneNumber(PhoneNumber));

		return PhoneNumber;
	}

	static string ReadPhoneKey(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string PhoneKey;

		do
		{

			PhoneKey = ReadStringLine(Message);

		} while (!Utility::IsPhoneKey(PhoneKey));

		return PhoneKey;
	}

	static string ReadPhoneKey()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string PhoneKey;

		do
		{

			PhoneKey = ReadStringLine();

		} while (!Utility::IsPhoneKey(PhoneKey));

		return PhoneKey;
	}

	static string ReadFullPhoneNumber(string PhoneKeyMessage, string PhoneNumberMessage)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string PhoneKey;
		string PhoneNumber;

		PhoneKey = ReadPhoneKey(PhoneKeyMessage);
		PhoneNumber = ReadPhoneNumber(PhoneNumberMessage);

		return PhoneKey + PhoneNumber;
	}

	static string ReadFullPhoneNumber()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string PhoneKey;
		string PhoneNumber;

		PhoneKey = ReadPhoneKey();
		PhoneNumber = ReadPhoneNumber();

		return PhoneKey + PhoneNumber;
	}

	static string ReadEmailAddress(string Message)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string EmailAddress;

		do
		{

			EmailAddress = ReadStringLine(Message);

		} while (!Utility::IsEmailAddress(EmailAddress));

		return EmailAddress;
	}

	static string ReadEmailAddress()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		string EmailAddress;

		do
		{

			EmailAddress = ReadStringLine();

		} while (!Utility::IsEmailAddress(EmailAddress));

		return EmailAddress;
	}

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(long long Number, long long From, long long To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(long double Number, long double From, long double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(::Date Date1, ::Date From, ::Date To)
	{
		if ((::Date::IsDate1AfterDate2(Date1, From) || ::Date::IsDate1EqualDate2(Date1, From)) &&
			(::Date::IsDate1BeforeDate2(Date1, To) || ::Date::IsDate1EqualDate2(Date1, To)))
		{
			return true;
		}

		if ((::Date::IsDate1AfterDate2(Date1, To) || ::Date::IsDate1EqualDate2(Date1, To)) &&
			(::Date::IsDate1BeforeDate2(Date1, From) || ::Date::IsDate1EqualDate2(Date1, From)))
		{
			return true;
		}

		return false;
	}

	static bool IsValidDate(::Date Date)
	{
		return ::Date::IsDateValid(Date);
	}

};

