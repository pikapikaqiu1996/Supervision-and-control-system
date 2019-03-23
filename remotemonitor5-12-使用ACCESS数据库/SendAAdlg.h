#if !defined(AFX_SENDAADLG_H__0B6FD3E1_80D7_45D1_BC21_BD579656F78E__INCLUDED_)
#define AFX_SENDAADLG_H__0B6FD3E1_80D7_45D1_BC21_BD579656F78E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendAAdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendAAdlg dialog

class CSendAAdlg : public CDialog
{
// Construction
public:
	CSendAAdlg(CWnd* pParent = NULL);   // standard constructor
    CString m_strInfo;
// Dialog Data
	//{{AFX_DATA(CSendAAdlg)
	enum { IDD = IDD_SENDAADLG };
	CListCtrl	m_list1;
	int		m_fenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendAAdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendAAdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDAADLG_H__0B6FD3E1_80D7_45D1_BC21_BD579656F78E__INCLUDED_)
