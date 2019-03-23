#if !defined(AFX_FENJINUMDLG_H__5307425E_B0F3_4790_804D_6BA65C746D51__INCLUDED_)
#define AFX_FENJINUMDLG_H__5307425E_B0F3_4790_804D_6BA65C746D51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FenjiNumDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFenjiNumDlg dialog
//#include "Draw.h"
class CDrawObject;
class CFenjiNumDlg : public CDialog
{
// Construction
public:
	CFenjiNumDlg(CDrawObject* usrCurrentObject,CWnd* pParent = NULL);   // standard constructor
 //   int m_NodeNum;
	CDrawObject* m_pusrCurrentObject;
// Dialog Data
	//{{AFX_DATA(CFenjiNumDlg)
	enum { IDD = IDD_FENJINUM };
	CEdit	m_numeditctl;
	CButton	m_changenumctl;
	int		m_numedit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenjiNumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFenjiNumDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnChangefenjinum();
	afx_msg void OnDisplayfenjiinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FENJINUMDLG_H__5307425E_B0F3_4790_804D_6BA65C746D51__INCLUDED_)
