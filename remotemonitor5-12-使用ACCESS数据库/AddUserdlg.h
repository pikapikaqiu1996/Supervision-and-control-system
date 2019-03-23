#if !defined(AFX_ADDUSERDLG_H__DFA0C918_8584_448F_AB44_53AA31DD15FD__INCLUDED_)
#define AFX_ADDUSERDLG_H__DFA0C918_8584_448F_AB44_53AA31DD15FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddUserdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddUserdlg dialog
#include "StaffTable.h"
class CAddUserdlg : public CDialog
{
// Construction
public:
	CAddUserdlg(CWnd* pParent = NULL);   // standard constructor
    int m_flag;
	CStaffTable* m_pSet;
// Dialog Data
	//{{AFX_DATA(CAddUserdlg)
	enum { IDD = IDD_ADDUSERDLG };
	CString	m_name;
	CString	m_pwd;
	CString	m_duty;
	CString	m_tel;
	CString	m_department;
	CString	m_address;
	BOOL	m_righta;
	BOOL	m_rightb;
	BOOL	m_rightc;
	BOOL	m_rightd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddUserdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddUserdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDUSERDLG_H__DFA0C918_8584_448F_AB44_53AA31DD15FD__INCLUDED_)
