#if !defined(AFX_VIEWFENJICABLEINFO_H__727E19DD_8A4C_4B0F_BA65_DE8F6235DE52__INCLUDED_)
#define AFX_VIEWFENJICABLEINFO_H__727E19DD_8A4C_4B0F_BA65_DE8F6235DE52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewFenjiCableInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CViewFenjiCableInfo dialog
#include "FenjiTable.h"
#include "CableInfoTable.h"
class CViewFenjiCableInfo : public CDialog
{
// Construction
public:
	CViewFenjiCableInfo(CWnd* pParent = NULL);   // standard constructor
	CFenjiTable m_table1;
	CCableInfoTable m_table2;
    WINDOWPLACEMENT m_mystaticwnd[4];
    WINDOWPLACEMENT m_editwnd[4];

    void InSertList1();
    void InSertList2();
	BOOL bHasExcelDriver();

// Dialog Data
	//{{AFX_DATA(CViewFenjiCableInfo)
	enum { IDD = IDD_FENJICABLEVIEW };
	CComboBox	m_mode2;
	CComboBox	m_mode1;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	int		m_edit1;
	int		m_edit2;
	int		m_edit3;
	int		m_edit4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewFenjiCableInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CViewFenjiCableInfo)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnProbe1();
	afx_msg void OnProbe2();
	afx_msg void OnSelchangeMode1();
	afx_msg void OnSelchangeMode2();
	afx_msg void OnExport1();
	afx_msg void OnExport2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWFENJICABLEINFO_H__727E19DD_8A4C_4B0F_BA65_DE8F6235DE52__INCLUDED_)
