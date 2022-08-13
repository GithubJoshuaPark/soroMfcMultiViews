#pragma once
#include "CMyListView.h"

#define CMYLISTVIEWFORMENU 26101

// CMyListViewForMenu view

class CMyListViewForMenu : public CView
{
	DECLARE_DYNCREATE(CMyListViewForMenu)

public:
	CMyListViewForMenu();           // protected constructor used by dynamic creation
	virtual ~CMyListViewForMenu();

	virtual void OnDraw(CDC* pDC);      // overridden to draw this view

	CMyListView m_wndCMyListview;

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
};


