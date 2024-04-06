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
#include "String.h";


using namespace std;
using namespace filesystem;


class Date
{
private : 
	short _Day;
	short _Month;
	long long _Year;

	enum CompareDatesResults { Before = -1, Equal = 0, After = 1 };

public : 

	Date()
	{
		time_t SystemTime = time(0);
		tm* SystemDate = localtime(&SystemTime);

		_Day = SystemDate->tm_mday;
		_Month = SystemDate->tm_mon + 1;
		_Year = SystemDate->tm_year + 1900;
	}

	Date(short Day, short Month, long long Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	Date(string DateString)
	{
		*this = StringToDate(DateString);
	}

	Date(short NumberOfDaysFromTheBeginningOfTheYear , long long Year)
	{
		*this = GetDateFromDayOrderInYear(NumberOfDaysFromTheBeginningOfTheYear, Year);
	}

	static void PrintDate(Date Date)
	{
		printf("%s\n", DateToString(Date).c_str());
	}

	void PrintDate()
	{
		printf("%s\n", DateToString(*this).c_str());
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay))short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth))short Month;

	void SetYear(long long Year)
	{
		_Year = Year;
	}

	long long GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear))long long Year;

	static bool IsLeapYear(long long Year)
	{
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInYear(long long Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(long long Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static short NumberOfMinutesInYear(long long Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	short NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static short NumberOfSecondsInYear(long long Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	short NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInMonth(short Month, long long Year)
	{

		if (Month < 1 || Month > 12)
		{
			return 0;
		}

		short MonthDays[] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : MonthDays[Month - 1];
	}

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, long long Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}

	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static short NumberOfMinutesInMonth(short Month, long long Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}

	short NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static short NumberOfSecondsInMonth(short Month, long long Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}

	short NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}

	static short DayOrderInWeek(short Day, short Month, long long Year)
	{
		// GREGORIAN METHOD:
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}

	static short DayOrderInWeek(Date Date)
	{
		// GREGORIAN METHOD:
		short a, y, m;
		a = (14 - Date.Month) / 12;
		y = Date.Year - a;
		m = Date.Month + (12 * a) - 2;

		return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}

	short DayOrderInWeek()
	{
		return DayOrderInWeek(_Day, _Month, _Year);
	}

	//static short DayOrderInWeek(Date Date)
	//{
	//	// GREGORIAN METHOD:
	//	short a, y, m;
	//	a = (14 - Date.Month) / 12;
	//	y = Date.Year - a;
	//	m = Date.Month + (12 * a) - 2;

	//	return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
	//		/ 12)) % 7;
	//}

	//short DayOrderInWeek()
	//{
	//	return DayOrderInWeek(*this);
	//}

	static Date GetSystemDate()
	{
		time_t SystemTime = time(0);
		tm* SystemDate = localtime(&SystemTime);

		return Date(SystemDate->tm_mday, SystemDate->tm_mon + 1, SystemDate->tm_year + 1900);
	}

	static string DayShortName(short DayOrderInWeek)
	{
		string DayShortName[] = { "SUN" , "MON" , "TUE" , "WED" , "THU" , "FRI" , "SAT" };

		return DayShortName[DayOrderInWeek];
	}

	string DayShortName()
	{
		return DayShortName(DayOrderInWeek(_Day , _Month , _Year));
	}

	static string DayLongName(short DayOrderInWeek)
	{
		string DayLongName[] = { "SUNDAY" , "MONDAY" , "TUESDAY" , "WEDNESDAY" ,
								 "THURSDAY" , "FRIDAY" , "SATURDAY" };

		return DayLongName[DayOrderInWeek];
	}

	string DayLongName()
	{
		return DayLongName(DayOrderInWeek(_Day , _Month , _Year));
	}

	static string MonthShortName(short Month)
	{
		string MonthShortName[] = { "JAN" , "FEB" , "MAR" , "APR" , "MAY" , "JUN" ,
								    "JUL" , "AUG" , "SEP" , "OCT" , "NOV" , "DEC" };

		return MonthShortName[Month - 1];
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static string MonthLongName(short Month)
	{
		string MonthLongName[] = { "JANUARY" , "FEBRUARY" , "MARCH" , "APRIL" , "MAY" ,
								  "JUNE" , "JUILET" , "AUGUST" , "SEPTEMBER" ,
								  "OCTOBER" , "NOVEMBER" , "DECEMBER" };

		return MonthLongName[Month - 1];
	}

	string MonthLongName()
	{
		return MonthLongName(_Month);
	}

	static void PrintMonthCalender(short Month, long long Year)
	{
		short MonthDays = NumberOfDaysInMonth(Month, Year);
		short FirstDayInMonth = DayOrderInWeek(1, Month, Year);

		printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
		printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");

		short i;

		for (int i = 0; i < FirstDayInMonth; i++)
		{
			printf("     ");
		}

		for (int j = 1; j <= MonthDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				printf("\n");
				i = 0;
			}
		}

		printf("\n  _________________________________\n\n");
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	static void PrintYearCalender(long long Year)
	{
		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, Year);
		}
	}

	void PrintYearCalender()
	{
		printf("\n  _________________________________\n\n");
		printf("           CALENDER - %d", Year);
		printf("\n  _________________________________\n");

		PrintYearCalender(_Year);
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, long long Year)
	{
		short NumberOfDaysFromTheBeginningOfTheYear = 0;

		for (int i = 1; i < Month; i++)
		{
			NumberOfDaysFromTheBeginningOfTheYear += NumberOfDaysInMonth(Month, Year);
		}

		return NumberOfDaysFromTheBeginningOfTheYear += Day;
	}

	static short NumberOfDaysFromTheBeginningOfTheYear(Date Date)
	{
		short NumberOfDaysFromTheBeginningOfTheYear = 0;

		for (int i = 1; i < Date.Month; i++)
		{
			NumberOfDaysFromTheBeginningOfTheYear += NumberOfDaysInMonth(Date.Month, Date.Year);
		}

		return NumberOfDaysFromTheBeginningOfTheYear += Date.Day;
	}

	short NumberOfDaysFromTheBeginningOfTheYear()
	{
		return NumberOfDaysFromTheBeginningOfTheYear(_Day, _Month, _Year);
	}

	static Date GetDateFromDayOrderInYear(short DayOrderInYear, long long Year)
	{
		Date Date;
		Date.Month = 1;
		Date.Year = Year;
		
		short RemainingDays = DayOrderInYear;

		while (true)
		{
			short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
			
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;

	}

	static Date AddDaysToDateLongMethod(Date Date, long long AddedDays)
	{
		short RemainingDays = NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year) + AddedDays;
		
		while (true)
		{
			short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}

	void AddDaysToDateLongMethod(long long AddedDays)
	{
		*this = AddDaysToDateLongMethod(*this, AddedDays);
	}

	static bool IsDate1BeforeDate2(Date Date1, Date Date2)
	{
		return (Date1.Year < Date2.Year) ||
			(Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
			(Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
	}

	bool IsDateBeforeDate2(Date Date2)
	{
		return (this->Year < Date2.Year) ||
			(this->Year == Date2.Year && this->Month < Date2.Month) ||
			(this->Year == Date2.Year && this->Month == Date2.Month && this->Day < Date2.Day);
	}

	static bool IsDate1EqualDate2(Date Date1, Date Date2)
	{
		return (Date1.Day == Date2.Day && Date1.Month == Date2.Month && Date1.Year == Date2.Year);
	}

	bool IsDateEqualDate2(Date Date2)
	{
		return (this->Day == Date2.Day && this->Month == Date2.Month && this->Year == Date2.Year);
	}

	static bool IsDate1AfterDate2(Date Date1, Date Date2)
	{
		return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
	}

	bool IsDateAfterDate2(Date Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(Date Date)
	{
		return (Date.Day == NumberOfDaysInMonth(Date.Month , Date.Year));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInTheYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInTheYear()
	{
		return IsLastMonthInTheYear(_Month);
	}

	static bool IsLastDayInTheYear(Date Date)
	{
		return (Date.Day == 31 && Date.Month == 12);
	}

	bool IsLastDayInTheYear()
	{
		return IsLastDayInTheYear(*this);
	}

	static bool IsFirstDayInTheMonth(Date Date)
	{
		return (Date.Day == 1);
	}

	bool IsFirstDayInTheMonth()
	{
		return IsFirstDayInTheMonth(*this);
	}

	static bool IsFirstMonthInTheYear(short Month)
	{
		return (Month == 1);
	}

	bool IsFirstMonthInTheYear()
	{
		return IsFirstMonthInTheYear(_Month);
	}

	static bool IsFirstDayInTheYear(Date Date)
	{
		return (Date.Day == 1 && Date.Month == 1);
	} 

	bool IsFirstDayInTheYear()
	{
		return IsFirstDayInTheYear(*this);
	}

	static Date IncreaseDateByOneDay(Date Date)
	{
		if(IsLastDayInMonth(Date))
		{
			if (IsLastDayInTheYear(Date))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}

			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}

		else
		{
			Date.Day++;
		}

		return Date;

	}

	static long long GetDifferenceBetweenTwoDatesInDays(Date Date1, Date Date2, bool IncludeEndDay = false)
	{
		short DifferenceInDays = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DifferenceInDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay) ? ++DifferenceInDays : DifferenceInDays;
	}

	long long GetDifferenceBetweenTwoDatesInDays(Date Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceBetweenTwoDatesInDays(*this, Date2, IncludeEndDay);
	}

	static bool IsDateValid(Date Date)
	{
		return !(Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year) || Date.Month > 12 || Date.Month < 1);
	}

	bool IsDateValid()
	{
		return IsDateValid(*this);
	}

	static long long AgeInDays(Date BirthDate)
	{
		Date SystemDate = GetSystemDate();
		short AgeInDays = 0;

		while (IsDate1BeforeDate2(SystemDate, BirthDate))
		{
			AgeInDays++;
			BirthDate = IncreaseDateByOneDay(BirthDate);
		}

		return ++AgeInDays;
	}

	static void Swap(Date &Date1, Date &Date2)
	{
		Date TemporaryDate;

		TemporaryDate.Day = Date1.Day;
		TemporaryDate.Month = Date1.Month;
		TemporaryDate.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		Date2.Day = TemporaryDate.Day;
		Date2.Month = TemporaryDate.Month;
		Date2.Year = TemporaryDate.Year;
	}

	static long long GetDifferenceBetweenTwoUnorderedDatesInDays(Date Date1, Date Date2, bool IncludeEndDay = false)
	{
		short SwapFlagValue = 1;
		long long DifferenceInDays = 0;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapFlagValue = -1;
			Swap(Date1, Date2);
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			DifferenceInDays++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? ++DifferenceInDays * SwapFlagValue : DifferenceInDays * SwapFlagValue;
	}
	
	long long GetDifferenceBetweenTwoUnorderedDatesInDays(Date Date2)
	{
		return GetDifferenceBetweenTwoUnorderedDatesInDays(*this, Date2);
	}

	static Date IncreaseDateByXDays(Date Date, long long Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByXDays(long long Days)
	{
		*this = IncreaseDateByXDays(*this, Days);
	}

	static Date IncreaseDateByOneWeek(Date Date)
	{
		return IncreaseDateByXDays(Date, 7);
	}

	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}

	static Date IncreaseDateByXWeeks(Date Date, long long Weeks)
	{
		for (int i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void IncreaseDateByXWeeks(long long Weeks)
	{
		*this = IncreaseDateByXWeeks(*this, Weeks);
	}

	static Date IncreaseDateByOneMonth(Date Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}

		else
		{
			Date.Month++;
		}

		short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > MonthDays)
		{
			Date.Day = MonthDays;
		}

		return Date;
	}

	void IncreaseDateByXMonths()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static Date IncreaseDateByXMonths(Date Date, long long Months)
	{
		for (int i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void IncreaseDateByXMonths(long long Months)
	{
		*this = IncreaseDateByXMonths(*this, Months);
	}

	static Date IncreaseDateByOneYear(Date Date)
	{
		return IncreaseDateByXMonths(Date , 12);
	}

	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}

	static Date IncreaseDateByXYears(Date Date, long long Years)
	{
		for (int i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	void IncreaseDateByXYears(long long Years)
	{
		*this = IncreaseDateByXYears(*this, Years);
	}

	static Date IncreaseDateByOneDecade(Date Date)
	{
		return IncreaseDateByXYears(Date, 10);
	}

	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}

	static Date IncreaseDateByXDecades(Date Date, long long Decades)
	{
		for (int i = 1; i <= Decades; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}

		return Date;
	}

	void IncreaseDateByXDecades(long long Decades)
	{
		*this = IncreaseDateByXDecades(*this, Decades);
	}

	static Date IncreaseDateByOneCentury(Date Date)
	{
		return IncreaseDateByXDecades(Date, 10);
	}

	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static Date IncreaseDateByXCenturies(Date Date, long long Centuries)
	{
		for (int i = 1; i <= Centuries; i++)
		{
			Date = IncreaseDateByOneCentury(Date);
		}

		return Date;
	}

	void IncreaseDateByXCenturies(long long Centuries)
	{
		*this = IncreaseDateByXCenturies(*this, Centuries);
	}

	static Date IncreaseDateByOneMillennium(Date Date)
	{
		return IncreaseDateByXCenturies(Date, 10);
	}

	void IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}

	static Date IncreaseDateByXMillenniums(Date Date, long long Millenniums)
	{
		for (int i = 1; i <= Millenniums; i++)
		{
			Date = IncreaseDateByOneMillennium(Date);
		}

		return Date;
	}

	void IncreaseDateByXMillenniums(long long Millenniums)
	{
		*this = IncreaseDateByXMillenniums(*this, Millenniums);
	}

	static Date DecreaseDateByOneDay(Date Date)
	{
		if (IsFirstDayInTheMonth(Date))
		{
			if (IsFirstMonthInTheYear(Date.Month))
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}

			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}

		else
		{
			Date.Day--;
		}

		return Date; 
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static Date DecreaseDateByXDays(Date Date, long long Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDays(long long Days)
	{
		*this = DecreaseDateByXDays(*this, Days);
	}

	static Date DecreaseDateByOneWeek(Date Date)
	{
		return DecreaseDateByXDays(Date, 7);
	}

	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static Date DecreaseDateByXWeeks(Date Date, long long Weeks)
	{
		for (int i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	void DecreaseDateByXWeeks(long long Weeks)
	{
		*this = DecreaseDateByXWeeks(*this, Weeks);
	}

	static Date DecreaseDateByOneMonth(Date Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}

		else
		{
			Date.Month--;
		}

		short MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > MonthDays)
		{
			Date.Day = MonthDays;
		}

		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static Date DecreaseDateByXMonths(Date Date, long long Months)
	{
		for (int i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByXMonths(long long Months)
	{
		*this = DecreaseDateByXMonths(*this, Months);
	}

	static Date DecreaseDateByOneYear(Date Date)
	{
		return DecreaseDateByXMonths(Date, 12);
	}

	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static Date DecreaseDateByXYears(Date Date, long long Years)
	{
		for (int i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	void DecreaseDateByXYears(long long Years)
	{
		*this = DecreaseDateByXYears(*this, Years);
	}

	static Date DecreaseDateByOneDecade(Date Date)
	{
		return DecreaseDateByXYears(Date, 10);
	}

	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}

	static Date DecreaseDateByXDecades(Date Date, long long Decades)
	{
		for (int i = 1; i <= Decades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;
	}

	void DecreaseDateByXDecades(long long Decades)
	{
		*this = DecreaseDateByXDecades(*this, Decades);
	}

	static Date DecreaseDateByOneCentury(Date Date)
	{
		return DecreaseDateByXDecades(Date, 10);
	}

	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static Date DecreaseDateByXCenturies(Date Date, long long Centuries)
	{
		for (int i = 1; i <= Centuries; i++)
		{
			Date = DecreaseDateByOneCentury(Date);
		}

		return Date;
	}

	void DecreaseDateByXCenturies(long long Centuries)
	{
		*this = DecreaseDateByXCenturies(*this, Centuries);
	}

	static Date DecreaseDateByOneMillennium(Date Date)
	{
		return DecreaseDateByXDecades(Date, 10);
	}

	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}

	static Date DecreaseDateByXMillenniums(Date Date, long long Millenniums)
	{
		for (int i = 1; i <= Millenniums; i++)
		{
			Date = DecreaseDateByOneMillennium(Date);
		}

		return Date;
	}

	void DecreaseDateByXMillenniums(long long Millenniums)
	{
		*this = DecreaseDateByXMillenniums(*this, Millenniums);
	}

	static bool IsThisDayTheEndOfTheWeek(Date Date)
	{
		return DayOrderInWeek(Date) == 6;
	}

	bool IsThisDayTheEndOfTheWeek()
	{
		return IsThisDayTheEndOfTheWeek(*this);
	}

	static bool IsThisDayAWeekEnd(Date Date)
	{
		return (DayOrderInWeek(Date) == 5 || DayOrderInWeek(Date) == 6);
	}

	bool IsThisDayAWeekEnd()
	{
		return IsThisDayAWeekEnd(*this);
	}

	static bool IsThisDayABusinessDay(Date Date)
	{
		return !IsThisDayAWeekEnd(Date);
	}

	bool IsThisDayABusinessDay()
	{
		return IsThisDayABusinessDay(*this);
	}

	static short DaysUntilTheEndOfTheWeek(Date Date)
	{
		return 6 - DayOrderInWeek(Date);
	}

	short DaysUntilTheEndOfTheWeek()
	{
		return DaysUntilTheEndOfTheWeek(*this);
	}

	static short DaysUntilTheEndOfTheMonth(Date Date)
	{
		return NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day + 1;
	}

	short DaysUntilTheEndOfTheMonth()
	{
		return DaysUntilTheEndOfTheMonth(*this);
	}

	static short DaysUntilTheEndOfTheYear(Date StartDate)
	{
		Date EndDate;
		EndDate.Day = 31;
		EndDate.Month = 12;
		EndDate.Year = StartDate.Year;

		return GetDifferenceBetweenTwoDatesInDays(StartDate, EndDate , true);
	}

	short DaysUntilTheEndOfTheYear()
	{
		return DaysUntilTheEndOfTheYear(*this);
	}

	static long long CalculateEndOfTheWeekDays(Date StartDate, Date EndDate)
	{
		long long EndOfTheWeekDays = 0;

		while (IsDate1BeforeDate2(StartDate, EndDate))
		{
			if (IsThisDayTheEndOfTheWeek(StartDate))
			{
				EndOfTheWeekDays++;
			}

			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return EndOfTheWeekDays;
	}

	static long long CalculateWeekEndDays(Date StartDate, Date EndDate)
	{
		long long WeekEndDays = 0;

		while (IsDate1BeforeDate2(StartDate, EndDate))
		{
			if (IsThisDayAWeekEnd(StartDate))
			{
				WeekEndDays++;
			}

			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return WeekEndDays;
	}

	static long long CalculateBusinessDays(Date StartDate, Date EndDate)
	{
		long long BusinessDays = 0;

		while (IsDate1BeforeDate2(StartDate, EndDate))
		{
			if (IsThisDayABusinessDay(StartDate))
			{
				BusinessDays++;
			}

			StartDate = IncreaseDateByOneDay(StartDate);
		}

		return BusinessDays;
	}

	static long long CalculateVacationDays(Date VacationStartDate, Date VacationEndDate)
	{
		return CalculateBusinessDays(VacationStartDate, VacationEndDate);
	}

	static Date VacationEndDate(Date VacationStartDate, long long VacationDays)
	{
		Date VacationEndDate;

		while (VacationDays > 0)
		{
			if (IsThisDayABusinessDay(VacationStartDate))
			{
				VacationDays--;
			}

			VacationStartDate = IncreaseDateByOneDay(VacationStartDate);
		}

		return VacationEndDate = VacationStartDate;
	}

	static Date VacationStartDate(Date VacationEndDate, long long VacationDays)
	{
		Date VacationStartDate;

		while (VacationDays > 0)
		{
			if (IsThisDayABusinessDay(VacationEndDate))
			{
				VacationDays--;
			}

			VacationEndDate = DecreaseDateByOneDay(VacationEndDate);
		}

		return VacationStartDate = VacationEndDate;
	}

	static CompareDatesResults CompareDates(Date Date1, Date Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
		{
			return Before;
		}

		if (IsDate1AfterDate2(Date1, Date2))
		{
			return After;
		}

		return Equal;
	}

	CompareDatesResults CompareDates(Date Date2)
	{
		return CompareDates(*this, Date2);
	}

	static Date StringToDate(string DateString)
	{
		vector<string> DateVector = String::SplitStringWordstoVector(DateString, "/");

		Date Date;
		Date.Day = stoi(DateVector[0]);
		Date.Month = stoi(DateVector[1]);
		Date.Year = stoll(DateVector[2]);

		return Date;
	}

	static string DateToString(Date Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static string FormatDate(Date Date, string DateFormat = "DD/MM/YYYY")
	{
		string FormattedDate = String::ReplaceWordsInStringUsingBuiltInFunction(DateFormat, "DD", to_string(Date.Day));
		FormattedDate = String::ReplaceWordsInStringUsingBuiltInFunction(FormattedDate, "MM", to_string(Date.Month));
		FormattedDate = String::ReplaceWordsInStringUsingBuiltInFunction(FormattedDate, "YYYY", to_string(Date.Year));

		return FormattedDate;
	}

	string FormatDate(string DateFormat = "DD/MM/YYY")
	{
		return FormatDate(*this, DateFormat);
	}

	static string GetSystemDateInStringForm(string DateFormat = "DD/MM/YYYY")
	{
		return FormatDate(GetSystemDate() , DateFormat);
	}

	static string GetSystemDateTimeStringForm()
	{
		time_t NowTime = time(0);
		tm* SystemTime = localtime(&NowTime);

		short Hours = SystemTime->tm_hour;
		short Minutes = SystemTime->tm_min;
		short Seconds = SystemTime->tm_sec;


		return GetSystemDateInStringForm() + " - " + to_string(Hours) + ":" +
			to_string(Minutes) + ":" + to_string(Seconds);
	}

};



