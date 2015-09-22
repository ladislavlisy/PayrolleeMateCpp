#pragma once

#include <string>
#include <sstream>
#include <iostream>

namespace Payrollee
{
	namespace Common
	{
		class MonthPeriod
		{
		public:
			static const unsigned int PRESENT = 0;
			static const unsigned int TERM_BEG_FINISHED = 32;
			static const unsigned int TERM_END_FINISHED =  0;

		private:
			unsigned int code;
		
		public:
			MonthPeriod(unsigned int code);
			MonthPeriod(const MonthPeriod& element);
			~MonthPeriod(void);

		public:
			static MonthPeriod Empty();
			static MonthPeriod BeginYear(unsigned int year);
			static MonthPeriod EndYear(unsigned int year);

		public:
			unsigned int Code() const {
				return code;
			}
			unsigned int Year() const {
				return (code / 100);
			}
			unsigned int Month() const {
				return (code % 100);
			}
			int YearInt() const {
				return (code / 100);
			}
			int MonthInt() const {
				return (code % 100);
			}
			int MonthOrder() const {
				return __max(0, YearInt() - 2000) * 12 + MonthInt();
			}
			int DaysInMonth() const {
				return 0;
			}
			COleDateTime BeginOfMonth() const; 
			COleDateTime EndOfMonth() const; 

			COleDateTime DateOfMonth(int dayOrdinal) const; 
			int WeekDayOfMonth(int dayOrdinal) const; 
			int DayOfWeekMonToSun(const COleDateTime periodDate) const; 

			CString Description() const; 

			int CompareTo(const MonthPeriod& other) const; 
			bool isEqualToPeriod(const MonthPeriod& other)  const; 

			const MonthPeriod& operator=(const MonthPeriod& element);

			bool operator==(const MonthPeriod& other) const; 
			bool operator!=(const MonthPeriod& other) const; 
			bool operator<(const MonthPeriod& other) const; 
			bool operator>(const MonthPeriod& other) const; 
			bool operator<=(const MonthPeriod& other) const; 
			bool operator>=(const MonthPeriod& other) const; 

			CString ToString() const; 

			friend std::wstringstream &operator<<( std::wstringstream &output, const MonthPeriod &element )
			{ 
				output << _T("Code : ") << element.code << _T(" Description : ") << element.Description();
				return output;            
			}
		};
	}
}
