// CMyListViewForMenu.cpp : implementation file
//

#include "pch.h"
#include "soroMfcMultiViews.h"
#include "CMyListViewForMenu.h"


// CMyListViewForMenu

IMPLEMENT_DYNCREATE(CMyListViewForMenu, CView)

CMyListViewForMenu::CMyListViewForMenu()
{

}

CMyListViewForMenu::~CMyListViewForMenu()
{
}

BEGIN_MESSAGE_MAP(CMyListViewForMenu, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMyListViewForMenu drawing

void CMyListViewForMenu::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CMyListViewForMenu diagnostics

#ifdef _DEBUG
void CMyListViewForMenu::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyListViewForMenu::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyListViewForMenu message handlers


int CMyListViewForMenu::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect cRect;
	GetClientRect(&cRect);
	m_wndCMyListview.Create(WS_CHILD | WS_VISIBLE, cRect, this, CMYLISTVIEWFORMENU);
	return 0;
}


void CMyListViewForMenu::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_wndCMyListview.MoveWindow(0, 0, cx, cy);
}


void CMyListViewForMenu::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}
