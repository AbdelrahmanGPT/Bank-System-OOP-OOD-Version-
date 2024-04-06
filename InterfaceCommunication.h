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

class InterfaceCommunication
{
	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendSMS(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;

};

