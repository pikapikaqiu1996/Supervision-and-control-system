#if !defined(AFX_SENDCDDLG_H__B7A3A925_4628_4D92_99D0_0508CFDDF722__INCLUDED_)
#define AFX_SENDCDDLG_H__B7A3A925_4628_4D92_99D0_0508CFDDF722__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendCDdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendCDdlg dialog

class CSendCDdlg : public CDialog
{
// Construction
public:
	CSendCDdlg(CWnd* pParent = NULL);   // standard constructor
	CString m_strInfo;

// Dialog Data
	//{{AFX_DATA(CSendCDdlg)
	enum { IDD = IDD_SENDCDDLG };
	CComboBox	m_combo1;
	CString	m_gbk;
	int		m_fenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendCDdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendCDdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDCDDLG_H__B7A3A925_4628_4D92_99D0_0508CFDDF722__INCLUDED_)
