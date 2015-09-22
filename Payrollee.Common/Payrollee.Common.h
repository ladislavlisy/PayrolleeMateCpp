// Payrolle.Common.h : main header file for the Payrolle.Common DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPayrolleCommonApp
// See Payrolle.Common.cpp for the implementation of this class
//

class CPayrolleCommonApp : public CWinApp
{
public:
	CPayrolleCommonApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
