#if !defined(AFX_SENDDCDLG_H__210D4B5C_8A9A_448A_81E6_8C9C60513558__INCLUDED_)
#define AFX_SENDDCDLG_H__210D4B5C_8A9A_448A_81E6_8C9C60513558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendDCDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendDCDlg dialog

class CSendDCDlg : public CDialog
{
// Construction
public:
	CSendDCDlg(CWnd* pParent = NULL);   // standard constructor
    CString m_strInfo;

// Dialog Data
	//{{AFX_DATA(CSendDCDlg)
	enum { IDD = IDD_SENDDCDLG };
	int		m_fenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendDCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendDCDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDDCDLG_H__210D4B5C_8A9A_448A_81E6_8C9C60513558__INCLUDED_)
