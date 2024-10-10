
// 2017132030lhjView.cpp : implementation of the CMy2017132030lhjView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "2017132030lhj.h"
#endif

#include "2017132030lhjDoc.h"
#include "2017132030lhjView.h"
#include "planet_dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2017132030lhjView

IMPLEMENT_DYNCREATE(CMy2017132030lhjView, CView)

BEGIN_MESSAGE_MAP(CMy2017132030lhjView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_COMMAND(ID_SIMULATION_START, &CMy2017132030lhjView::OnSimulationStart)
	ON_COMMAND(ID_SIMULATION_STOP, &CMy2017132030lhjView::OnSimulationStop)
	ON_WM_CREATE()
	ON_COMMAND(ID_PLANET_ADD, &CMy2017132030lhjView::OnPlanetAdd)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy2017132030lhjView construction/destruction

CMy2017132030lhjView::CMy2017132030lhjView()
	: m_flag(0)
{
	// TODO: add construction code here

}

CMy2017132030lhjView::~CMy2017132030lhjView()
{
}

BOOL CMy2017132030lhjView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy2017132030lhjView drawing

void CMy2017132030lhjView::OnDraw(CDC* pDC)
{
	CMy2017132030lhjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//////////////////////////////////////////////////////////// First orbit
	CRect rect;
	GetClientRect(&rect);
	const int centerX = rect.Width() / 2;
	const int centerY = rect.Height() / 2;
	
	if (m_mars.life != 0) {
		int radius = 300;
		pDC->Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	}
	if (m_earth.life != 0) {
		int radius = 220;
		pDC->Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	}

	if (m_venus.life != 0) {
		int radius = 150;
		pDC->Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	}
	if (m_mercury.life != 0) {
		int radius = 100;
		pDC->Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	}
	

	// TODO: add draw code for native data here
	////////////////////////////////////////////////////////////sun
	
	int radius = 30;
	CBrush solidBrush;
	CBrush* pOldBrush;

	solidBrush.CreateSolidBrush(RGB(255, 0, 0));
	pOldBrush = pDC->SelectObject(&solidBrush);
	pDC->Ellipse(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	pDC->SelectObject(pOldBrush);

	////////////////////////////////////////////////////////////mercury


	//solidBrush.CreateSolidBrush(RGB(255, 0, 255));
	//pOldBrush = pDC->SelectObject(&solidBrush);
	if (m_mercury.life != 0) {
		pDC->Ellipse(centerX + (100 * cos(m_mercury.angle*(3.14 / 180))) - m_mercury.radius, centerY + (100 * sin(m_mercury.angle*(3.14 / 180))) - m_mercury.radius, centerX + (100 * cos(m_mercury.angle*(3.14 / 180))) + m_mercury.radius, centerY + (100 * sin(m_mercury.angle*(3.14 / 180))) + m_mercury.radius);
	}
	//pDC->SelectObject(pOldBrush);
	if (m_venus.life != 0) {
		////////////////////////////////////////////////////////////venus
		pDC->Ellipse(centerX + (150 * cos(m_venus.angle*(3.14 / 180))) - m_venus.radius, centerY + (150 * sin(m_venus.angle*(3.14 / 180))) - m_venus.radius, centerX + (150 * cos(m_venus.angle*(3.14 / 180))) + m_venus.radius, centerY + (150 * sin(m_venus.angle*(3.14 / 180))) + m_venus.radius);
	}
	if (m_earth.life != 0) {
		////////////////////////////////////////////////////////////earth
		pDC->Ellipse(centerX + (220 * cos(m_earth.angle*(3.14 / 180))) - m_earth.radius, centerY + (220 * sin(m_earth.angle*(3.14 / 180))) - m_earth.radius, centerX + (220 * cos(m_earth.angle*(3.14 / 180))) + m_earth.radius, centerY + (220 * sin(m_earth.angle*(3.14 / 180))) + m_earth.radius);
	}
	if (m_mars.life != 0) {
		////////////////////////////////////////////////////////////mars
		pDC->Ellipse(centerX + (300 * cos(m_mars.angle*(3.14 / 180))) - m_mars.radius, centerY + (300 * sin(m_mars.angle*(3.14 / 180))) - m_mars.radius, centerX + (300 * cos(m_mars.angle*(3.14 / 180))) + m_mars.radius, centerY + (300 * sin(m_mars.angle*(3.14 / 180))) + m_mars.radius);
	}
}


// CMy2017132030lhjView printing

BOOL CMy2017132030lhjView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy2017132030lhjView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy2017132030lhjView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy2017132030lhjView diagnostics

#ifdef _DEBUG
void CMy2017132030lhjView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2017132030lhjView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2017132030lhjDoc* CMy2017132030lhjView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2017132030lhjDoc)));
	return (CMy2017132030lhjDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2017132030lhjView message handlers


void CMy2017132030lhjView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1) {
		if (m_flag == 20) {
			OnSimulationStop();
		}
		m_venus.angle += m_venus.speed;
		m_mercury.angle += m_mercury.speed;
		m_earth.angle += m_earth.speed;
		m_mars.angle += m_mars.speed;
		if (m_mars.life > 0) {
			m_mars.life--;
		}

		if (m_venus.life > 0) {
			m_venus.life--;
		}
		
		if (m_mercury.life > 0) {
			m_mercury.life--;
		}
		if (m_earth.life > 0) {
			m_earth.life--;
		}
		/*m_mars.life--;
		m_venus.life--;
		m_mercury.life--;
		m_earth.life--;*/
		Invalidate();
		m_flag++;
	}

	CView::OnTimer(nIDEvent);
}


