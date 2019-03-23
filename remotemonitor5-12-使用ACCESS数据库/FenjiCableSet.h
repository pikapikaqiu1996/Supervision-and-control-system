#if !defined(AFX_FENJICABLESET_H__C725FB23_D4E3_4217_8EC2_679D8A75B78B__INCLUDED_)
#define AFX_FENJICABLESET_H__C725FB23_D4E3_4217_8EC2_679D8A75B78B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FenjiCableSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFenjiCableSet dialog
#include "FenjiTable.h"
#include "CableInfoTable.h"
class CFenjiCableSet : public CDialog
{
// Construction
public:
	CFenjiCableSet(CWnd* pParent = NULL);   // standard constructor
    CFenjiTable m_table1;
	CCableInfoTable m_table2;
	void InSertList1();
	void InSertList2();
// Dialog Data
	//{{AFX_DATA(CFenjiCableSet)
	enum { IDD = IDD_FENJICABLESET };
	CButton	m_delete2;
	CButton	m_delete1;
	CButton	m_change2;
	CButton	m_change1;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenjiCableSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFenjiCableSet)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnAdd1();
	afx_msg void OnChange1();
	afx_msg void OnDelete1();
	afx_msg void OnAdd2();
	afx_msg void OnChange2();
	afx_msg void OnDelete2();
	afx_msg void OnClickCablelist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickFenjilist(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FENJICABLESET_H__C725FB23_D4E3_4217_8EC2_679D8A75B78B__INCLUDED_)
