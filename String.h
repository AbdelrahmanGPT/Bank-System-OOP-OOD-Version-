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


using namespace std;
using namespace filesystem;

class String
{
private :
	string _Value;
	enum WhatToCountInString { CapitalLetters = 1, SmallLetters = 2, VowelLetters = 3,
							   AllLetters = 4, Digits = 5, SpecialCharacters = 6, 
							   AllCharacters = 7 };

	enum WhatToRemoveFromString { rCapitalLetters = 1, rSmallLetters = 2, 
								  rVowelLetters = 3, rAllLetters = 4, rDigits = 5, 
								  rSpecialCharacters = 6, rAllCharacters = 7 };

public :
	//DEFAULT CONSTRUCTOR
	String()
	{
		_Value = "";
	}

	//PARAMETRIZED CONSTRUCTOR
	String(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;

	static void Print(string Word)
	{
		printf("%s", Word.c_str());
	}

	void Print()
	{
		Print(_Value);
	}

	static void PrintFirstLetterOfEachWordInString(string Word)
	{
		bool FirstLetter = true;

		for (int i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ' && FirstLetter)
			{
				cout << Word[i] << "\n";
			}

			FirstLetter = (Word[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWordInString()
	{
		PrintFirstLetterOfEachWordInString(_Value);
	}

	static string UpperCaseFirstLetterInEachWordInString(string Word)
	{
		bool FirstLetter = true;

		for (int i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ' && FirstLetter)
			{
				Word[i] = toupper(Word[i]);
			}

			FirstLetter = (Word[i] == ' ' ? true : false);
		}

		return Word;
	}

	void UpperCaseFirstLetterInEachWordInString()
	{
		_Value = UpperCaseFirstLetterInEachWordInString(_Value);
	}

	static string LowerCaseFirstLetterInEachWordInString(string Word)
	{
		bool FirstLetter = true;

		for (int i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ' && FirstLetter)
			{
				Word[i] = tolower(Word[i]);
			}

			FirstLetter = (Word[i] == ' ' ? true : false);
		}

		return Word;
	}

	void LowerCaseFirstLetterInEachWordInString()
	{
		_Value = LowerCaseFirstLetterInEachWordInString(_Value);
	}

	static string LowerCaseAllString(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			Word[i] = tolower(Word[i]);
		}

		return Word;
	}

	void LowerCaseAllString()
	{
		_Value = LowerCaseAllString(_Value);
	}

	static string UpperCaseAllString(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			Word[i] = toupper(Word[i]);
		}

		return Word;
	}

	void UpperCaseAllString()
	{
		 _Value = UpperCaseAllString(_Value);
	}

	static char InvertLetterCase(char Character)
	{
		return isupper(Character) ? tolower(Character) : toupper(Character);
	}

	static string InvertAllLettersCaseInString(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			Word[i] = InvertLetterCase(Word[i]);
		}

		return Word;
	}

	void InvertAllLettersCaseInString()
	{
		 _Value = InvertAllLettersCaseInString(_Value);
	}

	static short CountCapitalLettersInString(string Word)
	{
		short CapitalLettersCounter = 0;
		for (int i = 0; i < Word.length(); i++)
		{
			isupper(Word[i]) ? CapitalLettersCounter++ : CapitalLettersCounter;
		}

		return CapitalLettersCounter;
	}

	short CountCapitalLettersInString()
	{
		return CountCapitalLettersInString(_Value);
	}

	static short CountSmallLettersInString(string Word)
	{
		short SmallLettersCounter = 0;

		for (int i = 0; i < Word.length(); i++)
		{
			islower(Word[i]) ? SmallLettersCounter++ : SmallLettersCounter;
		}

		return SmallLettersCounter;
	}

	short CountSmallLettersInString()
	{
		return CountSmallLettersInString(_Value);
	}

	static short CountAllLettersInString(string Word)
	{
		short LettersCounter = 0;
		for (int i = 0; i < Word.length(); i++)
		{
			if (isupper(Word[i]) || islower(Word[i]))
			{
				LettersCounter++;
			}
		}

		return LettersCounter;
	}

	short CountAllLettersInString()
	{
		return CountAllLettersInString(_Value);
	}

	static short CountDigitsInString(string Word)
	{
		short DigitsCounter = 0;

		for (int i = 0; i < Word.length(); i++)
		{
			isdigit(Word[i]) ? DigitsCounter++ : DigitsCounter;
		}

		return DigitsCounter;
	}
	 
	short CountDigitsInString()
	{
		return CountDigitsInString(_Value);
	}

	static short CountSpecialCharactersInString(string Word)
	{
		short SpecialCharactersCounter = 0;

		for (int i = 0; i < Word.length(); i++)
		{
			ispunct(Word[i]) ? SpecialCharactersCounter++ : SpecialCharactersCounter;
		}

		return SpecialCharactersCounter;
	}

	short CountSpecialCharactersInString()
	{
		return CountSpecialCharactersInString(_Value);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'o') || (Letter == 'u')
			|| (Letter == 'i'));
	}

