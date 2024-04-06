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
#include "InterfaceCommunication.h"

using namespace std;
using namespace filesystem;

class Person : public InterfaceCommunication
{

private : 
	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public : 


	Person(string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName; 
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName))string LastName;


	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}

	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}

	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber))string PhoneNumber;
	
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SendEmail(string Title, string Body)
	{
		printf("TO : %s\n" , Email.c_str());
		printf("EMAIL TITLE : %s\n", Title.c_str());
		printf("_______________________\n");
		printf("EMAIL BODY : \n");
		printf("%s\n", Body.c_str());
		printf("_______________________\n");
	}

	void SendSMS(string Title, string Body)
	{
		printf("TO : %s\n", PhoneNumber.c_str());
		printf("SMS TITLE : %s\n", Title.c_str());
		printf("_______________________\n");
		printf("SMS BODY : \n");
		printf("%s\n", Body.c_str());
		printf("_______________________\n");
	}

	void SendFax(string Title, string Body)
	{
		printf("TO : %s\n", Email.c_str());
		printf("FAX TITLE : %s\n", Title.c_str());
		printf("_______________________\n");
		printf("FAX BODY : \n");
		printf("%s\n", Body.c_str());
		printf("_______________________\n");
	}

};

