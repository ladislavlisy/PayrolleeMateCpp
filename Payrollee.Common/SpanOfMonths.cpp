#include "stdafx.h"
#include "SpanOfMonths.h"
#include "MonthPeriod.h"

namespace Payrollee
{
	namespace Common
	{
		SpanOfMonths::SpanOfMonths(void) : periodFrom(MonthPeriod::PRESENT), periodUpto(MonthPeriod::PRESENT)
		{
		}

		SpanOfMonths::SpanOfMonths(const MonthPeriod& from, const MonthPeriod& upto) : periodFrom(from), periodUpto(upto)
		{
		}

		SpanOfMonths::SpanOfMonths(const SpanOfMonths& element) : periodFrom(element.periodFrom), periodUpto(element.periodUpto)
		{
		}

		SpanOfMonths::~SpanOfMonths(void)
		{
		}

		SpanOfMonths SpanOfMonths::Year(unsigned int year)
		{
			return SpanOfMonths(MonthPeriod::BeginYear(year), MonthPeriod::EndYear(year));
		}

		SpanOfMonths SpanOfMonths::Month(const MonthPeriod& period)
		{
			return SpanOfMonths(period, period);
		}

		const SpanOfMonths& SpanOfMonths::operator=(const SpanOfMonths& element)
		{
			periodFrom = (element.periodFrom);
			periodUpto = (element.periodUpto);
			return *this;
		}

		bool SpanOfMonths::operator ==(const SpanOfMonths& other) const
		{
			return (periodFrom == (other.periodFrom) && periodUpto == (other.periodUpto));
		}

		bool SpanOfMonths::operator !=(const SpanOfMonths& other) const
		{
			return (periodFrom != (other.periodFrom) || periodUpto != (other.periodUpto));
		}

		bool SpanOfMonths::operator <(const SpanOfMonths& element) const
		{
			return (this->periodFrom < element.periodFrom) || (this->periodFrom == element.periodFrom && (this->periodUpto < element.periodUpto));
		}

		bool SpanOfMonths::operator >(const SpanOfMonths& element) const
		{
			return (this->periodFrom > element.periodFrom) || (this->periodFrom == element.periodFrom && (this->periodUpto > element.periodUpto));
		}

		bool SpanOfMonths::operator <=(const SpanOfMonths& element) const
		{
			return (this->periodFrom <= element.periodFrom) || (this->periodFrom == element.periodFrom && (this->periodUpto <= element.periodUpto));
		}

		bool SpanOfMonths::operator >=(const SpanOfMonths& element) const
		{
			return (this->periodFrom >= element.periodFrom) || (this->periodFrom == element.periodFrom && (this->periodUpto >= element.periodUpto));
		}

		int SpanOfMonths::CompareTo(const SpanOfMonths& other) const
		{
			if (this->periodFrom != other.periodFrom)
			{
				return this->periodFrom.CompareTo(other.periodFrom);
			}
			return (this->periodUpto.CompareTo(other.periodUpto));
		}

		bool SpanOfMonths::isEqualToInterval(const SpanOfMonths& other) const
		{
			return (this->periodFrom == other.periodFrom && this->periodUpto == other.periodUpto);
		}

		CString SpanOfMonths::ClassName() const
		{
			CString classNameBuilder(periodFrom.ToString());

			if(periodFrom != periodUpto)
			{
				classNameBuilder + _T("to") + periodUpto.ToString();
			}
			return classNameBuilder;
		}

		CString SpanOfMonths::ToString() const
		{
			return this->ClassName();
		}
	}
}

