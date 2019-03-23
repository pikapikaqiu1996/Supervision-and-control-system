#if !defined(AFX_DUTYRECORDDLG_H__1119526A_383C_4CDF_A41C_F9862BA150CE__INCLUDED_)
#define AFX_DUTYRECORDDLG_H__1119526A_383C_4CDF_A41C_F9862BA150CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DutyRecordDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDutyRecordDlg dialog

class CDutyRecordDlg : public CDialog
{
// Construction
public:
	CDutyRecordDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDutyRecordDlg)
	enum { IDD = IDD_DUTYRECORD };
	CString	m_dutyrecord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDutyRecordDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDutyRecordDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUTYRECORDDLG_H__1119526A_383C_4CDF_A41C_F9862BA150CE__INCLUDED_)
