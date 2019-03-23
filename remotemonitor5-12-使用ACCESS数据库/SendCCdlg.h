#if !defined(AFX_SENDCCDLG_H__556A3E7B_8091_4C4F_BFCF_6724D26EA3CF__INCLUDED_)
#define AFX_SENDCCDLG_H__556A3E7B_8091_4C4F_BFCF_6724D26EA3CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendCCdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendCCdlg dialog

class CSendCCdlg : public CDialog
{
// Construction
public:
	CSendCCdlg(CWnd* pParent = NULL);   // standard constructor
 //   CString m_strTelephone;
	CString m_strInfo;
    void DisplaySomeWnd();
// Dialog Data
	//{{AFX_DATA(CSendCCdlg)
	enum { IDD = IDD_SENDCCDLG };
	CSpinButtonCtrl	m_spin7;
	CSpinButtonCtrl	m_spin4;
	CSpinButtonCtrl	m_spin3;
	CSpinButtonCtrl	m_spin2;
	CSpinButtonCtrl	m_spin1;
	CComboBox	m_combo6;
	int		m_radio1;
	int		m_fenjinumber;
	BOOL	m_bprobe;
	int		m_edit1;
	int		m_edit2;
	int		m_edit3;
	int		m_edit4;
	float	m_edit5;
	int		m_edit7;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendCCdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendCCdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnProbe();
	afx_msg void OnRadio1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDCCDLG_H__556A3E7B_8091_4C4F_BFCF_6724D26EA3CF__INCLUDED_)
