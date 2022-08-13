#pragma once

#define IMAGES_CNT 7
#define CMYLISTVIEW 26003
#define IDC_LIST1 26000

// CMyListView

class CMyListView : public CListCtrl
{
	DECLARE_DYNAMIC(CMyListView)

public:
	CMyListView();
	virtual ~CMyListView();

	CImageList m_ImageListForNormal;
	CImageList m_ImageListForSmall;
	CListCtrl m_List;
	BOOL m_bAscending;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLvnEndlabeleditList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHdnItemclickList(NMHDR* pNMHDR, LRESULT* pResult);

	void UpdateArrow();
	static int CALLBACK CompareItem(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

};


