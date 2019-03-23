#if !defined(AFX_SENDDADLG_H__E4462D19_7449_4F76_8E17_C36657F5F5A5__INCLUDED_)
#define AFX_SENDDADLG_H__E4462D19_7449_4F76_8E17_C36657F5F5A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendDAdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendDAdlg dialog

class CSendDAdlg : public CDialog
{
// Construction
public:
	CSendDAdlg(CWnd* pParent = NULL);   // standard constructor
    CString m_strInfo;
// Dialog Data
	//{{AFX_DATA(CSendDAdlg)
	enum { IDD = IDD_SENDDADLG };
	int		m_fenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendDAdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendDAdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDDADLG_H__E4462D19_7449_4F76_8E17_C36657F5F5A5__INCLUDED_)
