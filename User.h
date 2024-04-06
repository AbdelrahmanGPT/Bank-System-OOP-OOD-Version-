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
#include "Person.h"

using namespace std;
using namespace filesystem;

class User : public Person
{
private :

	enum UserMode {EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2};

	UserMode _UserMode;
	string _UserName;
	string _Password;
	int _Permissions = 0;
	bool _DeleteMark = false;

	struct LoginRegisterStructure;

	static User _ConvertRecordToUserObject(string Record, string Separator = "#//#")
	{
		vector <string> UserVector = String::SplitStringWordstoVector(Record, Separator);

		return User(UpdateMode, UserVector[0], UserVector[1], UserVector[2],
			UserVector[3], UserVector[4], Utility::Decrypt(UserVector[5] , 2), stoi(UserVector[6]));
	}

	static string _ConvertUserObjectToRecord(User UserObject, string Separator = "#//#")
	{
		string UserRecord = "";

		UserRecord += (UserObject.FirstName + Separator);
		UserRecord += (UserObject.LastName + Separator);
		UserRecord += (UserObject.Email + Separator);
		UserRecord += (UserObject.PhoneNumber + Separator);
		UserRecord += (UserObject.UserName + Separator);
		UserRecord += (Utility::Encrypt(UserObject.Password , 2) + Separator);
		UserRecord += (to_string(UserObject.Permissions));

		return UserRecord;
		
	}

	static void _SaveUsersObjectsDataToFile(vector<User>& UsersVector)
	{
		fstream File;
		File.open("USERS.txt", ios::out);

		if (File.is_open())
		{
			for (User& UserObject : UsersVector)
			{
				if (UserObject._DeleteMark == false)
				{
					File << _ConvertUserObjectToRecord(UserObject) << "\n";
				}
			}

			File.close();
		}
	}

	static vector<User> _LoadUsersObjectsDataFromFile()
	{
		vector<User>UsersVector;

		fstream File;
		File.open("USERS.txt", ios::in);

		if (File.is_open())
		{
			string Record;

			while (getline(File, Record))
			{
				if(Record != "") 
				{
					UsersVector.push_back(_ConvertRecordToUserObject(Record));
				}
			}

			File.close();
		}

		return UsersVector;
	}

