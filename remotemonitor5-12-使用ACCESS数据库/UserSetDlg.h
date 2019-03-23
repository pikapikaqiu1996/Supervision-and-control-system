#if !defined(AFX_USERSETDLG_H__ACACF20B_FB58_4D1A_98A0_5CFF2F5DE011__INCLUDED_)
#define AFX_USERSETDLG_H__ACACF20B_FB58_4D1A_98A0_5CFF2F5DE011__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserSetDlg.h : header file
//
#include "StaffTable.h"
/////////////////////////////////////////////////////////////////////////////
// CUserSetDlg dialog

class CUserSetDlg : public CDialog
{
// Construction
public:
	CUserSetDlg(CWnd* pParent = NULL);   // standard constructor
    CStaffTable m_table;
	void InSertList1();
// Dialog Data
	//{{AFX_DATA(CUserSetDlg)
	enum { IDD = IDD_USERSET };
	CButton	m_delete;
	CButton	m_change;
	CListCtrl	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserSetDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnChange();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSETDLG_H__ACACF20B_FB58_4D1A_98A0_5CFF2F5DE011__INCLUDED_)
