
// VPC_2017132030LHJ.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CVPC_2017132030LHJApp:
// See VPC_2017132030LHJ.cpp for the implementation of this class
//

class CVPC_2017132030LHJApp : public CWinApp
{
public:
	CVPC_2017132030LHJApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CVPC_2017132030LHJApp theApp;