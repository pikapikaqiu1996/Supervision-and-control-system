// FenjiInfoPage.h : header file
//

#ifndef __FENJIINFOPAGE_H__
#define __FENJIINFOPAGE_H__
#include "FenjiTable.h"
/////////////////////////////////////////////////////////////////////////////
// CFenjiInfoPage dialog

class CFenjiInfoPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CFenjiInfoPage)

// Construction
public:
	CFenjiInfoPage();
	~CFenjiInfoPage();
	int m_nflag;
    CFenjiTable* m_pSet;
    int m_nuserCount;
	int m_nmainteCount;
	CString m_username[6];
	CString  m_usertel[6];
	CString m_maintename[6];
	CString m_maintetel[6];
// Dialog Data
	//{{AFX_DATA(CFenjiInfoPage)
	enum { IDD = IDD_FENJIINFO };
	CButton	m_delete2;
	CButton	m_delete1;
	CButton	m_change2;
	CButton	m_change1;
	CButton	m_add2;
	CButton	m_add1;
	CListCtrl	m_list2;
	CListCtrl	m_list1;
	int		m_fenjinum;
	CString	m_fenjitel;
	CString	m_fenjiname;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFenjiInfoPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFenjiInfoPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickUserinfolist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickMaintenancelist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd1();
	afx_msg void OnAdd2();
	afx_msg void OnChange1();
	afx_msg void OnChange2();
	afx_msg void OnDelete1();
	afx_msg void OnDelete2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CFenjiParaPage dialog

class CFenjiParaPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CFenjiParaPage)
// Construction
public:
	CFenjiParaPage();
	~CFenjiParaPage();
	int m_nflag;
//    int m_fenjinum;
    CFenjiTable* m_pSet;
// Dialog Data
	//{{AFX_DATA(CFenjiParaPage)
	enum { IDD = IDD_FENJIPARA };
	BYTE	m_edit1;
	BYTE	m_edit2;
	BYTE	m_edit3;
	BYTE	m_edit4;
	float	m_edit5;
	CString	m_edit6;
	BYTE	m_edit7;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFenjiParaPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFenjiParaPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



#endif // __FENJIINFOPAGE_H__
