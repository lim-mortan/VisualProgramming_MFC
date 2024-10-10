#pragma once


// planet_dlg dialog

class planet_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(planet_dlg)

public:
	planet_dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~planet_dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_dir;
	int m_speed;
	int m_life;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
