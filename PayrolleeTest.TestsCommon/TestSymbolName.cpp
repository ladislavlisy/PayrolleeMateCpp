#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Payrollee.Common\SymbolName.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Payrollee::Common;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {

			template<>
			static std::wstring ToString<SymbolName>(const SymbolName  & element) {
				std::wstringstream _s;
				_s << element;
				return _s.str();
			}

		}
	}
}

namespace PayrolleeTests {
	namespace Common {
		namespace Core {
			TEST_CLASS(MonthPeriodTest)
			{
			private:
				unsigned int testSymbolCode1001;
				unsigned int testSymbolCode2001;
				unsigned int testSymbolCode3001;
				unsigned int testSymbolCode4001;
				unsigned int testSymbolCode5001;
			public:
				MonthPeriodTest()
				{
					testSymbolCode1001 = 1001;
					testSymbolCode2001 = 2001;
					testSymbolCode3001 = 3001;
					testSymbolCode4001 = 4001;
					testSymbolCode5001 = 5001;
				}
				TEST_METHOD(Should_Compare_Different_Symbols_AsEqual)
				{
					SymbolName testSymbolOne(testSymbolCode1001, "Begining Symbol");
					SymbolName testSymbolTwo(testSymbolCode1001, "Terminal Symbol");

					Assert::AreEqual(testSymbolOne, testSymbolTwo);
				}

				TEST_METHOD(Should_Compare_Different_Symbols_AsGreater)
				{
					SymbolName testSymbolOne(testSymbolCode1001, "Begining Symbol");
					SymbolName testSymbolTwo(testSymbolCode5001, "Terminal Symbol");

					Assert::AreNotEqual(testSymbolOne, testSymbolTwo);
					Assert::IsTrue(testSymbolTwo > testSymbolOne);
				}

				TEST_METHOD(Should_Compare_Different_Symbols_AsLess)
				{
					SymbolName testSymbolOne(testSymbolCode1001, "Begining Symbol");
					SymbolName testSymbolTwo(testSymbolCode5001, "Terminal Symbol");

					Assert::AreNotEqual(testSymbolOne, testSymbolTwo);
					Assert::IsTrue(testSymbolOne < testSymbolTwo);
				}
			};
		}
	}
}