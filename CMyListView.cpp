// CMyListView.cpp : implementation file
//

#include "pch.h"
#include "soroMfcMultiViews.h"
#include "CMyListView.h"


// CMyListView

IMPLEMENT_DYNAMIC(CMyListView, CListCtrl)

CMyListView::CMyListView()
{
	m_ImageListForNormal.Create(48, 48, ILC_COLOR32 | ILC_MASK, IMAGES_CNT, 1);
	m_ImageListForSmall.Create(16, 16, ILC_COLOR32 | ILC_MASK, IMAGES_CNT, 1);
}

CMyListView::~CMyListView()
{
}


BEGIN_MESSAGE_MAP(CMyListView, CListCtrl)
	ON_WM_CREATE()
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST1, &CMyListView::OnLvnEndlabeleditList)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CMyListView::OnHdnItemclickList)
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CMyListView message handlers
void CMyListView::OnLvnEndlabeleditList(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: Add your control notification handler code here
	CString ls_str = _T("");
	//m_List = new CListCtrl;
	CEdit* pEdit = m_List.GetEditControl();
	pEdit->GetWindowTextW(ls_str);

	m_List.SetItemText(pDispInfo->item.iItem, 0, ls_str);

	*pResult = 0;
}

void CMyListView::OnHdnItemclickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	if (phdr->iItem == 0)
	{
		m_bAscending = !m_bAscending;
		UpdateArrow();
		m_List.SortItems(&CMyListView::CompareItem, (DWORD_PTR)this);
	}
	*pResult = 0;
}

int CMyListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CRect cRect;
	GetClientRect(&cRect);

	m_List.Create(WS_CHILD | WS_VISIBLE, cRect, this, IDC_LIST1);
	m_List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 200);
	m_List.InsertColumn(1, _T("Desc"), LVCFMT_LEFT, 300);
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	DWORD dwSeed = ::GetTickCount();
	LVITEM lvItem;
	::ZeroMemory(&lvItem, sizeof(lvItem));
	lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;

	for (int i = 0; i < IMAGES_CNT; i++) {
		m_ImageListForNormal.Add(AfxGetApp()->LoadIconW(IDI_ICON1 + i));
		m_ImageListForSmall.Add(AfxGetApp()->LoadIconW(IDI_ICON1 + i));

		CString ls_str = _T("");
		ls_str.Format(_T("[%d]th Item"), i + 1);

		lvItem.pszText = ls_str.GetBuffer();
		lvItem.iItem = i;
		lvItem.iImage = i;
		lvItem.lParam = dwSeed + i;  // kind of PK among LVITEMs

		//m_List.InsertItem(i, ls_str, i);
		m_List.InsertItem(&lvItem);
		m_List.SetItemText(i, 1, ls_str);
	}

	m_List.SetImageList(&m_ImageListForNormal, LVSIL_NORMAL);
	m_List.SetImageList(&m_ImageListForSmall, LVSIL_SMALL);

	DWORD dwExStyle = m_List.GetExtendedStyle();
	m_List.SetExtendedStyle(dwExStyle |
		LVS_EX_CHECKBOXES |
		LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES |
		LVS_EX_HEADERDRAGDROP);

	m_bAscending = FALSE;

	m_List.SetView(LVS_REPORT);

	return 0;
}


void CMyListView::OnSize(UINT nType, int cx, int cy)
{
	CListCtrl::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_List.MoveWindow(0, 0, cx, cy);
}

void CMyListView::UpdateArrow()
{
	// TODO: Add your implementation code here.
	CHeaderCtrl* pHeaderCtrl = m_List.GetHeaderCtrl();
	HDITEM hdItem;
	TCHAR szBuffer[256];
	::ZeroMemory(&hdItem, sizeof(hdItem));
	::ZeroMemory(szBuffer, 256);

	hdItem.mask = -1;                             // ич
	hdItem.pszText = szBuffer;
	hdItem.cchTextMax = 256;

	pHeaderCtrl->GetItem(0, &hdItem);

	hdItem.fmt &= ~(HDF_SORTDOWN | HDF_SORTUP);   // иш

	if (m_bAscending) hdItem.fmt |= HDF_SORTDOWN; // ищ
	else hdItem.fmt |= HDF_SORTUP;

	pHeaderCtrl->SetItem(0, &hdItem);
}

int CALLBACK CMyListView::CompareItem(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CMyListView* pView = (CMyListView*)lParamSort;

	LVFINDINFO lvFind1, lvFind2;
	lvFind1.flags = LVFI_PARAM;
	lvFind1.lParam = lParam1;

	lvFind2.flags = LVFI_PARAM;
	lvFind2.lParam = lParam2;

	int nIndex1 = (pView->m_List).FindItem(&lvFind1);
	int nIndex2 = (pView->m_List).FindItem(&lvFind2);

	CString strText1 = (pView->m_List).GetItemText(nIndex1, 0);
	CString strText2 = (pView->m_List).GetItemText(nIndex2, 0);

	int nResult = 0;
	if (pView->m_bAscending) nResult = strText2.Compare(strText1);
	else nResult = strText1.Compare(strText2);

	return nResult;
}
