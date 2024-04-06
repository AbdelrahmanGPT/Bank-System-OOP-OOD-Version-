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
#include "ABODAstd.h" ;

using namespace std;

class Utility
{

public:

	enum RandomCharacterType {
		SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3,
		Digit = 4, RandomCharacter = 5
	};

	enum CLIColors {
		Black = 0, Blue = 1, Green = 2, Aqua = 3, Red = 4, Purple = 5,
		Yellow = 6, White = 7, Gray = 8, LightBlue = 9, LightGreen = 10,
		LightAqua = 11, LightRed = 12, LightPurple = 13, LightYellow = 14,
		BrightWhite = 15
	};

	static int RandomNumber(int From, int To)
	{
		
		int RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;
	}

	static long long RandomNumber(long long From, long long To)
	{

		long long RandomNumber = rand() % (To - From + 1) + From;

		return RandomNumber;
	}

	static void Swap(short& Number1, short& Number2)
	{
		Number2 = Number1 + Number2;
		Number1 = Number2 - Number1;
		Number2 = Number2 - Number1;

		//ANOTHER SOLUTION (BUT TAKES MORE SPACE)

		/*short TemporaryNumber = Number1;
		Number1 = Number2;
		Number2 = TemporaryNumber;*/
	}

	static void Swap(int& Number1, int& Number2)
	{
		Number2 = Number1 + Number2;
		Number1 = Number2 - Number1;
		Number2 = Number2 - Number1;

		//ANOTHER SOLUTION (BUT TAKES MORE SPACE)

		/*int TemporaryNumber = Number1;
		Number1 = Number2;
		Number2 = TemporaryNumber;*/
	}

	static void Swap(long long& Number1, long long& Number2)
	{
		Number2 = Number1 + Number2;
		Number1 = Number2 - Number1;
		Number2 = Number2 - Number1;

		//ANOTHER SOLUTION (BUT TAKES MORE SPACE)
		/*long long TemporaryNumber = Number1;
		Number1 = Number2;
		Number2 = TemporaryNumber;*/
	}

	static void Swap(float& Number1, float& Number2)
	{
		float TemporaryNumber = Number1;
		Number1 = Number2;
		Number2 = TemporaryNumber;
	}

	static void Swap(double& Number1, double& Number2)
	{
		double TemporaryNumber = Number1;
		Number1 = Number2;
		Number2 = TemporaryNumber;
	}

	static void Swap(long double& Number1, long double& Number2)
	{
		long double TemporaryNumber = Number1;
		Number1 = Number2;
		Number2 = TemporaryNumber;
	}

	static void Swap(char& Character1, char& Character2)
	{
		char TemporaryCharacter = Character1;
		Character1 = Character2;
		Character2 = TemporaryCharacter;
	}

	static void Swap(string& String1, string& String2)
	{
		string TemporaryString = String1;
		String1 = String2;
		String2 = TemporaryString;
	}

	static void Swap(bool& Boolean1, bool& Boolean2)
	{
		bool TemporaryBoolean = Boolean1;
		Boolean1 = Boolean2;
		Boolean2 = TemporaryBoolean;
	}

	static long long GetIntegerPart(long double Number)
	{
		return (long long)Number;
	}

	static long double GetFloatingPoint(long double Number)
	{
		return Number - GetIntegerPart(Number);
	}

	static bool IsPrime(long long Number)
	{
		for (long long i = 2; i * i <= Number; i++)
		{
			if (Number % i == 0)
			{
				return false;
			}
		}

		return (Number != 1);
	}

	static bool IsPerfect(long long Number)
	{
		long long DivisorsSum = 0;

		for (long long i = 1; i < Number; i++)
		{
			if (Number % i == 0)
			{
				DivisorsSum += i;
			}
		}

		return (DivisorsSum == Number);
	}

	static bool IsInteger(long double Number)
	{
		return (Number == GetIntegerPart(Number));
	}

	static bool IsFloat(long double Number)
	{
		return !IsInteger(Number);
	}

	static bool IsNumber(char Number)
	{
		return isdigit(Number);
	}

	static bool IsLetter(char Letter)
	{
		return isalpha(Letter);
	}

	static void ClearScreen()
	{
		system("cls");
	}

