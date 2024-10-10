
// 2017132030lhjView.h : interface of the CMy2017132030lhjView class
//

#pragma once
#include "Planet.h"

class CMy2017132030lhjView : public CView
{
protected: // create from serialization only
	CMy2017132030lhjView();
	DECLARE_DYNCREATE(CMy2017132030lhjView)

// Attributes
public:
	CMy2017132030lhjDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy2017132030lhjView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	Planet m_mercury;
	Planet m_venus;
	Planet m_earth;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSimulationStart();
	afx_msg void OnSimulationStop();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPlanetAdd();
	Planet m_mars;
	int m_flag;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 2017132030lhjView.cpp
inline CMy2017132030lhjDoc* CMy2017132030lhjView::GetDocument() const
   { return reinterpret_cast<CMy2017132030lhjDoc*>(m_pDocument); }
#endif

