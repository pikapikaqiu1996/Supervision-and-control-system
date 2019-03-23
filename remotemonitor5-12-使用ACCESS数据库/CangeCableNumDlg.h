#if !defined(AFX_CANGECABLENUMDLG_H__27B4B5F6_FA29_4C49_A19D_34D10C9EC9C0__INCLUDED_)
#define AFX_CANGECABLENUMDLG_H__27B4B5F6_FA29_4C49_A19D_34D10C9EC9C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CangeCableNumDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCangeCableNumDlg dialog

class CCangeCableNumDlg : public CDialog
{
// Construction
public:
	CCangeCableNumDlg(CWnd* pParent = NULL);   // standard constructor
    BYTE m_newcablenum;
// Dialog Data
	//{{AFX_DATA(CCangeCableNumDlg)
	enum { IDD = IDD_CHANGECABLENUM };
	CComboBox	m_cablecomboctl;
	int		m_newfenjinum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCangeCableNumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCangeCableNumDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CANGECABLENUMDLG_H__27B4B5F6_FA29_4C49_A19D_34D10C9EC9C0__INCLUDED_)
