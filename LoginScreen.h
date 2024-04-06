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
#include "GlobalUser.h"
#include "MainScreen.h"

using namespace std;
using namespace filesystem;

class LoginScreen : protected Screen
{
private :

	static void _LoginUser()
	{
		
		string UserName;
		string Password;
		bool LoginFailed = false;
		short LoginTrials = 3;

		do
		{
			if (LoginFailed)
			{
				
				printf("\nINVALID USERNAME/PASSWORD\n\n");
				printf("YOU HAVE %d TRIAL(S)\n", --LoginTrials);

				if (LoginTrials == 0)
				{
					printf("\nYOU ARE LOCKED AFTER 3 FAILED TRIALS\n");
					exit(0);
				}
			}

			UserName = Input_Validation::ReadStringLine("ENTER USER NAME");
			Password = Input_Validation::ReadStringLine("ENTER PASSWORD");

			CurrentUser = User::Find(UserName , Password);

			LoginFailed = CurrentUser.IsEmptyUser();


		} while (LoginFailed);

		CurrentUser.SaveUserLoginRegisterData();
		MainScreen::ShowMainScreen();
	}

public :
	static void ShowLoginScreen()
	{
		Utility::ClearScreen();
		_DrawScreenHeader("\t LOGIN SCREEN");
		_LoginUser();
	}

};

