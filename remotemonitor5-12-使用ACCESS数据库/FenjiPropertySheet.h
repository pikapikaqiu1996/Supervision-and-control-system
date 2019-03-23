// FenjiPropertySheet.h : header file
//
// This class defines custom modal property sheet 
// CFenjiPropertySheet.
 
#ifndef __FENJIPROPERTYSHEET_H__
#define __FENJIPROPERTYSHEET_H__

#include "FenjiInfoPage.h"

/////////////////////////////////////////////////////////////////////////////
// CFenjiPropertySheet

class CFenjiPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CFenjiPropertySheet)

// Construction
public:
	CFenjiPropertySheet(int nflag,CFenjiTable* pSet,int fenjinum,LPCTSTR pszCaption,CWnd* pWndParent = NULL);
   // int m_fengjinum;
// Attributes
public:
	CFenjiInfoPage m_Page1;
	CFenjiParaPage m_Page2;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenjiPropertySheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFenjiPropertySheet();

// Generated message map functions
protected:
	//{{AFX_MSG(CFenjiPropertySheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __FENJIPROPERTYSHEET_H__
