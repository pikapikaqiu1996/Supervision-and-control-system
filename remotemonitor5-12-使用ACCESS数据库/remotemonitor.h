// remotemonitor.h : main header file for the REMOTEMONITOR application
//

#if !defined(AFX_REMOTEMONITOR_H__1BCFFF20_7B73_4EC4_839E_C53B4867BD4D__INCLUDED_)
#define AFX_REMOTEMONITOR_H__1BCFFF20_7B73_4EC4_839E_C53B4867BD4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRemotemonitorApp:
// See remotemonitor.cpp for the implementation of this class
//

class CRemotemonitorApp : public CWinApp
{
public:
	CRemotemonitorApp();
    CString ReadTitleFromIni();
    CString ReadDatabase();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRemotemonitorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRemotemonitorApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REMOTEMONITOR_H__1BCFFF20_7B73_4EC4_839E_C53B4867BD4D__INCLUDED_)
