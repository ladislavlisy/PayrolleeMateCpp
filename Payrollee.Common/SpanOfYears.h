#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

namespace Payrollee
{
	namespace Common
	{
		class SpanOfYears
		{
		private:
			unsigned int yearFrom;
			unsigned int yearUpto;

		public:
			static SpanOfYears Year(unsigned int year);
			static SpanOfYears Years(unsigned int from, unsigned int upto);

		public:
			SpanOfYears();
			SpanOfYears(unsigned int from, unsigned int upto);
			SpanOfYears(const SpanOfYears& element);
			~SpanOfYears(void);

		public:
			unsigned int YearFrom() const { return yearFrom; }
			unsigned int YearUpto() const { return yearUpto; }

			const SpanOfYears& operator=(const SpanOfYears& element);
			bool operator ==(const SpanOfYears& other) const;
			bool operator !=(const SpanOfYears& other) const;
			bool operator < (const SpanOfYears& element) const;
			bool operator > (const SpanOfYears& element) const;
			bool operator <=(const SpanOfYears& element) const;
			bool operator >=(const SpanOfYears& element) const;

			int CompareTo(const SpanOfYears& other) const;

			bool isEqualToInterval(const SpanOfYears& other) const;

			CString ClassName() const;

			CString ToString() const;

			friend std::wstringstream &operator<<( std::wstringstream &output, const SpanOfYears &element )
			{ 
				output << _T("From : ") << element.yearFrom << _T(" Upto : ") << element.yearUpto << _T(" Clazz : ") << element.ClassName();
				return output;            
			}
		};

		typedef std::vector<SpanOfYears> V_SPAN_OFYEARS;

	}
}
