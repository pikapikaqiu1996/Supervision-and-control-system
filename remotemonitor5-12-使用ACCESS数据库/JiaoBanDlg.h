#if !defined(AFX_JIAOBANDLG_H__FA5004FE_0940_4F6E_BB88_8042F5DEF45D__INCLUDED_)
#define AFX_JIAOBANDLG_H__FA5004FE_0940_4F6E_BB88_8042F5DEF45D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JiaoBanDlg.h : header file
//
#include "StaffTable.h"

/////////////////////////////////////////////////////////////////////////////
// CJiaoBanDlg dialog

class CJiaoBanDlg : public CDialog
{
// Construction
public:
	CJiaoBanDlg(CWnd* pParent = NULL);   // standard constructor
    CStaffTable m_stafftable;

// Dialog Data
	//{{AFX_DATA(CJiaoBanDlg)
	enum { IDD = IDD_JIAOBAN };
	CComboBox	m_combo1ctl;
	CString	m_password1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiaoBanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJiaoBanDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIAOBANDLG_H__FA5004FE_0940_4F6E_BB88_8042F5DEF45D__INCLUDED_)
