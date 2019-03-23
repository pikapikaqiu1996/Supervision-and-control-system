#if !defined(AFX_CHANGEFENJINUMDLG_H__A384DA31_1006_434B_A132_D606723595F7__INCLUDED_)
#define AFX_CHANGEFENJINUMDLG_H__A384DA31_1006_434B_A132_D606723595F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangeFenjinumdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangeFenjinumdlg dialog

class CChangeFenjinumdlg : public CDialog
{
// Construction
public:
	CChangeFenjinumdlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeFenjinumdlg)
	enum { IDD = IDD_CHANGEFENJINUM };
	int		m_newnum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeFenjinumdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangeFenjinumdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEFENJINUMDLG_H__A384DA31_1006_434B_A132_D606723595F7__INCLUDED_)
