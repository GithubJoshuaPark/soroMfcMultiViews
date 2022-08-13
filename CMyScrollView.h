#pragma once

#define CMYSCROLLVIEW 26004

// CMyScrollView view

class CMyScrollView : public CScrollView
{
	DECLARE_DYNCREATE(CMyScrollView)

public:
	CMyScrollView();           // protected constructor used by dynamic creation
	virtual ~CMyScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};


