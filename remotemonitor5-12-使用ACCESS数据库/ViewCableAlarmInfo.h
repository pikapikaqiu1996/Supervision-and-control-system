#if !defined(AFX_VIEWCABLEALARMINFO_H__C9704E1F_7160_4040_8BDA_2143DCF8F9F9__INCLUDED_)
#define AFX_VIEWCABLEALARMINFO_H__C9704E1F_7160_4040_8BDA_2143DCF8F9F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewCableAlarmInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CViewCableAlarmInfo dialog
#include "CableAlarmTable.h"
class CViewCableAlarmInfo : public CDialog
{
// Construction
public:
	CViewCableAlarmInfo(CWnd* pParent = NULL);   // standard constructor
	CCableAlarmTable m_table;
    WINDOWPLACEMENT m_mystaticwnd;
    WINDOWPLACEMENT m_editwnd[3];
    WINDOWPLACEMENT m_combownd;
	void Insertlist1();
   int m_perCharHeight;
   int m_perlineHeight;
   int m_paperHeight;
   int m_paperWidth;
   int m_linesPerPage;
   int m_nStartRecord;
   int m_nEndRecord;
   BOOL bHasExcelDriver();

   void Print(CDC* pDC, CPrintInfo* pInfo);
   void DrawGrid(CDC* pDC,int nStartY,int nLine);
   void DrawTexttoGrid(CDC* pDC,int nStartY,int nStartRecord,int nEndRecord);

// Dialog Data
	//{{AFX_DATA(CViewCableAlarmInfo)
	enum { IDD = IDD_VIEWCABLEALARMINFO };
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	CListCtrl	m_list1;
	CString	m_edit1;
	CString	m_edit2;
	int		m_edit3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewCableAlarmInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CViewCableAlarmInfo)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnExport3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWCABLEALARMINFO_H__C9704E1F_7160_4040_8BDA_2143DCF8F9F9__INCLUDED_)
