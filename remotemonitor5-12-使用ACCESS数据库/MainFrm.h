// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__61A280BA_F210_4ED9_8294_D3451E9EDF88__INCLUDED_)
#define AFX_MAINFRM_H__61A280BA_F210_4ED9_8294_D3451E9EDF88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scbarg.h"	// Added by ClassView

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
	CStatic m_scalestatic;
	CListCtrl m_wndList;
	CCoolBar m_wndMyBar;
	void   ViewListbar();
    void ChangeTime();
    void ChangeLinkState(int state=0);
    void ShowWindowMax();

	void OnViewShort();
	void OnViewLong();
	BOOL m_bFlag;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDraw();
	afx_msg void OnUpdateDraw(CCmdUI* pCmdUI);
	afx_msg void OnViewListbar();
	afx_msg void OnUpdateViewListbar(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__61A280BA_F210_4ED9_8294_D3451E9EDF88__INCLUDED_)
