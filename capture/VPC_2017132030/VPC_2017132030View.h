
// VPC_2017132030View.h : CVPC_2017134033JUHView 클래스의 인터페이스
//

#pragma once


class CVPC_2017132030View : public CView
{
protected: // serialization에서만 만들어집니다.
	CVPC_2017132030View();
	DECLARE_DYNCREATE(CVPC_2017132030View)

	// 특성입니다.
public:
	CVPC_2017132030Doc* GetDocument() const;

	// 작업입니다.
public:

	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 구현입니다.
public:
	virtual ~CVPC_2017132030View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // VPC_2017134033JUHView.cpp의 디버그 버전
inline CVPC_2017132030Doc* CVPC_2017132030View::GetDocument() const
{
	return reinterpret_cast<CVPC_2017132030Doc*>(m_pDocument);
}
#endif