	static string NumberToText(long long Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string NumberText[] = { "" , "ONE" , "TWO" , "THREE" , "FOUR" , "FIVE" , "SIX" ,
								   "SEVEN" , "EIGHT" , "NINE" , "TEN" , "ELEVEN" ,
								   "TWELVE" , "THIRTEEN" , "FOURTEEN" , "FIFTEEN" , "SIXTEEN" ,
								   "SEVENTEEN" , "EIGHTEEN" , "NINETEEN" };

			return NumberText[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string NumberText[] = { "" , "" , "TWENTY" , "THIRTY" , "FOURTY" , "FIFTY" ,
								   "SIXTY" , "SEVENTY" , "EIGHTY" , "NINETY" };

			return NumberText[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "ONE HUNDRED " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "HUNDREDS " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "ONE THOUSNADS " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "HUNDREDS " + NumberToText(Number % 1000);
		}

		if (Number >= 1e6 && Number <= 1999999)
		{
			return "ONE MILLION " + NumberToText(Number % (long long)1e6);
		}

		if (Number >= 2e6 && Number <= 999999999)
		{
			return NumberToText(Number / 1e6) + "HUNDREDS " + NumberToText(Number % (long long)1e6);
		}

		if (Number >= 1e9 && Number <= 1999999999)
		{
			return "ONE BILLION " + NumberToText(Number % (long long)1e9);
		}

		if (Number >= 2e9 && Number <= 999999999999)
		{
			return NumberToText(Number / 1e9) + "BILLIONS " + NumberToText(Number % (long long)1e9);
		}

		if (Number >= 1e12 && Number <= 1999999999999)
		{
			return "ONE TRILLION " + NumberToText(Number % (long long)1e12);
		}

		if (Number >= 2e12 && Number <= 999999999999999)
		{
			return NumberToText(Number / 1e12) + "TRILLIONS " + NumberToText(Number % (long long)1e12);
		}

		else
		{
			return "NUMBER IS BIGGER THAN THE QUADRILLION\n";
		}
	}

	static string ReturnColorHexadecimalNumber(CLIColors CLIColor)
	{
		string ColorHexadecimalNumber[] = { "0" , "1" , "2" , "3" , "4" , "5" , "6" ,
										   "7" , "8" , "9" , "A" , "B" , "C" , "D" ,
										   "E" , "F" };

		return ColorHexadecimalNumber[CLIColor];
	}

	static void ChangeCLIColors(CLIColors BackgroundColor = Black, CLIColors ForegroundColor = BrightWhite)
	{
		string CLIColorCommand = "color " + ReturnColorHexadecimalNumber(BackgroundColor) + ReturnColorHexadecimalNumber(ForegroundColor);

		system(CLIColorCommand.c_str());
	}

	static bool IsPhoneKey(string PhoneKey)
	{
		if (PhoneKey[0] != '+')
		{
			printf("\nINVALID PHONE KEY , YOU HAVEN'T ENTERED + SIGN CHARACTER IN THE BEGINNING OF KEY !\n");
			return false;
		}

		for (int i = 1; i < PhoneKey.length(); i++)
		{
			if (!IsNumber(PhoneKey[i]))
			{
				printf("\nINVALID PHONE KEY , YOU HAVE ENTERED NON-DIGIT CHARACTER !\n");
				return false;
			}
		}

		return true;
	}

	static bool IsPhoneNumber(string PhoneNumber)
	{
		for (int i = 0; i < PhoneNumber.length(); i++)
		{
			if (!isdigit(PhoneNumber[i]))
			{
				printf("\nINVALID PHONE NUMBER , YOU HAVE ENTERED NON-DIGIT CHARACTER !\n");
				return false;
			}
		}

		return true;
	}

	static bool IsEmailAddress(string EmailAddress)
	{
		const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

		if (!regex_match(EmailAddress, pattern))
		{
			printf("\nINVALID EMAIL ADDRESS FORMULA !\n");
			return false;
		}

		return true;
	}

	static void PrintArray(int Array[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			cout << Array[i] << ' ';
		}

		cout << "\n";
	}

	static void FillArrayWithRandomNumber(int Array[100], int &ArraySize)
	{

		ArraySize = ReadPositiveNumber("ENTER ARRAY SIZE");

		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = RandomNumber(1, 100);
		}
	}

	static void FillArrayWithRandomNumber(int Array[100], int &ArraySize, int From, int To)
	{
		ArraySize = ReadPositiveNumber("ENTER ARRAY SIZE");

		for (int i = 0; i < ArraySize; i++)
		{
			Array[i] = RandomNumber(From, To);
		}
	}

	static void CopyArray(int CopiedArray[100], int ArrayCopy[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			ArrayCopy[i] = CopiedArray[i];
		}
	}

	static void AddArrayElement(int Number, int Array[100], int& ArraySize)
	{
		Array[ArraySize++] = Number;
	}

