
// VPC_2017132030View.h : CVPC_2017134033JUHView Ŭ������ �������̽�
//

#pragma once


class CVPC_2017132030View : public CView
{
protected: // serialization������ ��������ϴ�.
	CVPC_2017132030View();
	DECLARE_DYNCREATE(CVPC_2017132030View)

	// Ư���Դϴ�.
public:
	CVPC_2017132030Doc* GetDocument() const;

	// �۾��Դϴ�.
public:

	// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// �����Դϴ�.
public:
	virtual ~CVPC_2017132030View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint p1, p2, d1, d2;
	CRect rect1, rect2, rect3, rect4;
	int capture = 0;
};

#ifndef _DEBUG  // VPC_2017134033JUHView.cpp�� ����� ����
inline CVPC_2017132030Doc* CVPC_2017132030View::GetDocument() const
{
	return reinterpret_cast<CVPC_2017132030Doc*>(m_pDocument);
}
#endif

