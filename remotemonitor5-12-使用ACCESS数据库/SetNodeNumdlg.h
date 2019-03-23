#if !defined(AFX_SETNODENUMDLG_H__EF033B11_25F6_48EF_848D_5D2BA358DBAB__INCLUDED_)
#define AFX_SETNODENUMDLG_H__EF033B11_25F6_48EF_848D_5D2BA358DBAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetNodeNumdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetNodeNumdlg dialog

class CSetNodeNumdlg : public CDialog
{
// Construction
public:
	CSetNodeNumdlg(CWnd* pParent = NULL);   // standard constructor
    int m_NodeNum;
// Dialog Data
	//{{AFX_DATA(CSetNodeNumdlg)
	enum { IDD = IDD_SETNODENUM };
	CStatic	m_cablestaticctl;
	CComboBox	m_cablenumctl;
	int		m_fengjinum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetNodeNumdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetNodeNumdlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETNODENUMDLG_H__EF033B11_25F6_48EF_848D_5D2BA358DBAB__INCLUDED_)