	static User _GetEmptyUserObject()
	{
		return User(EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _AddNewDataLineToFile(string Record)
	{
		fstream File;
		File.open("USERS.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << Record << "\n";

			File.close();
		}

	}

	void _UpdateUserInternally()
	{
		vector<User> UserVector = _LoadUsersObjectsDataFromFile();

		for (User& UserObject : UserVector)
		{
			if (UserObject.UserName == UserName)
			{
				UserObject = *this;
			}
		}

		_SaveUsersObjectsDataToFile(UserVector);
	}

	void _AddNewUserInternally()
	{
		_AddNewDataLineToFile(_ConvertUserObjectToRecord(*this));
	}

	string _GetUserLoginRegisterRecord(string Separator = "#//#")
	{
		string UserLoginRegisterRecord = "";

		UserLoginRegisterRecord += (::Date::GetSystemDateTimeStringForm() + Separator);
		UserLoginRegisterRecord += (UserName + Separator);
		UserLoginRegisterRecord += (Utility::Encrypt(Password , 2) + Separator);
		UserLoginRegisterRecord += to_string(Permissions);

		return UserLoginRegisterRecord;
	}

	static LoginRegisterStructure _ConvertLoginRegsiterRecordToStructure(string Record , string Separator = "#//#")
	{
		LoginRegisterStructure LoginRegisterStructure_;
		vector<string>LoginRegisterVector = String::SplitStringWordstoVector(Record , Separator);
		
		LoginRegisterStructure_.DateTimeString = LoginRegisterVector[0];
		LoginRegisterStructure_.UserName = LoginRegisterVector[1];
		LoginRegisterStructure_.Password = Utility::Decrypt(LoginRegisterVector[2] , 2);
		LoginRegisterStructure_.Permissions = stoi(LoginRegisterVector[3]);

		return LoginRegisterStructure_;
	}
public : 

	struct LoginRegisterStructure
	{
		string DateTimeString;
		string UserName;
		string Password;
		int Permissions;
	};

	enum MainMenuPersmissions {pAll = -1 , pListClients = 1 , pAddNewClients = 2 ,
							   pDeleteClients = 4 , pUpdateClients = 8 , pFindClients = 16 ,
							   pTransactions = 32 , pManageUsers = 64 , pShowLoginRegisterList = 128 , pCurrencyExchangeMainScreen = 256};

	

	User(UserMode UserMode, string FirstName, string LastName, string Email,
		string PhoneNumber, string	UserName, string Password, int Permissions)
		:Person(FirstName, LastName, Email, PhoneNumber)
	{
		_UserMode = UserMode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}


	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Persmissions)
	{
		_Permissions = Persmissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	void SetDeleteMark(bool DeleteMark)
	{
		_DeleteMark = DeleteMark;
	}

	bool GetDeleteMark()
	{
		return _DeleteMark;
	}

	__declspec(property(get = GetDeleteMark, put = SetDeleteMark))bool DeleteMark;

	static User Find(string UserName)
	{
		vector<User>UserVector = _LoadUsersObjectsDataFromFile();

		for (User& UserObject : UserVector)
		{
			if (UserObject.UserName == UserName)
			{
				return UserObject;
			}
		}

		return _GetEmptyUserObject();
	}

	static User Find(string UserName, string Password)
	{
		vector<User>UserVector = _LoadUsersObjectsDataFromFile();

		for (User& UserObject : UserVector)
		{
			if (UserObject.UserName == UserName && UserObject.Password == Password)
			{
				return UserObject;
			}
		}

		return _GetEmptyUserObject();
	}

	static bool IsEmptyUser(User& UserObject)
	{
		return (UserObject._UserMode == EmptyMode);
	}

	bool IsEmptyUser()
	{
		return IsEmptyUser(*this);
	}

	static bool IsUserExist(string UserName)
	{
		User UserObject = User::Find(UserName);

		return (!UserObject.IsEmptyUser());
	}

	static bool IsUserExist(string UserName, string Password)
	{
		User UserObject = User::Find(UserName, Password);

		return (!UserObject.IsEmptyUser());
	}

	bool DeleteUser()
	{
		vector<User>UserVector = _LoadUsersObjectsDataFromFile();

		for (User& UserObject : UserVector)
		{
			if (UserObject.UserName == UserName)
			{
				UserObject.DeleteMark = true;
				break;
			}
		}

		_SaveUsersObjectsDataToFile(UserVector);

		*this = _GetEmptyUserObject();
		
		return true;
	}

	enum SaveResults {SaveFailedEmptyObject = 0 , SaveSucceeded = 1 , SaveFailedAccountExist = 2};

	SaveResults SaveUsersData()
	{
		switch (_UserMode)
		{
		case User::EmptyMode:

			if (IsEmptyUser())
			{
				return SaveFailedEmptyObject;
			}

		case User::UpdateMode:

			_UpdateUserInternally();
			
			return SaveSucceeded;

		case User::AddNewMode:
			
			if (User::IsUserExist(_UserName))
			{
				return SaveFailedAccountExist ;
			}

			_UserMode = UpdateMode;
			_AddNewUserInternally();

			return SaveSucceeded;

		}
	}

	static User GetAddNewUserObject(string UserName)
	{
		return User(AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<User>GetUsersList()
	{
		return _LoadUsersObjectsDataFromFile();
	}

	bool CheckAccessPermission(MainMenuPersmissions MainMenuPersmission)
	{
		if ((this->Permissions == pAll) || ((this->Permissions & MainMenuPersmission) == MainMenuPersmission))
		{
			return true ;
		}

		return false ;
	}

	void SaveUserLoginRegisterData()
	{
		fstream File;
		File.open("LOGIN_REGISTER.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << _GetUserLoginRegisterRecord() << "\n";
		
			File.close();
		}

		
	}

	static vector<LoginRegisterStructure> GetLoginRegisterList()
	{
		vector<LoginRegisterStructure>LoginRegisterVector;

		fstream File;
		File.open("LOGIN_REGISTER.txt", ios::in);

		if (File.is_open())
		{
			string Record;

			while (getline(File, Record))
			{
				if (Record != "")
				{
					LoginRegisterVector.push_back(_ConvertLoginRegsiterRecordToStructure(Record));
				}
			}

			File.close();
		}

		return LoginRegisterVector;
	}



};

