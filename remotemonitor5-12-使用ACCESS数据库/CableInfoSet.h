#if !defined(AFX_CABLEINFOSET_H__AF2B6837_BF4A_4421_B81B_77F6CA3FE0FA__INCLUDED_)
#define AFX_CABLEINFOSET_H__AF2B6837_BF4A_4421_B81B_77F6CA3FE0FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CableInfoSet.h : header file
//
#include "CableInfoTable.h"
/////////////////////////////////////////////////////////////////////////////
// CCableInfoSet dialog

class CCableInfoSet : public CDialog
{
// Construction
public:
	CCableInfoSet(CWnd* pParent = NULL);   // standard constructor
	int m_flag;//¼Ó
    CCableInfoTable* m_pSet;
    int m_cablenum;
// Dialog Data
	//{{AFX_DATA(CCableInfoSet)
	enum { IDD = IDD_CABLEINFOSET };
	CComboBox	m_comboctl;
	int		m_fenjinum;
	CString	m_startaddr;
	CString	m_endaddr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCableInfoSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCableInfoSet)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CABLEINFOSET_H__AF2B6837_BF4A_4421_B81B_77F6CA3FE0FA__INCLUDED_)
