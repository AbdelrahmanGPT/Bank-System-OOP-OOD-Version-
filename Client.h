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

class Client : public Person 
{
private : 
	enum ClientMode{EmptyMode = 0 , UpdateMode = 1 , AddNewMode = 2};

	ClientMode _ClientMode;

	string _AccountNumber;
	string _Pincode;
	long double _AccountBalance;
	bool _DeleteMark = false;

	static Client _ConvertRecordToClientObject(string Record, string Separator = "#//#")
	{
		vector<string>ClientVector = String::SplitStringWordstoVector(Record, Separator);

		return Client(UpdateMode, ClientVector[0], ClientVector[1], ClientVector[2], ClientVector[3],
			ClientVector[4], Utility::Decrypt(ClientVector[5] , 2), stold(ClientVector[6]));
	}

	static string _ConvertClientObjectToRecord(Client ClientObject, string Separartor = "#//#")
	{
		string ClientObjectRecord = "";

		ClientObjectRecord += (ClientObject.FirstName + Separartor);
		ClientObjectRecord += (ClientObject.LastName + Separartor);
		ClientObjectRecord += (ClientObject.Email + Separartor);
		ClientObjectRecord += (ClientObject.PhoneNumber + Separartor);
		ClientObjectRecord += (ClientObject.AccountNumber + Separartor);
		ClientObjectRecord += (Utility::Encrypt(ClientObject.Pincode , 2) + Separartor);
		ClientObjectRecord += (to_string(ClientObject.AccountBalance));
		

		return ClientObjectRecord;
	}

	static vector<Client> _LoadClientsObjectsDataFromFile()
	{
		vector<Client> ClientsVector;

		fstream File;
		File.open("CLIENTS.txt", ios::in);

		if (File.is_open())
		{
			string Record;

			while (getline(File, Record))
			{
				if (Record != "")
				{
					ClientsVector.push_back(_ConvertRecordToClientObject(Record));
				}
			}

			File.close();
		}

		return ClientsVector;
	}

	static void _SaveClientsObjectsDataToFile(vector<Client>& ClientsVector)
	{
		fstream File;
		File.open("CLIENTS.txt", ios::out);

		if (File.is_open())
		{
			for (Client& ClientObject : ClientsVector)
			{

				if(ClientObject.DeleteMark == false)
				{
					File << _ConvertClientObjectToRecord(ClientObject) << "\n";
				}
			}

			File.close();
		}
	}

	static Client _GetEmptyClientObject()
	{
		return Client(EmptyMode, "", "", "", "", "", " ", 0);
	}

	void _UpdateClientInternally()
	{
		vector<Client>ClientsVector = _LoadClientsObjectsDataFromFile();

		for (Client& ClientObject : ClientsVector)
		{
			if (ClientObject.AccountNumber == AccountNumber)
			{
				ClientObject = *this;
				break;
			}
		}

		_SaveClientsObjectsDataToFile(ClientsVector);
	}

	static void _AddNewDataLineToFile(string Record)
	{
		fstream File;
		File.open("CLIENTS.txt", ios::app | ios::out);

		if (File.is_open())
		{
			File << Record << "\n";

			File.close();
		}
	}

	void _AddNewClientInternally()
	{
		_AddNewDataLineToFile(_ConvertClientObjectToRecord(*this));
	}

	string _GetTransferLogInfoRecord(long double TransferAmount, Client& DestinationClient, string UserName , string Separator = "#//#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += ::Date::GetSystemDateTimeStringForm() + Separator;
		TransferLogRecord += AccountNumber + Separator;
		TransferLogRecord += DestinationClient.AccountNumber + Separator;
		TransferLogRecord += to_string(TransferAmount) + Separator;
		TransferLogRecord += to_string(AccountBalance) + Separator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogRecord += UserName;

		return TransferLogRecord;
	}

	void _SaveTransferLogInFile(long double TransferAmount, Client& DestinationClient, string UserName)
	{
		fstream File;
		File.open("TRANSFER_LOG.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << _GetTransferLogInfoRecord(TransferAmount, DestinationClient, UserName) << "\n";
			
			File.close();
		}
	}

