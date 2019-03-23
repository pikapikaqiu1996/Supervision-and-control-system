#if !defined(AFX_ADDCABLECONFIG_H__30933AA6_CA1A_4513_A973_7E9C02352977__INCLUDED_)
#define AFX_ADDCABLECONFIG_H__30933AA6_CA1A_4513_A973_7E9C02352977__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddCableConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddCableConfig dialog

class CAddCableConfig : public CDialog
{
// Construction
public:
	CAddCableConfig(CWnd* pParent = NULL);   // standard constructor
    int m_cable;
	int m_type;
	int m_nTotalItem;
	int m_nArray[16];
	BOOL Serch(int i);

// Dialog Data
	//{{AFX_DATA(CAddCableConfig)
	enum { IDD = IDD_ADDCABLECONFIG };
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddCableConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddCableConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCABLECONFIG_H__30933AA6_CA1A_4513_A973_7E9C02352977__INCLUDED_)
