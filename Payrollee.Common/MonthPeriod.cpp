#include "stdafx.h"
#include "MonthPeriod.h"

namespace Payrollee
{
	namespace Common
	{
		MonthPeriod::MonthPeriod(unsigned int code)
		{
			this->code = code;
		}

		MonthPeriod::MonthPeriod(const MonthPeriod& element)
		{
			this->code = element.Code();
		}


		MonthPeriod::~MonthPeriod(void)
		{
		}

		MonthPeriod MonthPeriod::Empty()
		{
			return MonthPeriod(MonthPeriod::PRESENT);
		}

		MonthPeriod MonthPeriod::BeginYear(unsigned int year)
		{
			return MonthPeriod(year*100 + 1);
		}

		MonthPeriod MonthPeriod::EndYear(unsigned int year)
		{
			return MonthPeriod(year*100 + 12);
		}

		COleDateTime MonthPeriod::BeginOfMonth() const {
			return COleDateTime(YearInt(), MonthInt(), 1, 0, 0, 0);
		}

		COleDateTime MonthPeriod::EndOfMonth() const {
			return COleDateTime(YearInt(), MonthInt(), DaysInMonth(), 0, 0, 0);
		}

		COleDateTime MonthPeriod::DateOfMonth(int dayOrdinal) const {
			int periodDay = __min(__max(1, dayOrdinal), DaysInMonth());
			return COleDateTime(YearInt(), MonthInt(), periodDay, 0, 0, 0);
		}

		int MonthPeriod::WeekDayOfMonth(int dayOrdinal) const {
			COleDateTime periodDate = DateOfMonth(dayOrdinal);
			return DayOfWeekMonToSun(periodDate);
		}

		int MonthPeriod::DayOfWeekMonToSun(const COleDateTime periodDate) const {
			int periodDateCwd = periodDate.GetDayOfWeek();
			// GetDayOfWeek Sunday = 1
			// Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7
			return (periodDateCwd == 1) ? 7 : (periodDateCwd - 1);
		}

		CString MonthPeriod::Description() const {
			COleDateTime firstPeriodDate = BeginOfMonth();
			return firstPeriodDate.Format(_T("%B %Y"));
		}

		const MonthPeriod& MonthPeriod::operator=(const MonthPeriod& element)
		{
			this->code = element.Code();
			return *this;
		}

		bool MonthPeriod::isEqualToPeriod(const MonthPeriod& other) const {
			return (code == other.code);
		}

		int MonthPeriod::CompareTo(const MonthPeriod& other) const {
			return (this->code - other.code);
		}

		bool MonthPeriod::operator==(const MonthPeriod& other) const {
			return (isEqualToPeriod(other));
		}

		bool MonthPeriod::operator!=(const MonthPeriod& other) const {
			return (!isEqualToPeriod(other));
		}

		bool MonthPeriod::operator<(const MonthPeriod& other) const {
			return (code < other.code);
		}

		bool MonthPeriod::operator>(const MonthPeriod& other) const {
			return (code > other.code);
		}

		bool MonthPeriod::operator<=(const MonthPeriod& other) const {
			return (code <= other.code);
		}

		bool MonthPeriod::operator>=(const MonthPeriod& other) const {
			return (code >= other.code);
		}

		CString MonthPeriod::ToString() const {
			CString toString;
			toString.Format(_T("%d"), code);
			return toString;
		}
	}
}
