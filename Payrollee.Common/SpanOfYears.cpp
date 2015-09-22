#include "stdafx.h"
#include "SpanOfYears.h"


namespace Payrollee
{
	namespace Common
	{
		SpanOfYears::SpanOfYears()
		{
			this->yearFrom = 0;
			this->yearUpto = 0;
		}

		SpanOfYears::SpanOfYears(unsigned int from, unsigned int upto)
		{
			this->yearFrom = from;
			this->yearUpto = upto;
		}

		SpanOfYears::SpanOfYears(const SpanOfYears& element)
		{
			this->yearFrom = element.yearFrom;
			this->yearUpto = element.yearUpto;
		}

		SpanOfYears Year(unsigned int year)
		{
			return SpanOfYears(year, year);
		}

		SpanOfYears Years(unsigned int from, unsigned int upto)
		{
			return SpanOfYears(from, upto);
		}

		SpanOfYears::~SpanOfYears(void)
		{
		}

		const SpanOfYears& SpanOfYears::operator=(const SpanOfYears& element)
		{
			this->yearFrom = element.yearFrom;
			this->yearUpto = element.yearUpto;
			return *this;
		}

		bool SpanOfYears::operator ==(const SpanOfYears& other) const
		{
			return (yearFrom == (other.yearFrom) && yearUpto == (other.yearUpto));
		}

		bool SpanOfYears::operator !=(const SpanOfYears& other) const
		{
			return (yearFrom != (other.yearFrom) || yearUpto != (other.yearUpto));
		}

		bool SpanOfYears::operator <(const SpanOfYears& element) const
		{
			return (this->yearFrom < element.yearFrom) || (this->yearFrom == element.yearFrom && (this->yearUpto < element.yearUpto));
		}

		bool SpanOfYears::operator >(const SpanOfYears& element) const
		{
			return (this->yearFrom > element.yearFrom) || (this->yearFrom == element.yearFrom && (this->yearUpto > element.yearUpto));
		}

		bool SpanOfYears::operator <=(const SpanOfYears& element) const
		{
			return (this->yearFrom <= element.yearFrom) || (this->yearFrom == element.yearFrom && (this->yearUpto <= element.yearUpto));
		}

		bool SpanOfYears::operator >=(const SpanOfYears& element) const
		{
			return (this->yearFrom >= element.yearFrom) || (this->yearFrom == element.yearFrom && (this->yearUpto >= element.yearUpto));
		}

		int SpanOfYears::CompareTo(const SpanOfYears& other) const
		{
			if (this->yearFrom != other.yearFrom)
			{
				return  (this->yearFrom - other.yearFrom);
			}
			return  (this->yearUpto - other.yearUpto);
		}

		bool SpanOfYears::isEqualToInterval(const SpanOfYears& other) const
		{
			return (this->yearFrom == other.yearFrom && this->yearUpto == other.yearUpto);
		}

		CString SpanOfYears::ClassName() const
		{
			CString toStringFrom;
			toStringFrom.Format(_T("%d"), yearFrom);
			CString toStringUpto;
			toStringUpto.Format(_T("%d"), yearUpto);

			CString classNameBuilder(toStringFrom);

			if (yearFrom != yearUpto) {
				classNameBuilder += _T("to") + toStringUpto;
			}
			return classNameBuilder;
		}

		CString SpanOfYears::ToString() const
		{
			return this->ClassName();
		}

	}
}
