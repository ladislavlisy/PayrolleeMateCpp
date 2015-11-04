#pragma once

#include <string>
#include <sstream>
#include <iostream>

namespace Payrollee
{
	namespace Common
	{
		class SymbolName
		{
		public:
			SymbolName(unsigned int code, const std::string& name);
			SymbolName(const SymbolName& element);
			~SymbolName();
		private:
			unsigned int code;
			std::string name;
		public:
			unsigned int Code() const { return code; }
			const std::string& Name() const { return name; }

			int CompareTo(const SymbolName& other) const;

			const SymbolName& operator=(const SymbolName& element);

			bool operator==(const SymbolName& other) const;
			bool operator!=(const SymbolName& other) const;
			bool operator<(const SymbolName& other) const;
			bool operator>(const SymbolName& other) const;
			bool operator<=(const SymbolName& other) const;
			bool operator>=(const SymbolName& other) const;

			CString Description() const;

			CString ToString() const;

			friend std::wstringstream &operator<<(std::wstringstream &output, const SymbolName &element)
			{
				output << _T("Code : ") << element.code << _T(" Description : ") << element.Description();
				return output;
			}
		};
	}
}
