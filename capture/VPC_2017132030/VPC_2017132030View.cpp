
// VPC_2017132030View.cpp : CVPC_2017132030View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "VPC_2017132030.h"
#endif

#include "VPC_2017132030Doc.h"
#include "VPC_2017132030View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVPC_2017134033JUHView

IMPLEMENT_DYNCREATE(CVPC_2017132030View, CView)

BEGIN_MESSAGE_MAP(CVPC_2017132030View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CVPC_2017134033JUHView ����/�Ҹ�

CVPC_2017132030View::CVPC_2017132030View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CVPC_2017132030View::~CVPC_2017132030View()
{
}

BOOL CVPC_2017132030View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CVPC_2017132030View �׸���

void CVPC_2017132030View::OnDraw(CDC* pDC)
{
	CVPC_2017132030Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CDC memdc;
	memdc.CreateCompatibleDC(pDC);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP2);

	BITMAP bm;
	bitmap.GetBitmap(&bm);
	memdc.SelectObject(&bitmap);


	GetClientRect(&rect1);
	rect2.bottom = (9 * rect1.bottom) / 10;
	rect2.top = (rect1.bottom * 3.5) / 6;
	rect2.left = rect1.right / 20;
	rect2.right = (rect1.right * 19) / 20;

	rect3.left = rect1.right / 3;
	rect3.right = rect1.right * 2 / 3;
	rect3.top = 20;
	rect3.bottom = 20 + rect1.bottom / 2;

	CPen blueinside(PS_INSIDEFRAME, 5, RGB(0, 0, 255));
	pDC->SelectObject(&blueinside);
	pDC->Rectangle(&rect2);

	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOutW((rect2.left + rect2.right) / 2, rect2.top + 10, _T("Wednesday Visual C++ MFC Class"));
	pDC->SetTextAlign(TA_LEFT);
	pDC->TextOutW(rect2.left + 80, rect2.top + 40, _T("Department:Mechatronics"));
	pDC->TextOutW(rect2.left + 80, rect2.top + 70, _T("Studentnum:2017132030"));
	pDC->TextOutW(rect2.left + 80, rect2.top + 100, _T("Name:Lim Hyeon Jong"));
	pDC->SetTextAlign(TA_RIGHT);
	pDC->TextOutW(rect2.right - 15, rect2.bottom - 40, _T("������:2022.05.05"));



	if (capture == 0) {
		pDC->StretchBlt(rect3.left, rect3.top, rect3.Width(), rect3.Height(), &memdc, 0, 0,
			bm.bmWidth, bm.bmHeight, SRCCOPY);
	}



	if (capture == 1) {
		CRect rect4(p1.x, p1.y, p2.x, p2.y);
		pDC->StretchBlt(p1.x, p1.y, p2.x - p1.x, p2.y - p1.y, &memdc,
			(p1.x - rect3.left)*bm.bmWidth / rect3.Width(),
			(p1.y - rect3.top)*bm.bmHeight / rect3.Height(),
			rect4.Width()*bm.bmWidth / rect3.Width(),
			rect4.Height()*bm.bmHeight / rect3.Height(), SRCCOPY);
	}
	blueinside.DeleteObject();
	bitmap.DeleteObject();
}


// CVPC_2017132030View �μ�

BOOL CVPC_2017132030View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CVPC_2017132030View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CVPC_2017132030View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CVPC_2017132030View ����

#ifdef _DEBUG
void CVPC_2017132030View::AssertValid() const
{
	CView::AssertValid();
}

void CVPC_2017132030View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVPC_2017132030Doc* CVPC_2017132030View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVPC_2017132030Doc)));
	return (CVPC_2017132030Doc*)m_pDocument;
}
#endif //_DEBUG


// CVPC_2017132030View �޽��� ó����




void CVPC_2017132030View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	SetCapture();
	p1 = p2 = point;
	CView::OnLButtonDown(nFlags, point);
	CView::OnLButtonDown(nFlags, point);
}


void CVPC_2017132030View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nFlags & MK_LBUTTON) {
		CClientDC dc(this);
		dc.SetROP2(R2_NOT);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
		dc.Rectangle(p1.x, p1.y, point.x, point.y);
		p2 = point;
	}
	CView::OnMouseMove(nFlags, point);
}


void CVPC_2017132030View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	capture = 1;
	ReleaseCapture();
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CVPC_2017132030View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_ESCAPE)
	{
		capture = 0;
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}