
// soroMfcMultiViewsView.cpp : implementation of the CsoroMfcMultiViewsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "soroMfcMultiViews.h"
#endif

#include "soroMfcMultiViewsDoc.h"
#include "soroMfcMultiViewsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsoroMfcMultiViewsView

IMPLEMENT_DYNCREATE(CsoroMfcMultiViewsView, CView)

BEGIN_MESSAGE_MAP(CsoroMfcMultiViewsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CsoroMfcMultiViewsView construction/destruction

CsoroMfcMultiViewsView::CsoroMfcMultiViewsView() noexcept
{
	// TODO: add construction code here

}

CsoroMfcMultiViewsView::~CsoroMfcMultiViewsView()
{
}

BOOL CsoroMfcMultiViewsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsoroMfcMultiViewsView drawing

void CsoroMfcMultiViewsView::OnDraw(CDC* /*pDC*/)
{
	CsoroMfcMultiViewsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsoroMfcMultiViewsView printing

BOOL CsoroMfcMultiViewsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsoroMfcMultiViewsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsoroMfcMultiViewsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CsoroMfcMultiViewsView diagnostics

#ifdef _DEBUG
void CsoroMfcMultiViewsView::AssertValid() const
{
	CView::AssertValid();
}

void CsoroMfcMultiViewsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsoroMfcMultiViewsDoc* CsoroMfcMultiViewsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsoroMfcMultiViewsDoc)));
	return (CsoroMfcMultiViewsDoc*)m_pDocument;
}
#endif //_DEBUG


// CsoroMfcMultiViewsView message handlers