	static void ReadArrayWithArrayLength(int Array[100])
	{
		int ArrayLength = ReadPositiveNumber("ENTER ARRAY SIZE");

		for (int i = 0; i < ArrayLength; i++)
		{
			printf("ENTER ELEMENT[%d] : ", i + 1);
			cin >> Array[i];
		}

		printf("\n");
	}

	static void ReadArray(int Array[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			printf("ENTER ELEMENT[%d] : ", (i + 1));
			cin >> Array[i];
		}

		printf("\n");
	}

	static bool IsArrayPalindrome(int Array[100], int ArraySize)
	{
		for (int i = 0; i <= floor(ArraySize / 2); i++)
		{
			if (Array[i] != Array[ArraySize - 1 - i])
			{
				return false;
			}
		}

		return true;
	}

	static int CheckFoundOrNot(int NumberToCheck, int Array[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			if (NumberToCheck == Array[i])
			{
				return i;
			}
		}

		return -1;
	}

	static bool IsFoundInArray(int NumberToCheck, int Array[100], int ArraySize)
	{
		return (CheckFoundOrNot(NumberToCheck, Array, ArraySize) != -1);
	}

	static bool AreArraysEqual(int Array1[100], int Array2[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			if (Array1[i] != Array2[i])
			{
				return false;
			}
		}

		return true;
	}

