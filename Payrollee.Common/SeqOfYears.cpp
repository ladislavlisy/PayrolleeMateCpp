#include "stdafx.h"
#include "MonthPeriod.h"
#include "SeqOfYears.h"

#include <algorithm>
#include <xutility>
#include <numeric>
#include <iterator>     // std::back_inserter
#include <functional>

#include "stdfunctions.h"

namespace Payrollee
{
	namespace Common
	{
		unsigned int SeqOfYears::TransformZeroToUpto(unsigned int year)
		{
			return ((year == 0) ? SeqOfYears::END_YEAR_ARRAY : year);
		}

		bool SeqOfYears::SeqOfYearsGreater(unsigned int elem1, unsigned int elem2)
		{
			unsigned int compElem1 = SeqOfYears::TransformZeroToUpto(elem1);

			unsigned int compElem2 = SeqOfYears::TransformZeroToUpto(elem2);

			return compElem1 < compElem2;
		}

		struct SelectForPeriod
		{	
			MonthPeriod currPeriod;

			SelectForPeriod::SelectForPeriod(const MonthPeriod& period) : currPeriod(period)
			{
			}

			bool operator()(const SpanOfYears& span) const
			{
				return (currPeriod.Year() >= span.YearFrom() && currPeriod.Year() <= span.YearUpto());
			}
		};

		struct TransformYearsToSpan : public std::binary_function<unsigned int, unsigned int, SpanOfYears>
		{	
			const SpanOfYears operator()(unsigned int yearFrom, unsigned int yearUpto) const
			{
				unsigned int tranUpto = SeqOfYears::TransformZeroToUpto(yearUpto);
				unsigned int spanUpto = (tranUpto == yearFrom) ? tranUpto : (tranUpto - 1);
				return SpanOfYears(yearFrom, spanUpto);
			}
		};

		SeqOfYears::SeqOfYears(std::vector<unsigned int> years)
		{
			std::vector<unsigned int> sortedYears;
			std::copy(years.begin(), years.end(), std::back_inserter(sortedYears));
			std::sort(sortedYears.begin(), sortedYears.end(), SeqOfYearsGreater);

			std::vector<unsigned int> beginsYears;
			std::copy_n(sortedYears.begin(), sortedYears.size() - 1, std::back_inserter(beginsYears));

			std::vector<unsigned int> finishYears;
			std::copy_n(++sortedYears.begin(), sortedYears.size() - 1, std::back_inserter(finishYears));

			std::transform(std::begin(beginsYears), std::end(beginsYears), std::begin(finishYears),
				std::back_inserter(milestones),TransformYearsToSpan());
		}

		SeqOfYears::~SeqOfYears(void)
		{
		}

		SpanOfYears SeqOfYears::SpanForPeriod(MonthPeriod period) const
		{
			std::vector<SpanOfYears>::const_iterator itValidSpan = std::find_if(milestones.begin(), milestones.end(), SelectForPeriod(period));
			if (itValidSpan != milestones.end())
			{
				return (*itValidSpan);
			}

			return SpanOfYears();
		}

		std::vector<SpanOfYears> SeqOfYears::YearsIntervalList() const
		{
			std::vector<SpanOfYears> clonedYears;
			std::copy(milestones.begin(), milestones.end(), std::back_inserter(clonedYears));
			return clonedYears;
		}
	}
}

