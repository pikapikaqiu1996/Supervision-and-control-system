#if !defined(AFX_ADDORCHANGEUSERDLG_H__0C4052C2_8EC7_4ED7_B3B0_ED3364BB4C73__INCLUDED_)
#define AFX_ADDORCHANGEUSERDLG_H__0C4052C2_8EC7_4ED7_B3B0_ED3364BB4C73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddorChangeUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeUserDlg dialog

class CAddorChangeUserDlg : public CDialog
{
// Construction
public:
	CAddorChangeUserDlg(CWnd* pParent = NULL);   // standard constructor
    int m_nflag;
// Dialog Data
	//{{AFX_DATA(CAddorChangeUserDlg)
	enum { IDD = IDD_ADDORCHANGEUSER };
	CString	m_username;
	CString	m_usertel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddorChangeUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddorChangeUserDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDORCHANGEUSERDLG_H__0C4052C2_8EC7_4ED7_B3B0_ED3364BB4C73__INCLUDED_)