	static void CopyArrayInReversedOrder(int CopiedArray[100], int ArrayReversedCopy[100], int CopiedArraySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			ArrayReversedCopy[i] = CopiedArray[CopiedArraySize - 1 - i];
		}
	}

	static void PrintMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = ReadNumber();
			}

			printf("\n");
		}
	}

	static void ReadMatrixWithRowsAndColumns(int Matrix[100][100])
	{
		int Rows = ReadPositiveNumber("ENTER NUMBER OF ROWS OF MATRIX");
		int Columns = ReadPositiveNumber("ENTER NUMBER OF COLUMNS OF MATRIX");

		int Counter = 0;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				printf("ELEMENT[%d] : ", ++Counter);
				Matrix[Rows][Columns] = ReadNumber();
			}
			printf("\n");
		}
	}

	static void ReadMatrixWithoutRowsAndColumns(int Matrix[100][100], int Rows, int Columns)
	{
		int Counter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				printf("ELEMENT[%d] : ", ++Counter);
				Matrix[i][j] = ReadNumber();
			}

			printf("\n");
		}
	}

	static void FillMatrixWithRandomNumbers(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = RandomNumber(1, 100);
			}
		}
	}

	static void FillMatrixWithRandomNumbers(int Matrix[100][100], int Rows, int Columns, int From, int To)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = RandomNumber(From, To);
			}
		}
	}

	static int RowSum(int Matrix[100][100], int RowNumber, int Columns)
	{
		int RowSum = 0;
		for (int i = 0; i < Columns; i++)
		{
			RowSum += Matrix[RowNumber - 1][i];
		}

		return RowSum;
	}

	static int ColumnSum(int Matrix[100][100], int Rows, int ColumnNumber)
	{
		int ColumnSum = 0;

		for (int i = 0; i < Rows; i++)
		{
			ColumnSum += Matrix[i][ColumnNumber];
		}

		return ColumnSum;
	}

	static void FillMatrixWithOrderedNumber(int Matrix[100][100], int Rows, int Columns)
	{
		int OrderCounter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				Matrix[i][j] = ++OrderCounter;
			}
		}
	}

	static void GetMatrixTranspose(int Matrix[100][100], int TransposeMatrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				TransposeMatrix[i][j] = Matrix[j][i];
			}
		}
	}

	static void MultiplyContentOfTwoMatrices(int Matrix1[100][100], int Matrix2[100][100], int ResultMatrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				ResultMatrix[i][j] = Matrix1[i][j] * Matrix2[i][j];
 			}
		}
	}

	static void PrintMiddleRow(int Matrix[100][100], int Rows, int Columns)
	{
		int MiddleRow = Rows / 2;

		printf("\nMIDDLE ROW : \n");

		for (int i = 0; i < Columns; i++)
		{
			printf("%02d	", Matrix[MiddleRow][i]);
		}

		printf("\n");
	}

	static void PrintMiddleColumn(int Matrix[100][100], int Rows, int Columns)
	{
		int MiddleColumn = Columns / 2;

		printf("\nMIDDLE COLUMN : \n");

		for (int i = 0; i < Rows; i++)
		{
			printf("%02d	", Matrix[i][MiddleColumn]);
		}

		printf("\n");
	}

	static int MatrixSum(int Matrix[100][100], int Rows, int Columns)
	{
		int MatrixSum = 0;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				MatrixSum += Matrix[i][j];
			}
		}

		return MatrixSum;
	}

	static bool AreMatricesEqual(int Matrix1[100][100], int Matrix2[100][100], int Rows, int Columns)
	{
		return (MatrixSum(Matrix1, Rows, Columns) == MatrixSum(Matrix2, Rows, Columns));
	}

	static bool AreMatricesIdentical(int Matrix1[100][100], int Matrix2[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix1[i][j] != Matrix2[i][j])
				{
					return false;
				}
			}

			return true;
		}
	}
	
	static bool IsMatrixIdentity(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if ((i == j && Matrix[i][j] != 1) || (i != j && Matrix[i][j] != 0))
				{
					return false;
				}
			}
		}

		return true;
	}

	static bool IsScalarMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int ScalarValue = Matrix[0][0];

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if ((i == j && Matrix[i][j] != ScalarValue) || (i != j && Matrix[i][j] != 0))
				{
					return false;
				}
			}
		}

		return true;
	}

	static short NumberFrequencyInMatrix(int Matrix[100][100], int Rows, int Columns, int TargetedNumber)
	{
		short NumberFrequencyInMatrix = 0;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] == TargetedNumber)
				{
					NumberFrequencyInMatrix++;
				}
			}
		}

		return NumberFrequencyInMatrix;
	}

	static bool IsSparseMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		return (NumberFrequencyInMatrix(Matrix, Rows, Columns, 0) >= (Rows * Columns * 0.5));
	}

	static bool IsNumberFoundInMatrix(int Matrix[100][100], int Rows, int Columns , int TargetedNumber)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] == TargetedNumber)
				{
					return true;
				}
			}
		}

		return false;
	}

	static void PrintIntersectedNumberInTwoMatrices(int Matrix1[100][100], int Matrix2[100][100], int Rows, int Columns)
	{
		
		int IntersectedElementsArray[100];
		int IntersectedElementsArraySize = 0;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (IsNumberFoundInMatrix(Matrix2, Rows, Columns, Matrix1[i][j]))
				{
					if (!IsFoundInArray(Matrix1[i][j], IntersectedElementsArray, IntersectedElementsArraySize))
					{
						AddArrayELement(Matrix1[i][j], IntersectedElementsArray, IntersectedElementsArraySize);
					}
				}
			}
		}

		printf("\nINTERSECTED NUMBERS BETWEEN TWO MATRICES\n");
		PrintArray(IntersectedElementsArray, IntersectedElementsArraySize);

	}

	static int MaximumNumberInMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int MaximumNumberInMatrix = INT_MIN;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] > MaximumNumberInMatrix)
				{
					MaximumNumberInMatrix = Matrix[i][j];
				}
			}
		}

		return MaximumNumberInMatrix;
	}

	static int MinimumNumberInMatrix(int Matrix[100][100], int Rows, int Columns)
	{
		int MinimumNumberInMatrix = INT_MAX;

		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columns; j++)
			{
				if (Matrix[i][j] < MinimumNumberInMatrix)
				{
					MinimumNumberInMatrix = Matrix[i][j];
				}
			}
		}

		return MinimumNumberInMatrix;
	}

	static int IsMatrixPalindrome(int Matrix[100][100], int Rows, int Columns)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < (Columns / 2); j++)
			{
				if (Matrix[i][j] != Matrix[i][Columns - 1 - j])
				{
					return false;
				}
			}
		}

		return true;
	}

	static bool DoYouWantToDoThisWithoutClear(string Message)
	{
		string ReadAgain = "Y";

		do
		{
			ReadAgain = ReadStringLine(Message + " [Y/N]");
		} while (UpperCaseAllString(ReadAgain) != "Y" && UpperCaseAllString(ReadAgain) != "N");

		if (UpperCaseAllString(ReadAgain) == "Y")
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	static bool DoYouWantToDoThisWithClear(string Message)
	{
		string ReadAgain = "Y";

		do
		{
			ReadAgain = ReadStringLine(Message + " [Y/N]");

		} while (UpperCaseAllString(ReadAgain) != "Y" && UpperCaseAllString(ReadAgain) != "N");
		
		if (UpperCaseAllString(ReadAgain) == "Y")
		{
			system("cls");
			return true;
		}

		else
		{
			return false;
		}

	}

	static bool DoYouWantToDoThisWithFullClear(string Message)
	{
		string ReadAgain = "Y";

		do
		{

		} while (UpperCaseAllString(ReadAgain) != "Y" && UpperCaseAllString(ReadAgain) != "N");

		if (UpperCaseAllString(ReadAgain) == "Y")
		{
			system("color 0F");
			system("cls");
			return true;
		}

		else
		{
			return false;
		}
	}

	static void PrintFileContent(string FileName)
	{
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line;

				while (getline(File, Line))
				{
					if(Line != "")
					{
						cout << Line << "\n";
					}
				}
			

			File.close();
		}
	}

	static void LoadDataFromFileToVector(string FileName, vector<string>& FileContent)
	{
		fstream File;
		File.open(FileName, ios::in);

		if (File.is_open())
		{
			string Line; 

			while (getline(File, Line))
			{
				if (Line != "")
				{
					FileContent.push_back(Line);
				}
			}

			File.close();
		}
	}

	static void SaveVectorDataToFile(string FileName, vector<string>& FileContent)
	{
		fstream File;
		File.open(FileName, ios::out);

		if (File.is_open())
		{
			for (string& Token : FileContent)
			{
				File << Token << "\n";
			}

			File.close();
		}
	}

	static void DeleteRecordFromFile(string FileName, string Record)
	{
		vector<string>FileContent;
		LoadDataFromFileToVector(FileName, FileContent);

		for (string& Token : FileContent)
		{
			if (Token == Record)
			{
				Token = "";
			}
		}

		SaveVectorDataToFile(FileName, FileContent);
	}

	static void UpdateRecordFromFile(string FileName, string Record, string Update)
	{
		vector<string>FileContent;
		LoadDataFromFileToVector(FileName, FileContent);

		for (string& Token : FileContent)
		{
			if (Token == Record)
			{
				Token = Update;
			}
		}

		SaveVectorDataToFile(FileName, FileContent);
	}

	static string Tab(short NumberOfTabs)
	{
		string Tab = "";

		for (int i = 1; i <= NumberOfTabs; i++)
		{
			Tab += "\t";
		}

		return Tab;
	}

	static string NewLine(short NumberOfNewLines)
	{
		string NewLine = "";
		
		for (int i = 1; i <= NumberOfNewLines; i++)
		{
			NewLine += "\n";
		}

		return NewLine;
	}

	static string Alarm(short NumberOfAlarms)
	{
		string Alarm = "";

		for (int i = 1; i <= NumberOfAlarms; i++)
		{
			Alarm += "\a";
		}

		return Alarm;
	}

	static string Line(string LineStyle = "_", short LineLength = 60)
	{
		string Line = "";

		for (int i = 0; i < LineLength; i++)
		{
			Line += LineStyle;
		}

		return Line;
	}

	static void SectionBanner(string SectionName, short NumberOfTabs = 2, string LineStyle = "-", short LineLength = 60)
	{
		string SectionBannerLine = Line(LineStyle, LineLength);
		printf("\n%s\n", SectionBannerLine.c_str());
		printf("\n%s%s\n", Tab(NumberOfTabs), SectionName.c_str());
		printf("\n%s\n", SectionBannerLine.c_str());
	}

	static void PrintLineWithNewLines(string LineStyle = "_", short LineLength = 60, short StartNewLinesNumber = 2, short EndNewLinesNumber = 2, short NumberOfLines = 1)
	{
		string Linev = Line(LineStyle, LineLength);
		string StartNewLines = NewLine(StartNewLinesNumber);
		string EndNewLines = NewLine(EndNewLinesNumber);
		string FullLine = StartNewLines + Linev + EndNewLines;

		for (int i = 0; i < NumberOfLines; i++)
		{
			printf("%s", FullLine.c_str());
		}
	}

	static void PrintLineWithoutNewLines(string LineStyle = "_", short LineLength = 60, short NumberOfLines = 1)
	{
		string Linev = Line(LineStyle, LineLength);

		for (int i = 0; i < NumberOfLines; i++)
		{
			printf("%s", Linev.c_str());
 		}
	}

	static void PrintStringElementInTable(string StringElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << StringElement;
	}

	static void PrintCharacterElementInTable(char CharacterElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << CharacterElement;
	}

	static void PrintNumberElementInTable(long long NumberElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << NumberElement;
	}

	static void PrintDoubleNumberElementInTable(long double DoubleNumberElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << DoubleNumberElement;
	}

	static void PrintBooleanElementInTable(bool BooleanElement, short ElementSpace)
	{
		cout << "| " << left << setw(ElementSpace) << BooleanElement;
	}

	static void PrintChoiceInMenu(short ChoiceNumber, string Choice, short NumberOfTabs = 3)
	{
		printf("%s[%d] %s.\n", Tab(NumberOfTabs).c_str(), ChoiceNumber, Choice.c_str());
	}

	struct Time
	{
		short Hours;
		short Minutes;
		short Seconds;
	};

	static Time GetSystemTime()
	{
		time_t SystemTime = time(0);
		tm* SystemDate = localtime(&SystemTime);

		Time Time;
		Time.Hours = SystemDate->tm_hour;
		Time.Minutes = SystemDate->tm_min;
		Time.Seconds = SystemDate->tm_sec;
	}

	static void PrintLocalTime()
	{
		time_t SystemTime = time(0);
		char* LocalTime = ctime(&SystemTime);

		cout << "LOCAL TIME : " << LocalTime << "\n";
	}

	static void PrintGlobalTime()
	{
		time_t SystemTime = time(0);

		tm* gmtm = gmtime(&SystemTime);
		char* GlobalTime = asctime(gmtm);

		cout << "GLOBAL TIME : " << GlobalTime << "\n";

	}

	static void PrintBothLocalAndGlobalTime()
	{
		time_t SystemTime = time(0);
		char* LocalTime = ctime(&SystemTime);

		cout << "LOCAL TIME : " << LocalTime << "\n";

		tm* gmtm = gmtime(&SystemTime);
		char* GlobalTime = asctime(gmtm);

		cout << "GLOBAL TIME : " << GlobalTime << "\n";
	}

	static void GoToPauseMessage(string Message)
	{
		printf("%s\n", Message.c_str());
		system("pause>0");
		system("cls");
	}

	static void StartProgram(string Message, short NumberOfTabs = 2, string LineStyle = "-", short LineLength = 60, CLIColors BackgroundColor = Black, CLIColors ForegroundColor = BrightWhite)
	{
		ClearScreen();
		ChangeCLIColors(BackgroundColor, ForegroundColor);
		SectionBanner(Message, NumberOfTabs, LineStyle, LineLength);
		GoToPauseMessage("\n\nPRESS ANY KEY TO START :-) ...\n");
	}

	static void ExitProgram(string Message, short NumberOfTabs = 2, string LineStyle = "-", short LineLength = 60, CLIColors BackgroundColor = Black, CLIColors ForegroundColor = BrightWhite)
	{
		ClearScreen();
		ChangeCLIColors(BackgroundColor, ForegroundColor);
		SectionBanner(Message, NumberOfTabs, LineStyle, LineLength);
		GoToPauseMessage("\n\nPRESS ANY KEY TO EXIT :-) ...\n");
		exit(0);

	}

	static long long SumOfDigits(long long Number)
	{
		long long DigitsSum = 0;

		while (Number > 0)
		{
			DigitsSum += Number % 10;
			Number /= 10;
		}

		return DigitsSum;
	}

	static long long ReverseNumber(long long Number)
	{
		long long ReversedNumber = 0;

		while (Number > 0)
		{
			ReversedNumber = ReversedNumber * 10 + (Number % 10);
			Number /= 10;
		}

		return ReversedNumber;
	}

	static long long CountDigitFrequency(short TargetedDigit, long long Number)
	{
		short DigitFrequency = 0;
		while (Number > 0)
		{
			if (Number % 10 == TargetedDigit)
			{
				DigitFrequency++;
			}

			Number /= 10;
		}
	}

	static bool IsPalindromNumber(long long Number)
	{
		return (Number == ReverseNumber(Number));
	}

	static void PrintPerfectNumbersFrom1ToN(long long Number)
	{
		for (int i = 1; i <= Number; i++)
		{
			if (IsPerfect(i))
			{
				printf("%d ", i);
			}
		}
	}

	static void PrintNumberInReversedOrder(long long Number)
	{
		while (Number > 0)

		{
			printf("%d", Number % 10);
			Number /= 10;
		} 
	}

	static void PrintAllDigitsFrequency(long long Number)
	{
		for (int i = 0; i < 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = CountDigitFrequency(i, Number);

			if (DigitFrequency > 0)
			{
				printf("DIGIT FREQUENCY [%d] : %d\n", i, DigitFrequency);
			}
		}
	}

	static void PrintNumberInRightOrder(long long Number)
	{
		PrintNumberInReversedOrder(ReverseNumber(Number));
	}

	static void PrintInvertedNumberPattern(long long Number)
	{
		for (long long i = Number; i >= 1; i--)
		{
			for (long long j = 1; j <= i; j++)
			{
				printf("%d", i);
			}

			printf("\n");
		}
	}

	static void PrintNumberPattern(long long Number)
	{
		for (long long i = 1; i <= Number; i++)
		{
			for (long long j = 1; j <= i; j++)
			{
				printf("%d", i);
			}

			printf("\n");
		}
	}

	static void PrintInvertedLetterPattern(short Number)
	{
		for (char i = 64 + Number; i >= 65; i--)
		{
			for (int j = 1; j <= i - 64; j++)
			{
				printf("%c", i);
			}

			printf("\n");
		}
	}

	static void PrintLetterPattern(short Number)
	{
		for (char i = 65; i <= Number + 64; i++)
		{
			for (int j = 1; j <= i - 64; j++)
			{
				printf("%c", i);
			}

			printf("\n");
		}
	}

	static void PrintWordsFromAAAToZZZ()
	{
		for (char a = 65; a <= 90; a++)
		{
			for (char b = 65; b <= 90; b++)
			{
				for (char c = 65; c <= 90; c++)
				{
					string Word = "";

					Word = (a + b + c);

					printf("%s\n", Word.c_str());

				}

				
			}
		}
	}

	static bool GuessPassword(string OriginalPassword)
	{
		short Counter = 0;

		for (char a = 65; a <= 90; a++)
		{
			for (char b = 65; b <= 90; b++)
			{
				for (char c = 65; c <= 90; c++)
				{
					string Word = "";

					Word = (a + b + c);

					printf("TRIAL [%d] : %s\n", ++Counter, Word.c_str());

					if (OriginalPassword == Word)
					{
						printf("PASSWORD IS %s\n", Word.c_str());
						printf("PASSWORD IS FOUND AFTER %d TRIAL(S)\n", Counter);
						return true;
					}
				}
			}
		}

		return false;
	}

	static string Encrypt(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] += EncryptionKey;
		}

		return Text;
	}

	static string Decrypt(string Text, short DecryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] -= DecryptionKey;
		}

		return Text;
	}
	
	static char GenerateRandomCharacterType()
	{
		return GenerateRandomCharacter((RandomCharacterType)RandomNumber(1, 4));
	}

	static char GenerateRandomCharacter(RandomCharacterType RandomCharacterType)
	{
		switch (RandomCharacterType)
		{
		case Utility::SmallLetter:
			return RandomNumber(97 , 122);
		case Utility::CapitalLetter:
			return RandomNumber(65 , 90);
		case Utility::SpecialCharacter:
			return RandomNumber(33 , 47);
		case Utility::Digit:
			return RandomNumber(48 , 57);
		case Utility::RandomCharacter :
			return GenerateRandomCharacterType();
		default:
			return RandomNumber(58 , 64);
		}
	}
	
	static string GenerateWord(RandomCharacterType RandomCharacterType, short WordLength)
	{
		string Word = "";

		for (int i = 0; i < WordLength; i++)
		{
			Word += GenerateRandomCharacter(RandomCharacterType);
		}

		return Word;
	}

	static string GenerateKey(RandomCharacterType RandomCharacterType , short WordLength = 4 , short KeyParts = 4, string KeyPartsSeparator = "-")
	{
		string Key = "";

		for (int i = 0; i < KeyParts; i++)
		{
			Key += (GenerateWord(RandomCharacterType, WordLength) + KeyPartsSeparator);
		}

		return Key.substr(0, Key.length() - KeyPartsSeparator.length());
	}

	static void GenerateKeys(int KeysNumber, RandomCharacterType RandomCharacterType, short WordLength = 4, short KeyParts = 4, string KeyPartsSeparator = "-")
	{
		for (int i = 0; i < KeysNumber; i++)
		{
			printf("%s\n", GenerateKey(RandomCharacterType, WordLength, KeyParts, KeyPartsSeparator).c_str());
		}
	}

	static float ArrayAverage(int Array[100], int ArraySize)
	{
		int Sum = 0;

		for (int i = 0; i < ArraySize; i++)
		{
			Sum += Array[i];
		}

		return (Sum / ArraySize);
	}

	static void CopyPrimeNumbersFromArray(int CopiedArray[100], int CopiedArraySize, int ArrayCopy[100], int &ArrayCopySize)
	{
		ArrayCopySize = 0;

		for (int i = 0; i < CopiedArraySize; i++)
		{
			if (IsPrime(CopiedArray[i]))
			{
				AddArrayELement(CopiedArray[i], ArrayCopy, ArrayCopySize);
			}
		}
	}

	static void TwoArraySum(int Array1[100], int Array2[100], int Array3[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			Array3[i] = Array1[i] + Array2[i];
		}
	}

	static void ShuffleArray(int Array[100], int ArraySize)
	{
		for (int i = 0; i < ArraySize; i++)
		{
			Swap(Array[RandomNumber(0, ArraySize - 1)], Array[RandomNumber(0, ArraySize - 1)]);
		}
	}

	static void GenerateKeysInArray(string KeysArray[100], int NumberOfKeys, RandomCharacterType RandomCharacterType, short WordLength = 4, short KeyParts = 4, string KeyPartsSeparator = "-")
	{
		for (int i = 0; i < NumberOfKeys; i++)
		{
			KeysArray[i] = GenerateKey(RandomCharacterType, WordLength, KeyParts, KeyPartsSeparator);
		}
	}

	static void CopyArrayByAdding(int CopiedArray[100], int CopiedArraySize, int ArrayCopy[100], int& ArrayCopySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			AddArrayELement(CopiedArray[i], ArrayCopy, ArrayCopySize);
		}
	}

	static void UserInputsInArray(int Array[100], int& ArraySize)
	{
		int Number;

		do
		{
			Number = ReadPositiveNumber("ENTER A POSITIVE NUMBER");

			AddArrayELement(Number, Array, ArraySize);

		} while (DoYouWantToDoThisWithoutClear("DO YOU WANT TO ENTER A NEW NUMBER ?"));
	}

	static void CopyOddNumbersFromArray(int CopiedArray[100], int CopiedArraySize, int ArrayCopy[100], int ArrayCopySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			if (CopiedArray[i] % 2 != 0)
			{
				AddArrayELement(CopiedArray[i], ArrayCopy, ArrayCopySize);
			}
		}
	}

	static void CopyDistinctNumbersFromArray(int CopiedArray[100], int CopiedArraySize, int ArrayCopy[100], int &ArrayCopySize)
	{
		for (int i = 0; i < CopiedArraySize; i++)
		{
			if (!IsFoundInArray(CopiedArray[i], CopiedArray, CopiedArraySize))
			{
				AddArrayELement(CopiedArray[i], ArrayCopy, ArrayCopySize);
			}
		}
	}

	static int CountOddNumbersInArray(int Array[100], int ArraySize)
	{
		int OddCounter = 0;

		for (int i = 0; i < ArraySize; i++)
		{
			(Array[i] % 2 != 0) ? OddCounter++ : OddCounter;
		}

		return OddCounter;
	}

	static int CountEvenNumbersInArray(int Array[100], int ArraySize)
	{
		int EvenCounter = 0;
		for (int i = 0; i < ArraySize; i++)
		{
			(Array[i] % 2 == 0) ? EvenCounter++ : EvenCounter;
		}

		return EvenCounter;
	}
	
	static int CountPositiveNumbersInArray(int Array[100], int ArraySize)
	{
		int PositiveCounter = 0;

		for (int i = 0; i < ArraySize; i++)
		{
			(Array[i] > 0) ? PositiveCounter++ : PositiveCounter;
		}

		return PositiveCounter;
	}

	static int CountNegativeNumbersInArray(int Array[100], int ArraySize)
	{
		int NegativeCounter = 0;

		for (int i = 0; i < ArraySize; i++)
		{
			(Array[i] < 0) ? NegativeCounter++ : NegativeCounter;
		}

		return NegativeCounter;
	}

	static long double MyAbs(long double Number)
	{
		return (Number >= 0) ? Number : Number * -1;
	}

	static long long MyRound(long double Number)
	{
		long long IntegerPart = GetIntegerPart(Number);

		if (GetFloatingPoint(Number) >= 0.5)
		{
			if (Number >= 0)
			{
				return ++IntegerPart;
			}

			else
			{
				return --IntegerPart;
			}
		}

		else
		{
			return IntegerPart;
		}
	}

	static long long MyFloor(long double Number)
	{
		long long IntegerPart = GetIntegerPart(Number);

		return (Number >= 0) ? IntegerPart : --IntegerPart;
	}

	static long long MyCeil(long double Number)
	{
		long long IntegerPart = GetIntegerPart(Number);

		if (Number == IntegerPart)
		{
			return IntegerPart;
		}

		else
		{
			(Number >= 0) ? ++IntegerPart : IntegerPart;
		}
	}

	static long double MySqrt(long double Number)
	{
		return pow(Number, 0.5);
	}



};