	static short CountVowelLettersInString(string Word)
	{
		short VowelLettersCounter = 0;
		for (int i = 0; i < Word.length(); i++)
		{
			IsVowel(Word[i]) ? VowelLettersCounter++ : VowelLettersCounter;
		}

		return VowelLettersCounter;
	}

	short CountVowelLettersInString()
	{
		return CountVowelLettersInString(_Value);
	}

	short static CountCharactersInString(string Word, WhatToCountInString WhatToCountInString = AllCharacters)
	{
		switch (WhatToCountInString)
		{
		case String::CapitalLetters:
			return CountCapitalLettersInString(Word);
		case String::SmallLetters:
			return CountSmallLettersInString(Word);
		case String::VowelLetters:
			return CountVowelLettersInString(Word);
		case String::AllLetters:
			return CountAllLettersInString(Word);
		case String::Digits:
			return CountDigitsInString(Word);
		case String::SpecialCharacters:
			return CountSpecialCharactersInString(Word);
		case String::AllCharacters:
			return Word.length();
		default:
			return 0;;
		}
	}

	short CountCharactersInString(WhatToCountInString WhatToCountInString = AllCharacters)
	{
		return CountCharactersInString(_Value, WhatToCountInString);
	}

	static short LetterFrequencyInString(string Word, char TargetedLetter, bool MatchCase = true)
	{
		short LetterFrequency = 0;

		for (int i = 0; i < Word.length(); i++)
		{
			if (MatchCase)
			{
				(Word[i] == TargetedLetter) ? LetterFrequency++ : LetterFrequency;
			}

			else
			{
				(tolower(Word[i]) == tolower(TargetedLetter)) ? LetterFrequency++ : LetterFrequency;
			}
		}

		return LetterFrequency;
	}

	short LetterFrequencyInString(char TargetedLetter, bool MatchCase = true)
	{
		return LetterFrequencyInString(_Value, TargetedLetter, MatchCase);
	}

	static short CountWordsInString(string Sentence, string Delimiter = " ")
	{
		short WordsCounter = 0;
		short DelimiterPosition = 0;
		string Word = "";
		
		while ((DelimiterPosition = Sentence.find(Delimiter)) != string::npos)
		{
			Word = Sentence.substr(0, DelimiterPosition);

			if (Word != "")
			{
				WordsCounter++;
			}

			Sentence.erase(0, DelimiterPosition + Delimiter.length());
		}

		if (Sentence != "")
		{
			WordsCounter++;
		}

		return WordsCounter++;
	}

	short CountWordsInString(string Delimiter = " ")
	{
		return CountWordsInString(_Value, Delimiter);
	}

	static vector<string> SplitStringWordstoVector(string Sentence, string Delimiter)
	{
		string Word = "";
		short DelimiterPosition = 0;
		vector<string>StringVector;

		while ((DelimiterPosition = Sentence.find(Delimiter)) != string::npos)
		{
			Word = Sentence.substr(0, DelimiterPosition);

			if (Word != "")
			{
				StringVector.push_back(Word);
			}


			Sentence.erase(0, DelimiterPosition + Delimiter.length());
		}

		if (Sentence != "")
		{
			StringVector.push_back(Sentence);
		}

		return StringVector;
	}

	vector<string> SplitStringWordstoVector(string Delimiter = " ")
	{
		return SplitStringWordstoVector(_Value, Delimiter);
	}

