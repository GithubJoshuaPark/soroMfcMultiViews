
// MainFrm.h : interface of the CMainFrame class
//

#pragma once
#include "CMyHtmlView.h"
#include "CMyEditView.h"
#include "CMyListview.h"
#include "CMyListviewForMenu.h"

#define VIEWID_DEFAULT AFX_IDW_PANE_FIRST
#define VIEWID_HTML    AFX_IDW_PANE_FIRST + 10
#define VIEWID_EDIT    AFX_IDW_PANE_FIRST + 20
#define VIEWID_LIST    AFX_IDW_PANE_FIRST + 30

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CMyHtmlView* m_pwndHtmlView;
	CMyEditView* m_pwndEditView;
	CMyListView* m_pwndListView;
	CMyListViewForMenu* m_pwndListViewForMenu;

// Operations
public:


// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	

protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	void SwitchView(int nId);
	afx_msg void OnHelpEditview();
	afx_msg void OnHelpHtmlview();
	afx_msg void OnHelpListview();
};


