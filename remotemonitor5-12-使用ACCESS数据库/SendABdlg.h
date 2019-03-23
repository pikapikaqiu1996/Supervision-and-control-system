#if !defined(AFX_SENDABDLG_H__717B40F8_0680_4EFA_8DA8_89B0F80CDE18__INCLUDED_)
#define AFX_SENDABDLG_H__717B40F8_0680_4EFA_8DA8_89B0F80CDE18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendABdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendABdlg dialog

class CSendABdlg : public CDialog
{
// Construction
public:
	CSendABdlg(CWnd* pParent = NULL);   // standard constructor
    CString m_strInfo;
	int m_flag;
// Dialog Data
	//{{AFX_DATA(CSendABdlg)
	enum { IDD = IDD_SENDABDLG };
	int		m_fenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendABdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendABdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDABDLG_H__717B40F8_0680_4EFA_8DA8_89B0F80CDE18__INCLUDED_)