	static string TrimLeft(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			if (Word[i] != ' ')
			{
				return Word.substr(i, Word.length() - i);
			}
		}

		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Word)
	{
		for (int i = Word.length() - 1; i >= 0; i--)
		{
			if (Word[i] != ' ')
			{
				return Word.substr(0, i + 1);
			}
		}

		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Word)
	{
		return TrimRight(TrimLeft(Word));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinStringsFromVector(vector<string>& StringVector, string Separator)
	{
		string ResultedString = "";
		for (string& Token : StringVector)
		{
			ResultedString += (Token + Separator);
		}

		return ResultedString.substr(0, ResultedString.length() - Separator.length());
	}

	static string JoinStringsFromArray(string StringArray[100] , int ArrayLength, string Separator)
	{
		string ResultedString = "";
		
		for (int i = 0; i < ArrayLength; i++)
		{
			ResultedString += (StringArray[i] + Separator);
		}

		return ResultedString.substr(0, ResultedString.length() - Separator.length());
	}

	static string JoinStringsFromVectorInReversedOrder(vector<string>& StringVector, string Separator)
	{
		string ResultedString = "";
		
		for (int i = StringVector.size() - 1; i >= 0; i--)
		{
			ResultedString += (StringVector[i] + Separator);
		}

		return ResultedString.substr(0, ResultedString.length() - Separator.length());
	}

	static string JoinStringsFromArrayInReversedOrder(string StringArray[100], int ArrayLength, string Separator)
	{
		string ResultedString = "";
		for (int i = ArrayLength - 1; i >= 0; i--)
		{
			ResultedString += (StringArray[i] + Separator);
		}

		return ResultedString.substr(0, ResultedString.length() - Separator.length());
	}

	static string ReverseWordsInString(string Word)
	{
		/*vector<string>StringVector = SplitStringWordstoVector(Word , " ");
		vector<string>::iterator iter;
		string ReversedString = "";

		for (iter = StringVector.end(); iter != StringVector.begin(); iter += 0)
		{
			iter--;

			ReversedString += (*iter + " ");
		}

		return ReversedString.substr(0, ReversedString.length() - 1);*/

		//ANOTHER IMPLEMENTATION : 

		vector<string>StringVector = SplitStringWordstoVector(Word, " ");
		return JoinStringsFromVectorInReversedOrder(StringVector, " ");
 	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWordsInStringUsingBuiltInFunction(string Sentence , string ReplacedWord, string ReplacingWord)
	{
		short ReplacedWordPosition = 0;
		while ((ReplacedWordPosition = Sentence.find(ReplacedWord)) != std::string::npos)
		{
			Sentence = Sentence.replace(ReplacedWordPosition, ReplacedWord.length(), ReplacingWord);
		}

		return Sentence;
	}

	void ReplaceWordsInStringUsingBuiltInFunction(string ReplacedWord, string ReplacingWord)
	{
		_Value = ReplaceWordsInStringUsingBuiltInFunction(_Value, ReplacedWord, ReplacingWord);
	}

	static string ReplaceWordsInString(string Sentence, string ReplacedWord, string ReplacingWord , bool MatchCase = true)
	{
		vector<string>StringVector = SplitStringWordstoVector(Sentence, " ");

		for (string& Token : StringVector)
		{
			if(MatchCase)
			{
				if (Token == ReplacedWord)
				{
					Token = ReplacingWord;
				}
			}
			
			else
			{
				if (LowerCaseAllString(Token) == LowerCaseAllString(ReplacedWord))
				{
					Token = ReplacingWord;
				}
			}
		}

		return JoinStringsFromVector(StringVector, " ");

	}

	void ReplaceWordsInString(string ReplacedWord, string ReplacingWord, bool MatchCase = true)
	{
		_Value = ReplaceWordsInString(_Value, ReplacingWord, ReplacingWord, MatchCase);
	}

	static string ReplaceCharactersInString(string Word, char ReplacedCharacter, char ReplacingCharacter)
	{
		for (char& Character : Word)
		{
			if (Character == ReplacedCharacter)
			{
				Character = ReplacingCharacter;
			}
		}

		return Word;
	}

	void ReplaceCharactersInString(char ReplacedCharacter, char ReplacingCharacter)
	{
		_Value = ReplaceCharactersInString(_Value, ReplacedCharacter, ReplacingCharacter);
	}

	static string ReplaceLettersInString(string Word, char ReplacedLetter, char ReplacingLetter, bool MatchCase = true)
	{
		for (char& Character : Word)
		{
			if(MatchCase)
			{
				if (Character == ReplacedLetter)
				{
					Character = ReplacingLetter;
				}
			}

			else
			{
				if (tolower(Character) == tolower(ReplacedLetter))
				{
					Character == ReplacingLetter;
				}
			}
		}

		return Word;
	}

	void ReplaceLettersInString(char ReplacedLetter, char ReplacingLetter, bool MatchCase = true)
	{
		_Value = ReplaceLettersInString(_Value, ReplacedLetter, ReplacingLetter, MatchCase);
	}

	static string RemoveSpecialCharactersFromString(string Word)
	{
		string FilteredString = "";

		for (char& Character : Word)
		{
			if (!ispunct(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	void RemoveSpecialCharactersFromString()
	{
		_Value = RemoveSpecialCharactersFromString(_Value);
	}

	static string RemoveCapitalLettersFromString(string Word)
	{
		string FilteredString = "";

		for (char& Character : Word)
		{
			if (!isupper(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	void RemoveCapialLettersFromString()
	{
		_Value = RemoveCapitalLettersFromString(_Value);
	}

	static string RemoveSmallLettersFromString(string Word)
	{
		string FilteredString = "";

		for (char& Character : Word)
		{
			if (!islower(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	void RemoveSmallLettersFromString()
	{
		_Value = RemoveSmallLettersFromString(_Value);
	}

	static string RemoveVowelLettersFromString(string Word)
	{
		string FilteredString = "";
		
		for (char& Character : Word)
		{
			if (!IsVowel(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	void RemoveVowelLettersFromString()
	{
		_Value = RemoveVowelLettersFromString(_Value);
	}

	static string RemoveDigitsFromString(string Word)
	{
		string FilteredString = "";

		for (char& Character : Word)
		{
			if (!isdigit(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	void RemoveDigitsFromString()
	{
		_Value = RemoveDigitsFromString(_Value);
	}

	static string RemoveAllLettersFromString(string Word)
	{
		string FilteredString = "";

		for (char& Character : Word)
		{
			if (!isupper(Character) && !islower(Character))
			{
				FilteredString += Character;
			}
		}

		return FilteredString;
	}

	void RemoveAllLettersFromString()
	{
		_Value = RemoveAllLettersFromString(_Value);
	}

	static string RemoveCharacterFromString(string Word, char Character)
	{
		string FilteredString = "";

		for (char& Characterf : Word)
		{
			if (Character != Characterf)
			{
				FilteredString += Characterf;
			}
		}

		return FilteredString;
	}

	void RemoveCharacterFromString(char Character)
	{
		_Value = RemoveCharacterFromString(_Value, Character);
	}

	static string RemoveLetterFromString(string Word, char TargetedLetter, bool MatchCase = true)
	{
		string FilteredString = "";

		for (char& Character : Word)
		{
			if (MatchCase)
			{
				if (Character != TargetedLetter)
				{
					FilteredString += Character;
				}
			}

			else
			{
				if(tolower(Character) != tolower(TargetedLetter))
				{
					FilteredString += Character;
				}
			}
		}
	}

	void RemoveLetterFromString(char TargetedLetter, bool MatchCase = true)
	{
		_Value = RemoveLetterFromString(_Value, TargetedLetter, MatchCase);
	}

	static string RemoveWordsFromString(string Sentence, string RemovedWord, bool MatchCase = true)
	{
		vector<string>StringVector = SplitStringWordstoVector(Sentence , " ");
		string FilteredString = "";

		for (string& Token : StringVector)
		{
			if(MatchCase)
			{
				if (Token != RemovedWord)
				{
					FilteredString += (Token + " ");
				}
			}

			else
			{
				if (LowerCaseAllString(Token) != LowerCaseAllString(RemovedWord))
				{
					FilteredString += (Token + " ");
				}
			}
		}

		return FilteredString.substr(0, FilteredString.length() - 1);
	}

	void RemoveWordsFromString(string RemovedWord, bool MatchCase = true)
	{
		_Value = RemoveWordsFromString(_Value , RemovedWord, MatchCase);
	}

	static string RemoveCharactersFromString(string Word, WhatToRemoveFromString WhatToRemoveFromString = rAllCharacters)
	{
		switch (WhatToRemoveFromString)
		{
		case String::rCapitalLetters:
			return RemoveCapitalLettersFromString(Word);
		case String::rSmallLetters:
			return RemoveSmallLettersFromString(Word);
		case String::rVowelLetters:
			return RemoveVowelLettersFromString(Word);
		case String::rAllLetters:
			return RemoveAllLettersFromString(Word);
		case String::rDigits:
			return RemoveDigitsFromString(Word);
		case String::rSpecialCharacters:
			return RemoveSpecialCharactersFromString(Word);
		case String::rAllCharacters:
			return "";
		default:
			printf("\nINVALID METHOD CHOICE\n");
			return Word;
		}
	}

	void RemoveCharactersFromString(WhatToRemoveFromString WhatToRemoveFromString = rAllCharacters)
	{
		_Value = RemoveCharactersFromString(_Value, WhatToRemoveFromString);
	}

};

