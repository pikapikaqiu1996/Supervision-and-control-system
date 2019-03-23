#if !defined(AFX_CABLEINFODLG_H__04C0302C_970D_435D_9DB1_D1233C0B63FD__INCLUDED_)
#define AFX_CABLEINFODLG_H__04C0302C_970D_435D_9DB1_D1233C0B63FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CableInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCableInfoDlg dialog
#include "CableInfoTable.h"

class CCableInfoDlg : public CDialog
{
// Construction
public:
	CCableInfoDlg(CWnd* pParent = NULL);   // standard constructor
    int m_nflag;
    CCableInfoTable* m_pSet;

// Dialog Data
	//{{AFX_DATA(CCableInfoDlg)
	enum { IDD = IDD_CABLEINFO };
	BYTE	m_cablenum;
	int		m_fenjinum;
	CString	m_startaddr;
	CString	m_endaddr;
	CString	m_strstate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCableInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCableInfoDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CABLEINFODLG_H__04C0302C_970D_435D_9DB1_D1233C0B63FD__INCLUDED_)
