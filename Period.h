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
#include "String.h"
#include"Date.h"

using namespace std;
using namespace filesystem;

class Period
{
private : 
	Date _StartDate;
	Date _EndDate;

public :
	Period(Date StartDate, Date EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;
	}

	static void PrintPeriod(Period Period)
	{
		printf("\nSTART DATE : %s\n", Date::DateToString(Period._StartDate).c_str());
		printf("END DATE : %s\n", Date::DateToString(Period._EndDate).c_str());
	}

	void PrintPeriod()
	{
		printf("\nSTART DATE : %s\n", Date::DateToString(_StartDate).c_str());
		printf("END DATE : %s\n", Date::DateToString(_EndDate).c_str());
	}

	static bool ArePeriodsOverlap(Period Period1, Period Period2)
	{
		return !(Date::IsDate1BeforeDate2(Period1._EndDate, Period2._StartDate) || Date::IsDate1BeforeDate2(Period2._EndDate, Period1._StartDate));
	}

	bool ArePeriodsOverlap(Period Period2)
	{
		return ArePeriodsOverlap(*this, Period2);
	}

	static long long PeriodLengthInDays(Period Period, bool IncludeEndDay = false)
	{
		return Date::GetDifferenceBetweenTwoDatesInDays(Period._StartDate, Period._EndDate, IncludeEndDay);
	}

	long long PeriodLengthInDays(bool IncludeEndDay = false)
	{
		return PeriodLengthInDays(*this, IncludeEndDay);
	}

	static bool IsThisDateInThisPeriod(Date Date, Period Period)
	{
		return !(Date::IsDate1BeforeDate2(Date, Period._StartDate) || Date::IsDate1AfterDate2(Date, Period._EndDate));
	}

	bool IsThisDateInThisPeriod(Date Date)
	{
		return IsThisDateInThisPeriod(Date, *this);
	}

	static long long CountOverlapDaysBetweenTwoPeriods(Period Period1, Period Period2)
	{
		if (ArePeriodsOverlap(Period1, Period2))
		{
			return 0;
		}

		long long Period1Length = PeriodLengthInDays(Period1);
		long long Period2Length = PeriodLengthInDays(Period2);
		long long OverlapDays = 0;

		if (Period1Length <= Period2Length)
		{
			while (Date::IsDate1BeforeDate2(Period1._StartDate, Period2._EndDate))
			{
				if (IsThisDateInThisPeriod(Period1._StartDate, Period2))
				{
					OverlapDays++;
				}

				Period1._StartDate = Date::IncreaseDateByOneDay(Period1._StartDate);
			}
		}

		else
		{
			while (Date::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate))
			{
				if (IsThisDateInThisPeriod(Period2._StartDate, Period1))
				{
					OverlapDays++;
				}

				Period2._StartDate = Date::IncreaseDateByOneDay(Period2._StartDate);
			}
		}

		return OverlapDays;
	}

	long long CountOverlapDaysBetweenTwoPeriods(Period Period2)
	{
		return CountOverlapDaysBetweenTwoPeriods(*this, Period2);
	}

};

