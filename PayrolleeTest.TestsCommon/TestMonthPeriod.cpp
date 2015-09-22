#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Payrollee.Common\MonthPeriod.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Payrollee::Common;

namespace Microsoft{
    namespace VisualStudio {
        namespace CppUnitTestFramework {

            template<>
            static std::wstring ToString<MonthPeriod>(const MonthPeriod  & element) {
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
			TEST_CLASS(MonthPeriodTest)
			{
			private:
				unsigned int testPeriodCodeJan;
				unsigned int testPeriodCodeFeb;
				unsigned int testPeriodCode501;
				unsigned int testPeriodCode402;
			public:		
				MonthPeriodTest() 
				{
					testPeriodCodeJan = 201401;
					testPeriodCodeFeb = 201402;
					testPeriodCode501 = 201501;
					testPeriodCode402 = 201402;
				}
				TEST_METHOD(Should_Compare_Different_Periods_AsEqual_When_2014_01)
				{
					MonthPeriod testPeriodOne(testPeriodCodeJan);
					MonthPeriod testPeriodTwo(testPeriodCodeJan);

					Assert::AreEqual(testPeriodOne, testPeriodTwo);
				}

				TEST_METHOD(Should_Compare_Different_Periods_AsEqual_When_2014_02)
				{
					MonthPeriod testPeriodOne(testPeriodCodeFeb);
					MonthPeriod testPeriodTwo(testPeriodCodeFeb);

					Assert::AreEqual(testPeriodOne, testPeriodTwo);
				}

				TEST_METHOD(Should_Compare_Different_Periods_SameYear_AsGreater)
				{
					MonthPeriod testPeriodOne(testPeriodCodeJan);
					MonthPeriod testPeriodTwo(testPeriodCodeFeb);

					Assert::AreNotEqual(testPeriodOne, testPeriodTwo);
					Assert::IsTrue(testPeriodTwo > testPeriodOne);
				}

				TEST_METHOD(Should_Compare_Different_Periods_SameYear_AsLess)
				{
					MonthPeriod testPeriodOne(testPeriodCodeJan);
					MonthPeriod testPeriodTwo(testPeriodCodeFeb);

					Assert::AreNotEqual(testPeriodOne, testPeriodTwo);
					Assert::IsTrue(testPeriodOne < testPeriodTwo);
				}

				TEST_METHOD(Should_Compare_Different_Periods_SameMonth_AsGreater)
				{
					MonthPeriod testPeriodOne(testPeriodCodeJan);
					MonthPeriod testPeriodTwo(testPeriodCode501);

					Assert::AreNotEqual(testPeriodOne, testPeriodTwo);
					Assert::IsTrue(testPeriodTwo > testPeriodOne);
				}

				TEST_METHOD(Should_Compare_Different_Periods_SameMonth_AsLess)
				{
					MonthPeriod testPeriodOne(testPeriodCodeJan);
					MonthPeriod testPeriodTwo(testPeriodCode501);

					Assert::AreNotEqual(testPeriodOne, testPeriodTwo);
					Assert::IsTrue(testPeriodOne < testPeriodTwo);
				}

				TEST_METHOD(Should_Compare_Different_Periods_DifferentYear_AsGreater)
				{
					MonthPeriod testPeriodOne(testPeriodCode402);
					MonthPeriod testPeriodTwo(testPeriodCode501);

					Assert::AreNotEqual(testPeriodOne, testPeriodTwo);
					Assert::IsTrue(testPeriodTwo > testPeriodOne);
				}

				TEST_METHOD(Should_Compare_Different_Periods_DifferentYear_AsLess)
				{
					MonthPeriod testPeriodOne(testPeriodCode402);
					MonthPeriod testPeriodTwo(testPeriodCode501);

					Assert::AreNotEqual(testPeriodOne, testPeriodTwo);
					Assert::IsTrue(testPeriodOne < testPeriodTwo);
				}

				TEST_METHOD(Should_Return_Periods_Year_And_Month_2014_01)
				{
					MonthPeriod testPeriodOne(testPeriodCodeJan);

					Assert::AreEqual(2014u, testPeriodOne.Year()    );
					Assert::AreEqual(   1u, testPeriodOne.Month()   );
					Assert::AreEqual( 2014, testPeriodOne.YearInt() );
					Assert::AreEqual(    1, testPeriodOne.MonthInt());
				}

				TEST_METHOD(Should_Return_Periods_Year_And_Month_2014_02)
				{
					MonthPeriod testPeriodOne(testPeriodCodeFeb);

					Assert::AreEqual(2014u, testPeriodOne.Year()    );
					Assert::AreEqual(   2u, testPeriodOne.Month()   );
					Assert::AreEqual( 2014, testPeriodOne.YearInt() );
					Assert::AreEqual(    2, testPeriodOne.MonthInt());
				}

				TEST_METHOD(Should_Return_Periods_Month_And_Year_Description)
				{
					MonthPeriod testPeriodJan(testPeriodCodeJan);
					MonthPeriod testPeriodFeb(testPeriodCodeFeb);
					MonthPeriod testPeriod501(testPeriodCode501);
					MonthPeriod testPeriod402(testPeriodCode402);

					Assert::AreEqual(_T("January 2014") ,testPeriodJan.Description());
					Assert::AreEqual(_T("February 2014"),testPeriodFeb.Description());
					Assert::AreEqual(_T("January 2015") ,testPeriod501.Description());
					Assert::AreEqual(_T("February 2014"),testPeriod402.Description());
				}
			};
		}
	}
}