	struct TransferLogStructure;

	static TransferLogStructure _ConvertTransferLogRecordToTransferLogStructure(string TransferLogRecord, string Separator = "#//#")
	{
		vector<string>TransferLogVector = String::SplitStringWordstoVector(TransferLogRecord, Separator);

		TransferLogStructure TransferLogStructurev;
		
		TransferLogStructurev.DateTimeString = TransferLogVector[0];
		TransferLogStructurev.SourceClientAccountNumber = TransferLogVector[1];
		TransferLogStructurev.DestinationClientAccountNumber = TransferLogVector[2];
		TransferLogStructurev.TransferAmount = stold(TransferLogVector[3]);
		TransferLogStructurev.SourceClientAccountBalance = stold(TransferLogVector[4]);
		TransferLogStructurev.DestinationClientAccountBalance = stold(TransferLogVector[5]);
		TransferLogStructurev.UserName = TransferLogVector[6];

		return TransferLogStructurev;
	}

public : 

	struct TransferLogStructure
	{
		string DateTimeString;
		string SourceClientAccountNumber;
		string DestinationClientAccountNumber;
		long double TransferAmount;
		long double SourceClientAccountBalance;
		long double DestinationClientAccountBalance;
		string UserName;

	};

	Client(ClientMode ClientMode, string FirstName, string LastName, string Email
		, string PhoneNumber, string AccountNumber, string Pincode, long double AccountBalance)
		: Person(FirstName, LastName, Email, PhoneNumber)
	{
		_ClientMode = ClientMode;

		if (_ClientMode == EmptyMode)
		{
			FirstName = "";
			LastName = "";
			Email = "";
			PhoneNumber = "";
			AccountNumber = "";
			Pincode = "";
			AccountBalance = 0;
		}

		_AccountNumber = AccountNumber;
		_Pincode = Pincode;
		_AccountBalance = AccountBalance;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber))string AccountNumber;

	void SetPincode(string Pincode)
	{
		_Pincode = Pincode;
	}

	string GetPincode()
	{
		return _Pincode;
	}

	__declspec(property(get = GetPincode, put = SetPincode))string Pincode;

	void SetAccountBalance(long double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	long double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))long double AccountBalance;

	void SetDeleteMark(bool DeleteMark)
	{
		_DeleteMark = DeleteMark;
	}

	bool GetDeleteMark()
	{
		return _DeleteMark;
	}

	__declspec(property(get = GetDeleteMark, put = SetDeleteMark))bool DeleteMark;

	void PrintClientInfo()
	{
		//NO RELATED UI CODE IN OBJECT
		/*printf("CLIENT INFO : \n");
		printf("_______________________________\n");
		printf("ACCOUNT NUMBER : %s\n", AccountNumber.c_str());
		printf("FIRST NAME     : %s\n", FirstName.c_str());
		printf("LAST NAME      : %s\n", LastName.c_str());
		printf("FULL NAME      : %s\n", FullName().c_str());
		printf("EMAIL ADDRESS  : %s\n", Email.c_str());
		printf("PHONE NUMBER   : %s\n", PhoneNumber.c_str());
		printf("PASSWORD       : %s\n", Pincode.c_str());
		printf("BALANCE        : %lf\n", AccountBalance);
		printf("_______________________________\n");*/
	}

	static bool IsClientEmpty(Client ClientObject)
	{
		return (ClientObject._ClientMode == EmptyMode);
	}

	bool IsClientEmpty()
	{
		return IsClientEmpty(*this);
	}

	static Client Find(string AccountNumber)
	{
		vector<Client>ClientsVector;

		fstream File;
		File.open("CLIENTS.txt", ios::in);

		if (File.is_open())
		{
			string Record;

			while (getline(File, Record))
			{
				Client ClientObject = _ConvertRecordToClientObject(Record);

				if (ClientObject.AccountNumber == AccountNumber)
				{
					File.close();
					return ClientObject;
				}
				ClientsVector.push_back(ClientObject);

			}
			File.close();
		}

		return _GetEmptyClientObject();
	}

	static Client Find(string AccountNumber, string Pincode)
	{
		vector<Client> ClientsVector;

		fstream File;

		File.open("CLIENTS.txt", ios::in);

		if (File.is_open())
		{
			string Record;

			while (getline(File, Record))
			{
				Client ClientObject = _ConvertRecordToClientObject(Record);

				if (ClientObject.AccountNumber == AccountNumber && ClientObject.Pincode == Pincode)
				{
					File.close();
					return ClientObject;
				}

				ClientsVector.push_back(ClientObject);
			}

			File.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		Client ClientObject = Client::Find(AccountNumber);

		return (!ClientObject.IsClientEmpty());
	}

	static bool IsClientExist(string AccountNumber, string Pincode)
	{
		Client ClientObject = Client::Find(AccountNumber, Pincode);
		return (!ClientObject.IsClientEmpty());
	}

	enum SaveResults {SaveFailedEmptyObject = 0 , SaveSucceeded = 1 , SaveFailedAccountExist = 2};

	static Client GetAddNewClientObject(string AccountNumber)
	{
		return Client(AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	SaveResults SaveClientsData()
	{
		switch (_ClientMode)
		{
		case Client::EmptyMode:

			if (Client::IsClientEmpty())
			{
				return SaveFailedEmptyObject;
			}

		case Client::UpdateMode:

			_UpdateClientInternally();
			
			return SaveSucceeded;

		case Client::AddNewMode :
		if(!Client::IsClientExist(AccountNumber))
		{
			_ClientMode = UpdateMode;
			_AddNewClientInternally();
			return SaveSucceeded;
		}

		else
		{
			return SaveFailedAccountExist;
		}
		}
	}

	bool DeleteClientInternally()
	{
		vector<Client>ClientsVector = _LoadClientsObjectsDataFromFile();

		for (Client& ClientObject : ClientsVector)
		{
			if (ClientObject.AccountNumber == AccountNumber)
			{
				ClientObject.DeleteMark = true;
				break;
			}
		}

		_SaveClientsObjectsDataToFile(ClientsVector);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<Client>GetClientsList()
	{
		return _LoadClientsObjectsDataFromFile();
	}

	static long double GetClientsBalance()
	{
		long double ClientsBalance = 0;

		vector<Client>ClientsVector = GetClientsList();

		for (Client& ClientObject : ClientsVector)
		{
			ClientsBalance += ClientObject.AccountBalance;
		}

		return ClientsBalance;
	}

	void DepositeMoneyInClient(long double Amount)
	{
		AccountBalance += Amount;
		SaveClientsData();
	} 

	bool WithdrawMoneyInClient(long double Amount)
	{
		if (AccountBalance >= Amount)
		{
			AccountBalance -= Amount;
			SaveClientsData();
		}

		else
		{
			return false;
		}

		return true;
	}

	bool TransferMoneyFromClientToClient(long double TransferAmount, Client& DestinationClient , string UserName)
	{
		if (AccountBalance >= TransferAmount)
		{
			WithdrawMoneyInClient(TransferAmount);
			DestinationClient.DepositeMoneyInClient(TransferAmount);
			_SaveTransferLogInFile(TransferAmount, DestinationClient, UserName);
			return true;
		}

		return false;
	}

	static vector<TransferLogStructure> GetTransferLogList()
	{
		vector<TransferLogStructure>TransferLogStructuresVector;

		fstream File;

		File.open("TRANSFER_LOG.txt", ios::in);

		if (File.is_open())
		{
			string TransferLogRecord; 

			while (getline(File, TransferLogRecord))
			{
				if (TransferLogRecord != "")
				{
					TransferLogStructuresVector.push_back(_ConvertTransferLogRecordToTransferLogStructure(TransferLogRecord));
				}
			}

			File.close();
		}

		return TransferLogStructuresVector;
	}
};