void CMy2017132030lhjView::OnSimulationStart()
{
	// TODO: Add your command handler code here
	SetTimer(1, 1000, NULL);
	m_flag = 0;

}


void CMy2017132030lhjView::OnSimulationStop()
{

	// TODO: Add your command handler code here
	KillTimer(1);
	Invalidate();
	m_mercury.angle = 0;
	m_venus.angle = 0;
	m_earth.angle = 0;
	m_mars.angle = 0;
	CString str;
	str.AppendFormat(_T("%s,%d,%d,%d,%d\n"), m_mercury.name, m_mercury.radius, m_mercury.direction, m_mercury.position, m_mercury.life, m_mercury.direction, m_mercury.position, m_mercury.speed);
	str.AppendFormat(_T("%s,%d,%d,%d,%d\n"), m_venus.name, m_venus.radius, m_venus.direction, m_venus.position, m_venus.life, m_venus.direction, m_venus.position, m_venus.speed);
	str.AppendFormat(_T("%s,%d,%d,%d,%d\n"), m_earth.name, m_earth.radius, m_earth.direction, m_earth.position, m_earth.life, m_earth.direction, m_earth.position, m_earth.speed);
	str.AppendFormat(_T("%s,%d,%d,%d,%d\n"), m_mars.name, m_mars.radius, m_mars.direction, m_mars.position, m_mars.life, m_mars.direction, m_mars.position, m_mars.speed);
	
	//str.Append(_T("the End"));
	AfxMessageBox(str);
}


int CMy2017132030lhjView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_mercury = Planet(_T("mercury"), 15, 0, 0, 30, 6, 0);
	m_venus = Planet(_T("venus"), 20, 0, 0, 30, 9, 0);
	m_earth = Planet(_T("earth"), 30, 0, 0, 25, 10, 0);

	return 0;
}


void CMy2017132030lhjView::OnPlanetAdd()
{
	planet_dlg dlg;
	int res = dlg.DoModal();

	if (res == IDOK) {
		m_mars = Planet(_T("mars"), 30, dlg.m_dir, 0, dlg.m_life, dlg.m_speed, 0);
		Invalidate();
	}

	// TODO: Add your command handler code here
}


void CMy2017132030lhjView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if ((::GetKeyState(VK_CONTROL)<0) && nChar == 0x58) {
		OnSimulationStop();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
