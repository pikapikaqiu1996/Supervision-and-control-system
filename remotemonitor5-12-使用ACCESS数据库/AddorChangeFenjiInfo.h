#if !defined(AFX_ADDORCHANGEFENJIINFO_H__0F1BC8D4_3CF7_4C84_A3F1_B39D58462770__INCLUDED_)
#define AFX_ADDORCHANGEFENJIINFO_H__0F1BC8D4_3CF7_4C84_A3F1_B39D58462770__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddorChangeFenjiInfo.h : header file
//
#include "FenjiTable.h"

/////////////////////////////////////////////////////////////////////////////
// CAddorChangeFenjiInfo dialog

class CAddorChangeFenjiInfo : public CDialog
{
// Construction
public:
	CAddorChangeFenjiInfo(CWnd* pParent = NULL);   // standard constructor
	int m_flag;
    CFenjiTable* m_pSet;

    int m_nuserCount;
	int m_nmainteCount;
	CString m_username[6];
	CString  m_usertel[6];
	CString m_maintename[6];
	CString m_maintetel[6];

// Dialog Data
	//{{AFX_DATA(CAddorChangeFenjiInfo)
	enum { IDD = IDD_ADDFENJIINFO };
	CButton	m_delete2;
	CButton	m_delete1;
	CButton	m_change2;
	CButton	m_change1;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	int		m_fenjinum;
	CString	m_fenjitel;
	CString	m_fenjiname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddorChangeFenjiInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddorChangeFenjiInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd1();
	afx_msg void OnChange1();
	afx_msg void OnDelete1();
	afx_msg void OnAdd2();
	afx_msg void OnChange2();
	afx_msg void OnDelete2();
	afx_msg void OnClickUserinfolist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickMaintenancelist(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDORCHANGEFENJIINFO_H__0F1BC8D4_3CF7_4C84_A3F1_B39D58462770__INCLUDED_)
