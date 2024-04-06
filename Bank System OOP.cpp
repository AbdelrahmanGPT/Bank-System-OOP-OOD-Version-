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
#include"Client.h"
#include "MainScreen.h"
#include "LoginScreen.h"

using namespace std;
using namespace filesystem;



int main()
{
	srand((unsigned)time(NULL));

	while(true)
	{
		LoginScreen::ShowLoginScreen();
	}
	
	return 0;
}