
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "soroMfcMultiViews.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_HELP_EDITVIEW, &CMainFrame::OnHelpEditview)
	ON_COMMAND(ID_HELP_HTMLVIEW, &CMainFrame::OnHelpHtmlview)
	ON_COMMAND(ID_HELP_LISTVIEW, &CMainFrame::OnHelpListview)
	ON_COMMAND(ID_HELP_SCRLVIEW, &CMainFrame::OnHelpScrlview)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	m_pwndHtmlView = new CMyHtmlView;
	m_pwndEditView = new CMyEditView;
	m_pwndListViewForMenu = new CMyListViewForMenu;
	m_pwndScrollView = new CMyScrollView;

	m_pwndHtmlView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE,
		CFrameWnd::rectDefault, this, VIEWID_HTML, pContext);

	m_pwndEditView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE,
		CFrameWnd::rectDefault, this, VIEWID_EDIT, pContext);

	m_pwndListViewForMenu->Create(NULL, NULL, WS_CHILD | WS_VISIBLE,
		CFrameWnd::rectDefault, this, VIEWID_LIST, pContext);

	m_pwndScrollView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE,
		CFrameWnd::rectDefault, this, VIEWID_SCRL, pContext);

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}


void CMainFrame::SwitchView(int nId)
{
	// TODO: Add your implementation code here.
	CView* pOldView = GetActiveView();
	CView* pNewView = NULL;

	switch (nId)
	{
	case VIEWID_HTML:
		pNewView = (CView*)m_pwndHtmlView;
		break;
	case VIEWID_EDIT:
		pNewView = (CView*)m_pwndEditView;
		break;
	case VIEWID_LIST:
		pNewView = (CView*)m_pwndListViewForMenu;
		break;
	case VIEWID_SCRL:
		pNewView = (CView*)m_pwndScrollView;
		break;
	default:
		break;
	}

	if (pNewView) {
		if (pOldView == pNewView) return;

		pOldView->ShowWindow(SW_HIDE);
		pOldView->SetDlgCtrlID(nId);

		pNewView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
		pNewView->ShowWindow(SW_SHOW);

		SetActiveView(pNewView);
		RecalcLayout();
	}
}


void CMainFrame::OnHelpEditview()
{
	// TODO: Add your command handler code here
	SwitchView(VIEWID_EDIT);
}


void CMainFrame::OnHelpHtmlview()
{
	// TODO: Add your command handler code here
	SwitchView(VIEWID_HTML);
}


void CMainFrame::OnHelpListview()
{
	// TODO: Add your command handler code here
	SwitchView(VIEWID_LIST);
}


void CMainFrame::OnHelpScrlview()
{
	// TODO: Add your command handler code here
	SwitchView(VIEWID_SCRL);
}
