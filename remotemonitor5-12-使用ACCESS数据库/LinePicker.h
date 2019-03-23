#if !defined(AFX_LINEPICKER_H__452E426F_EFB7_4ED9_9B2C_BAD7226DD48C__INCLUDED_)
#define AFX_LINEPICKER_H__452E426F_EFB7_4ED9_9B2C_BAD7226DD48C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LinePicker.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLinePicker window

class CLinePicker : public CComboBox
{
// Construction
public:
	CLinePicker();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinePicker)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLinePicker();
	void InitializeData();
    void SetLineColor(COLORREF nColor);
	int GetSelectedWidth();
	// Generated message map functions
protected:
	//{{AFX_MSG(CLinePicker)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
private:
	BOOL m_bInitialized;
	static DWORD m_lineWidth[];
    COLORREF m_nColor;
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEPICKER_H__452E426F_EFB7_4ED9_9B2C_BAD7226DD48C__INCLUDED_)
