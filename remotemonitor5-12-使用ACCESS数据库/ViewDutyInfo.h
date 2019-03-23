#if !defined(AFX_VIEWDUTYINFO_H__BFA66501_9A96_4892_AF03_2D900D318F06__INCLUDED_)
#define AFX_VIEWDUTYINFO_H__BFA66501_9A96_4892_AF03_2D900D318F06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ViewDutyInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CViewDutyInfo dialog
#include "DutyTable.h"
class CViewDutyInfo : public CDialog
{
// Construction
public:
	CViewDutyInfo(CWnd* pParent = NULL);   // standard constructor
	CDutyTable m_table;
    WINDOWPLACEMENT m_mystaticwnd;
    WINDOWPLACEMENT m_edit2wnd;

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
	//{{AFX_DATA(CViewDutyInfo)
	enum { IDD = IDD_DUTYRECORDDLG };
	CListCtrl	m_list1;
	CComboBox	m_modectl;
	CString	m_edit1;
	CString	m_edit2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewDutyInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CViewDutyInfo)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeModecombo();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnExport4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWDUTYINFO_H__BFA66501_9A96_4892_AF03_2D900D318F06__INCLUDED_)
