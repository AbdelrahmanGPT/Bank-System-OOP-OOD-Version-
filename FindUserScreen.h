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

using namespace std;
using namespace filesystem;

class FindUserScreen : protected Screen
{
private : 

	static void _PrintUserInfo(User& UserObject)
	{
		printf("\nUSER INFO : \n");
		printf("_______________________________\n");
		printf("USER NAME     : %s\n", UserObject.UserName.c_str());
		printf("FIRST NAME    : %s\n", UserObject.FirstName.c_str());
		printf("LAST NAME     : %s\n", UserObject.LastName.c_str());
		printf("FULL NAME     : %s\n", UserObject.FullName().c_str());
		printf("EMAIL ADDRESS : %s\n", UserObject.Email.c_str());
		printf("PHONE NUMBER  : %s\n", UserObject.PhoneNumber.c_str());
		printf("PASSWORD      : %s\n", UserObject.Password.c_str());
		printf("PERMISSIONS   : %d\n", UserObject.Permissions);
		printf("_______________________________\n");
	}

public :

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t FIND USER SCREEN");

		string UserName = Input_Validation::ReadStringLine("ENTER USRE NAME");

		while (!User::IsUserExist(UserName))
		{
			UserName = Input_Validation::ReadStringLine("INVALID USER NAME , ENTER ANOTHER USER NAME");
		}

		User UserObject = User::Find(UserName);
		
		if (!UserObject.IsEmptyUser())
		{
			printf("\nUSER FOUND :-)\n");
		}

		else
		{
			printf("\nUSER IS NOT FOUND :-(\n");

		}

		_PrintUserInfo(UserObject);
	}

};

