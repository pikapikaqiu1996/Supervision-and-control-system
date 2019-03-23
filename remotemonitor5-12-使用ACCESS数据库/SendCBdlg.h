#if !defined(AFX_SENDCBDLG_H__C1030A99_42F8_41CB_A6CF_04D037E5F00A__INCLUDED_)
#define AFX_SENDCBDLG_H__C1030A99_42F8_41CB_A6CF_04D037E5F00A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendCBdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendCBdlg dialog

class CSendCBdlg : public CDialog
{
// Construction
public:
	CSendCBdlg(CWnd* pParent = NULL);   // standard constructor
    CString m_strInfo;
// Dialog Data
	//{{AFX_DATA(CSendCBdlg)
	enum { IDD = IDD_SENDCBDLG };
	int		m_fenjinumber;
	int		m_newfenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendCBdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendCBdlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDCBDLG_H__C1030A99_42F8_41CB_A6CF_04D037E5F00A__INCLUDED_)
