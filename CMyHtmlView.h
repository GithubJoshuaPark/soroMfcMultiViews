#pragma once
#include <afxhtml.h>

#define CMYHTMLVIEW 26002

#ifdef _WIN32_WCE
#error "CHtmlView is not supported for Windows CE."
#endif 

// CMyHtmlView html view

class CMyHtmlView : public CHtmlView
{
	DECLARE_DYNCREATE(CMyHtmlView)

public:
	CMyHtmlView();           // protected constructor used by dynamic creation
	virtual ~CMyHtmlView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


