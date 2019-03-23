#if !defined(AFX_SETCENTERTELDLG_H__F31CED11_BFA4_449F_B16F_6952FC2C76E2__INCLUDED_)
#define AFX_SETCENTERTELDLG_H__F31CED11_BFA4_449F_B16F_6952FC2C76E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetCenterTeldlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetCenterTeldlg dialog
#include "CenterTelTable.h"
class CSetCenterTeldlg : public CDialog
{
// Construction
public:
	CSetCenterTeldlg(CWnd* pParent = NULL);   // standard constructor
    CCenterTelTable table;
// Dialog Data
	//{{AFX_DATA(CSetCenterTeldlg)
	enum { IDD = IDD_SETCENTERTELDLG };
	CString	m_tel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetCenterTeldlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetCenterTeldlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCENTERTELDLG_H__F31CED11_BFA4_449F_B16F_6952FC2C76E2__INCLUDED_)
