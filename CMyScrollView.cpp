// CMyScrollView.cpp : implementation file
//

#include "pch.h"
#include "soroMfcMultiViews.h"
#include "CMyScrollView.h"
#include <atlimage.h>

// CMyScrollView

IMPLEMENT_DYNCREATE(CMyScrollView, CScrollView)

CMyScrollView::CMyScrollView()
{

}

CMyScrollView::~CMyScrollView()
{
}


BEGIN_MESSAGE_MAP(CMyScrollView, CScrollView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMyScrollView drawing

void CMyScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view

	sizeTotal.cx = 6000;
	sizeTotal.cy = 4000;

	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CMyScrollView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CMyScrollView diagnostics

#ifdef _DEBUG
void CMyScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyScrollView message handlers


int CMyScrollView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	return 0;
}


void CMyScrollView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here	CRect cRect;
	CString ls_str;
	ls_str.Format(_T("¡Ù¡Ú¡Ø CMyScrollView::OnSize width: [%d], height: [%d] ¡Ù¡Ú¡Ø\n"), cx, cy);
	OutputDebugStringW(ls_str);
}


void CMyScrollView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CScrollView::OnPaint() for painting messages

	CRect cRect;
	GetClientRect(&cRect);

	CString ls_str;
	ls_str.Format(_T("¡Ù¡Ú¡Ø CMyScrollView::OnPaint width: [%d], height: [%d] ¡Ù¡Ú¡Ø\n"), cRect.Width(), cRect.Height());
	OutputDebugStringW(ls_str);

	int nVertScroll = GetScrollPos(SB_VERT);
	int nHorzScroll = GetScrollPos(SB_HORZ);

	CImage cImage;
	cImage.LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP2);  // 6000*4000
	cImage.BitBlt(dc.m_hDC, -nHorzScroll, -nVertScroll);
}
