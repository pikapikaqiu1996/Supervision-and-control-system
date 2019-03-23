#if !defined(AFX_CABLENUMDLG_H__CF65BB89_BB58_471D_9841_53C952D95D48__INCLUDED_)
#define AFX_CABLENUMDLG_H__CF65BB89_BB58_471D_9841_53C952D95D48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CableNumDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCableNumDlg dialog
class CDrawObject;
class CCableNumDlg : public CDialog
{
// Construction
public:
	CCableNumDlg(CDrawObject* usrCurrentObject,CWnd* pParent = NULL);   // standard constructor
	CDrawObject* m_pusrCurrentObject;

// Dialog Data
	//{{AFX_DATA(CCableNumDlg)
	enum { IDD = IDD_CABLENUM };
	BYTE	m_cablenumber;
	int		m_fenjinumber;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCableNumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCableNumDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnChangecablenum();
	afx_msg void OnDisplaycableinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CABLENUMDLG_H__CF65BB89_BB58_471D_9841_53C952D95D48__INCLUDED_)
