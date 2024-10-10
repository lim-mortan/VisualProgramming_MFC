// planet_dlg.cpp : implementation file
//

#include "stdafx.h"
#include "2017132030lhj.h"
#include "planet_dlg.h"
#include "afxdialogex.h"
#include "Planet.h"



// planet_dlg dialog

IMPLEMENT_DYNAMIC(planet_dlg, CDialogEx)

planet_dlg::planet_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_dir(0)
	, m_speed(10)
	, m_life(10)
{

}

planet_dlg::~planet_dlg()
{
}

void planet_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DIR, m_dir);
	DDV_MinMaxInt(pDX, m_dir, 0, 1);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_speed);
	DDV_MinMaxInt(pDX, m_speed, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_LIFE, m_life);
	DDV_MinMaxInt(pDX, m_life, 0, 40);
}


BEGIN_MESSAGE_MAP(planet_dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &planet_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// planet_dlg message handlers


void planet_dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
	CDialogEx::OnOK();
}


BOOL planet_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
