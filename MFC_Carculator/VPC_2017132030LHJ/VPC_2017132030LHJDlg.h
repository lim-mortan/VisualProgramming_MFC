
// VPC_2017132030LHJDlg.h : header file
//

#pragma once


// CVPC_2017132030LHJDlg dialog
class CVPC_2017132030LHJDlg : public CDialogEx
{
// Construction
public:
	CVPC_2017132030LHJDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VPC_2017132030LHJ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonCalc();
	afx_msg void OnEnChangeEditnum();
	afx_msg void OnEnChangeEditresult();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonClear();
	CString num;
	CString result;
	CString num1, num2;
	double dnum1, dnum2;
	double dresult;
	int p;
	int flag;
};
