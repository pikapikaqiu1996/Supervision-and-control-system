#if !defined(AFX_COMBOCOLORPICKER_H__E32ACF1B_4A06_4F7A_91C7_94A5CD0C0CD8__INCLUDED_)
#define AFX_COMBOCOLORPICKER_H__E32ACF1B_4A06_4F7A_91C7_94A5CD0C0CD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComboColorPicker.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComboColorPicker window

class CComboColorPicker : public CComboBox
{
// Construction
public:
	CComboColorPicker();

// Attributes
public:

// Operations
public:
   COLORREF GetSelectedColor();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboColorPicker)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitializeData();
	virtual ~CComboColorPicker();

	// Generated message map functions
protected:
	//{{AFX_MSG(CComboColorPicker)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	//}}AFX_MSG
private:
	BOOL m_bInitialized;
	static COLORREF m_rgStandardColors[];

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOCOLORPICKER_H__E32ACF1B_4A06_4F7A_91C7_94A5CD0C0CD8__INCLUDED_)
