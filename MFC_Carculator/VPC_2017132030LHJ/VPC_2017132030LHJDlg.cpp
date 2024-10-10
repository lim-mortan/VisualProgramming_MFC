
// VPC_2017132030LHJDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VPC_2017132030LHJ.h"
#include "VPC_2017132030LHJDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	int a, b;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVPC_2017132030LHJDlg dialog



CVPC_2017132030LHJDlg::CVPC_2017132030LHJDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_VPC_2017132030LHJ_DIALOG, pParent)
	, num(_T(""))
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVPC_2017132030LHJDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_num, num);
	DDX_Text(pDX, IDC_EDIT_result, result);
}

BEGIN_MESSAGE_MAP(CVPC_2017132030LHJDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CVPC_2017132030LHJDlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON15, &CVPC_2017132030LHJDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON3, &CVPC_2017132030LHJDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_CALC, &CVPC_2017132030LHJDlg::OnBnClickedButtonCalc)
	ON_EN_CHANGE(IDC_EDIT_num, &CVPC_2017132030LHJDlg::OnEnChangeEditnum)
	ON_EN_CHANGE(IDC_EDIT_result, &CVPC_2017132030LHJDlg::OnEnChangeEditresult)
	ON_BN_CLICKED(IDC_BUTTON7, &CVPC_2017132030LHJDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CVPC_2017132030LHJDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON0, &CVPC_2017132030LHJDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &CVPC_2017132030LHJDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CVPC_2017132030LHJDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CVPC_2017132030LHJDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CVPC_2017132030LHJDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CVPC_2017132030LHJDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CVPC_2017132030LHJDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CVPC_2017132030LHJDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CVPC_2017132030LHJDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CVPC_2017132030LHJDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CVPC_2017132030LHJDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CVPC_2017132030LHJDlg message handlers

BOOL CVPC_2017132030LHJDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVPC_2017132030LHJDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVPC_2017132030LHJDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVPC_2017132030LHJDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVPC_2017132030LHJDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	num.AppendChar('2');
	UpdateData(FALSE);
}


void CVPC_2017132030LHJDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	num.AppendChar('3');
	UpdateData(FALSE);
}


void CVPC_2017132030LHJDlg::OnBnClickedButtonCalc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (flag == 1) {
		p = num.Find('+');
		num1 = num.Left(p);
		num2 = num.Mid(p + 1);
		dnum1 = _tstof(num1);
		dnum2 = _tstof(num2);
		dresult = dnum1 + dnum2;
		result.Format(_T("%.2f"), dresult);
		UpdateData(FALSE);
	}
	else if (flag == 2) {
		p = num.Find('-');
		num1 = num.Left(p);
		num2 = num.Mid(p + 1);
		dnum1 = _tstof(num1);
		dnum2 = _tstof(num2);
		dresult = dnum1 - dnum2;
		result.Format(_T("%.2f"), dresult);
		UpdateData(FALSE);
	}
	else if (flag == 3) {
		p = num.Find('*');
		num1 = num.Left(p);
		num2 = num.Mid(p + 1);
		dnum1 = _tstof(num1);
		dnum2 = _tstof(num2);
		dresult = dnum1 * dnum2;
		result.Format(_T("%.2f"), dresult);
		UpdateData(FALSE);
	}
	else if (flag == 4) {
		p = num.Find('/');
		num1 = num.Left(p);
		num2 = num.Mid(p + 1);
		dnum1 = _tstof(num1);
		dnum2 = _tstof(num2);
		dresult = dnum1 / dnum2;
		result.Format(_T("%.2f"), dresult);
		UpdateData(FALSE);
	}
}


void CVPC_2017132030LHJDlg::OnEnChangeEditnum()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnEnChangeEditresult()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	num.AppendChar('7');
	UpdateData(FALSE);
}


void CVPC_2017132030LHJDlg::OnBnClickedButton8()
{
	num.AppendChar('8');
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton0()
{
	// TODO: Add your control notification handler code here
	num.AppendChar('0');
	UpdateData(FALSE);
}


void CVPC_2017132030LHJDlg::OnBnClickedButton1()
{
	num.AppendChar('1');
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton4()
{
	num.AppendChar('4');
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton5()
{
	num.AppendChar('5');
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton6()
{
	num.AppendChar('6');
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButton9()
{
	num.AppendChar('9');
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButtonPlus()
{
	num.AppendChar('+');
	UpdateData(FALSE);
	flag = 1;
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButtonMinus()
{
	num.AppendChar('-');
	UpdateData(FALSE);
	flag = 2;
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButtonMultiply()
{
	num.AppendChar('*');
	UpdateData(FALSE);
	flag = 3;
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButtonDivide()
{
	num.AppendChar('/');
	UpdateData(FALSE);
	flag = 4;
	// TODO: Add your control notification handler code here
}


void CVPC_2017132030LHJDlg::OnBnClickedButtonClear()
{
	num = "";
	result = "";
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}
