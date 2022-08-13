
// soroMfcMultiViewsView.h : interface of the CsoroMfcMultiViewsView class
//

#pragma once


class CsoroMfcMultiViewsView : public CView
{
protected: // create from serialization only
	CsoroMfcMultiViewsView() noexcept;
	DECLARE_DYNCREATE(CsoroMfcMultiViewsView)

// Attributes
public:
	CsoroMfcMultiViewsDoc* GetDocument() const;

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
	virtual ~CsoroMfcMultiViewsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in soroMfcMultiViewsView.cpp
inline CsoroMfcMultiViewsDoc* CsoroMfcMultiViewsView::GetDocument() const
   { return reinterpret_cast<CsoroMfcMultiViewsDoc*>(m_pDocument); }
#endif

