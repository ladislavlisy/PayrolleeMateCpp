#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "SpanOfYears.h"
#include "MonthPeriod.h"

namespace Payrollee
{
	namespace Common
	{
		class SeqOfYears
		{
		public:
			static const unsigned int END_YEAR_ARRAY = 2100;
			static const unsigned int END_YEAR_INTER = 2099;
		public:
			static unsigned int TransformZeroToUpto(unsigned int year);
			static bool SeqOfYearsGreater(unsigned int elem1, unsigned int elem2);
		private:
			V_SPAN_OFYEARS milestones;

		public:
			SeqOfYears(std::vector<unsigned int> years);
			~SeqOfYears(void);

		public:
			SpanOfYears SpanForPeriod(MonthPeriod period) const;

			void YearsIntervalList(V_SPAN_OFYEARS& clonedYears) const;

			friend std::wstringstream &operator<<( std::wstringstream &output, const SeqOfYears &element )
			{ 
				output << _T("Count : ") << element.milestones.size();
				return output;            
			}
		};

	}
}
