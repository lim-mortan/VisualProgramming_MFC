
// VPC_2017132030.h : VPC_2017132030 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CVPC_2017132030App:
// �� Ŭ������ ������ ���ؼ��� VPC_2017132030.cpp�� �����Ͻʽÿ�.
//

class CVPC_2017132030App : public CWinAppEx
{
public:
	CVPC_2017132030App();


	// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CVPC_2017132030App theApp;
