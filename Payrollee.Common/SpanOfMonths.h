#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "MonthPeriod.h"

namespace Payrollee
{
	namespace Common
	{
		class SpanOfMonths
		{
		private:
			MonthPeriod periodFrom;
			MonthPeriod periodUpto;
		public:
			SpanOfMonths(void);
			SpanOfMonths(const MonthPeriod& from, const MonthPeriod& upto);
			SpanOfMonths(const SpanOfMonths& element);

			~SpanOfMonths(void);
		public:
			static SpanOfMonths Year(unsigned int year);

			static SpanOfMonths Month(const MonthPeriod& period);

			const MonthPeriod& PeriodFrom() const { return periodFrom; }
			const MonthPeriod& PeriodUpto() const { return periodUpto; }

			const SpanOfMonths& operator=(const SpanOfMonths& element);
			bool operator ==(const SpanOfMonths& other) const;
			bool operator !=(const SpanOfMonths& other) const;
			bool operator < (const SpanOfMonths& other) const;
			bool operator > (const SpanOfMonths& other) const;
			bool operator <=(const SpanOfMonths& other) const;
			bool operator >=(const SpanOfMonths& other) const;

			int CompareTo(const SpanOfMonths& other) const;

			bool isEqualToInterval(const SpanOfMonths& other) const;

			CString ClassName() const;

			CString ToString() const;

			friend std::wstringstream &operator<<( std::wstringstream &output, const SpanOfMonths &element )
			{ 
				output << _T("From : ") << element.PeriodFrom().ToString() << _T("\nUpto : ") << element.PeriodUpto().ToString() << _T("\nClazz : ") << element.ClassName();
				return output;            
			}
		};
	}
}

