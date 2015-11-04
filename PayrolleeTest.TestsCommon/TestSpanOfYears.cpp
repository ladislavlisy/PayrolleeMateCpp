#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Payrollee.Common\SpanOfYears.h"
#include "..\Payrollee.Common\SeqOfYears.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Payrollee::Common;

namespace Microsoft{
    namespace VisualStudio {
        namespace CppUnitTestFramework {

            template<>
            static std::wstring ToString<SeqOfYears>(const SeqOfYears & element) {
                std::wstringstream _s;	
				_s << element; 
				return _s.str();
            }

            template<>
            static std::wstring ToString<CString>(const CString & element) {
                std::wstringstream _s;	
				_s << element; 
				return _s.str();
            }

        }
    }
}

namespace PayrolleeTests {		
	namespace Common {		
		namespace Periods {		
			TEST_CLASS(TestSpanOfYears)
			{
			public:		
				TEST_METHOD(Should_Return_IntervalName_2013)
				{
					SpanOfYears testInterval(2013, 2013);
					CString testName = testInterval.ClassName ();
					Assert::AreEqual (_T("2013"), testName);
				}

				TEST_METHOD(Should_Return_IntervalName_2011to2013)
				{
					SpanOfYears testInterval(2011, 2013);
					CString testName = testInterval.ClassName ();
					Assert::AreEqual (_T("2011to2013"), testName);
				}

				TEST_METHOD(Should_Return_IntervalArray_2011_2015)
				{
					unsigned int testYears[] = {2011,2012,2014,2016,2017,0};

					std::vector<unsigned int> testVector(testYears, testYears + _countof(testYears));

					SeqOfYears testResultSpan(testVector);

					SpanOfYears testExpect[] = {
						SpanOfYears(2011, 2011),
						SpanOfYears(2012, 2013),
						SpanOfYears(2014, 2015),
						SpanOfYears(2016, 2016),
						SpanOfYears(2017, 2099)};

					V_SPAN_OFYEARS resExpectVect(testExpect, testExpect + _countof(testExpect));

					V_SPAN_OFYEARS resResultVect;
					testResultSpan.YearsIntervalList(resResultVect);

					Assert::AreEqual (resResultVect.begin()->ToString(), resExpectVect.begin()->ToString());
					Assert::AreEqual (resResultVect.back().ToString(), resExpectVect.back().ToString());
				}

				TEST_METHOD(Should_Return_Interval_2011_For_Period_2011)
				{
					unsigned int testYears[] = { 2011,2012,2014,2016,2017,0 };

					std::vector<unsigned int> testVector(testYears, testYears + _countof(testYears));

					SeqOfYears testResultSpan(testVector);

					MonthPeriod testPeriod(201101);
					SpanOfYears expInterval(2011, 2011);
					SpanOfYears testInterval = testResultSpan.SpanForPeriod (testPeriod);
					Assert::AreEqual (expInterval.ToString(), testInterval.ToString());
				}

				TEST_METHOD(Should_Return_Interval_2016_For_Period_2016)
				{
					unsigned int testYears[] = { 2011,2012,2014,2016,2017,0 };

					std::vector<unsigned int> testVector(testYears, testYears + _countof(testYears));

					SeqOfYears testResultSpan(testVector);

					MonthPeriod testPeriod(201601);
					SpanOfYears expInterval(2016, 2016);
					SpanOfYears testInterval = testResultSpan.SpanForPeriod (testPeriod);
					Assert::AreEqual (expInterval.ToString(), testInterval.ToString());
				}

				TEST_METHOD(Should_Return_Interval_2012to2013_For_Period_2013)
				{
					unsigned int testYears[] = { 2011,2012,2014,2016,2017,0 };

					std::vector<unsigned int> testVector(testYears, testYears + _countof(testYears));

					SeqOfYears testResultSpan(testVector);

					MonthPeriod testPeriod(201301);
					SpanOfYears expInterval(2012, 2013);
					SpanOfYears testInterval = testResultSpan.SpanForPeriod (testPeriod);
					Assert::AreEqual (expInterval.ToString(), testInterval.ToString());
				}

				TEST_METHOD(Should_Return_Interval_2017to2099_For_Period_2018)
				{
					unsigned int testYears[] = { 2011,2012,2014,2016,2017,0 };

					std::vector<unsigned int> testVector(testYears, testYears + _countof(testYears));

					SeqOfYears testResultSpan(testVector);

					MonthPeriod testPeriod(201801);
					SpanOfYears expInterval(2017, 2099);
					SpanOfYears testInterval = testResultSpan.SpanForPeriod (testPeriod);
					Assert::AreEqual (expInterval.ToString(), testInterval.ToString());
				}
			};
		}
	}
}

