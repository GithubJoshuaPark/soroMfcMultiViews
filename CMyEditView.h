#pragma once

#define CMYEDITVIEW 26001

// CMyEditView view

class CMyEditView : public CEditView
{
	DECLARE_DYNCREATE(CMyEditView)

public:
	CMyEditView();           // protected constructor used by dynamic creation
	virtual ~CMyEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void PostNcDestroy();
};


