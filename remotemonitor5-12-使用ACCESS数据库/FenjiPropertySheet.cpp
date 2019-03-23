// FenjiPropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "FenjiPropertySheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFenjiPropertySheet

IMPLEMENT_DYNAMIC(CFenjiPropertySheet, CPropertySheet)

CFenjiPropertySheet::CFenjiPropertySheet(int nflag,CFenjiTable* pSet,int fenjinum,LPCTSTR pszCaption,CWnd* pWndParent)
	 : CPropertySheet(pszCaption, pWndParent)
{
	// Add all of the property pages here.  Note that
	// the order that they appear in here will be
	// the order they appear in on screen.  By default,
	// the first page of the set is the active one.
	// One way to make a different property page the 
	// active one is to call SetActivePage().
    m_psh.dwFlags|=PSH_NOAPPLYNOW;//jht add
	AddPage(&m_Page1);
	AddPage(&m_Page2);
    m_Page1.m_nflag=nflag;
    m_Page2.m_nflag=nflag;
	m_Page1.m_fenjinum=fenjinum;
//	m_Page2.m_fenjinum=fenjinum;
    m_Page1.m_pSet=pSet;
    m_Page2.m_pSet=pSet;
}

CFenjiPropertySheet::~CFenjiPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CFenjiPropertySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CFenjiPropertySheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFenjiPropertySheet message handlers


