#if !defined(AFX_LOGINDLG_H__1C6FDC0D_7877_44C7_8D48_FEEA625C7C2C__INCLUDED_)
#define AFX_LOGINDLG_H__1C6FDC0D_7877_44C7_8D48_FEEA625C7C2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Logindlg.h : header file
//
#include "StaffTable.h"

/////////////////////////////////////////////////////////////////////////////
// CLogindlg dialog

class CLogindlg : public CDialog
{
// Construction
public:
	BOOL m_bAccess;
	CLogindlg(CWnd* pParent = NULL);   // standard constructor
    CStaffTable m_stafftable;

// Dialog Data
	//{{AFX_DATA(CLogindlg)
	enum { IDD = IDD_LOGIN };
	CComboBox	m_usernamectl;
	CComboBox	m_baudratectl;
	CComboBox	m_portctl;
	CString	m_strPassword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogindlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogindlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__1C6FDC0D_7877_44C7_8D48_FEEA625C7C2C__INCLUDED_)
