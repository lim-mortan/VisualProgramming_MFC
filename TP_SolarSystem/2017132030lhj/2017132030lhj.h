
// 2017132030lhj.h : main header file for the 2017132030lhj application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy2017132030lhjApp:
// See 2017132030lhj.cpp for the implementation of this class
//

class CMy2017132030lhjApp : public CWinApp
{
public:
	CMy2017132030lhjApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2017132030lhjApp theApp;
